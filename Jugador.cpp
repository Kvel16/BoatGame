#include "Jugador.h"
#include "Personaje.h"
#include <iostream>
#include <vector>
#include <termios.h>//Libreria para funcion getch()
#include <unistd.h>//Libreria para funcion getch()
#include <stdio.h>//Libreria para funcion getch() y gotoxy()
#include <stdlib.h>//Libreria para funcion gotoxy()
#define TECLA_ARRIBA 'w'
#define TECLA_ABAJO 's'
#define ENTER ' '
using namespace std;

/*
Archivo: Jugador.cpp
Autores (Grupo 8): 
  ♦ José Palma <jose.palma@correounivalle.edu.co> - 2125182-3743
  ♦ Isabela Rosero <isabela.rosero@correounivalle.com> - 2128720-3743
  ♦ Santiago Torres <santiago.torres@correounivalle.edu.co> - 2140010-3743
  ♦ Jhon Suescun <suescun.jhon@correounivalle.edu.co> 2124648-3743
  ♦ Kevin Velez <kevin.alejandro.velez@correounivalle.edu.co> - 2123281-3743
Fecha Creación: 2022/02/23
Fecha Última Modificación: 2022/03/19
Licencia: GNU-GPL
*/

//Constructor
Jugador::Jugador(Orilla *izquierda, Orilla *derecha, Barca *laBarca, vector<Personaje*> individuos)
{
  this->laBarca = laBarca;
  this->izquierda = izquierda;
  this->derecha = derecha;
  this->individuos = individuos;
  finJuego = false;
}


//Destructor
Jugador::~Jugador()
{
  delete izquierda;
  delete derecha;
  delete laBarca;
  for(int i=0 ; i < individuos.size() ; i++)
  {
    delete individuos[i];
    individuos[i] = nullptr;
  }
}


void Jugador::gotoxy(int x, int y)
{
  //Codigos de escape ANSI para posicionar el cursor en la terminal
  printf( "\033[%d;%df", y, x );
}


int Jugador::getch()
{
  //Determina la tecla presionada y la guarda en una variable sin mostrarlo en consola
  struct termios oldattr, newattr;
  int ch;
  tcgetattr( STDIN_FILENO, &oldattr );
  newattr = oldattr;
  newattr.c_lflag &= ~( ICANON | ECHO );
  tcsetattr( STDIN_FILENO, TCSANOW, &newattr );
  ch = getchar();
  tcsetattr( STDIN_FILENO, TCSANOW, &oldattr );
  return ch;
}


void Jugador::menuPrincipal()
{
  int opcion;

  //Titulo y opciones del menu
  const char *separador = "----------------------------------------------------------------------";
  const char *titulo = "//***** BIENVENIDO AL JUEGO DE LA BARCA *****//";
  const char *instrucciones = "Utiliza las teclas 'w' y 's' para moverte y 'ESPACIO' como ENTER.";
  const char *opciones[] = {"Barca se mueve a la orilla","El Robot salta","El Zorro salta","El conejo salta","La lechuga salta"};
  int n = 5; //numero de opciones
  
  opcion = menu(separador,titulo, instrucciones, opciones, n);
  system("clear");//limpiar pantalla en cada ejecución
  
  switch(opcion)
  {
    case 1://Barca
      comandoB();
      break;
    case 2://Robot
      moverPersonaje(individuos[3]);
      break;
    case 3://Zorro
      moverPersonaje(individuos[1]);
      break;
    case 4://Conejo
      moverPersonaje(individuos[0]);
      break;
    case 5://Lechuga
      moverPersonaje(individuos[2]);
      break;
  }
}


int Jugador::menu(const char *separador, const char *titulo, const char *instrucciones, const char *opciones[], int n)
{
  int tecla, opcion=1;
  bool repite = true;
  do{
    system("clear");
    string imprimeLugares = mostrarLugares();
    string tableroIndividuos = mostrarIndividuos();
    cout<<imprimeLugares<<endl;
    cout<<tableroIndividuos<<endl;
    gotoxy(0,7);cout << separador;
    gotoxy(9,8);cout << titulo;
    gotoxy(0,9);cout << instrucciones;
    gotoxy(5,10 + opcion);cout << "==>";
    for(int i=0; i<n; i++){
      gotoxy(10,11 + i); cout << i + 1 << ") " << opciones[i];
    }
    cout << "\n\n";
    
    //Funcion identificar tecla presionada por el usuario
    do{
      tecla = getch();
    }while(tecla != TECLA_ARRIBA && tecla != TECLA_ABAJO && tecla != ENTER);

    switch(tecla){
      case TECLA_ARRIBA:
        opcion--;
        if(opcion < 1){
          opcion = n;
        }
        break;

      case TECLA_ABAJO:
        opcion++;
        if(opcion > n){
          opcion = 1;
        }
        break;
      
      case ENTER:
        repite = false;
        break;
      
    }
  }while(repite);
  return opcion;
}


string Jugador::mostrarLugares()
{
  string misLugares;
  if(laBarca->getPos()==1)
    misLugares = "| IZQUIERDA |   BARCA   |           |  DERECHA  |";
  else if (laBarca->getPos()==2)
    misLugares = "| IZQUIERDA |           |   BARCA   |  DERECHA  |";
  return misLugares;
}


string Jugador::mostrarIndividuos()
{
  string tableroIndividuos="";
  for(int i=0; i<individuos.size();i++)
  {
    for(int lugarContador=0; lugarContador<4;lugarContador++)
    {
      if(individuos.at(i)->getPos()==lugarContador)
      {
        tableroIndividuos +="|"+individuos.at(i)->getNombre();
          if(lugarContador == 3)
            tableroIndividuos += "|\n";
          else if(lugarContador == 2)
            tableroIndividuos += "|           |\n";
          else if(lugarContador == 1)
            tableroIndividuos += "|           |           |\n";
          else if(lugarContador == 0)
            tableroIndividuos += "|           |           |           |\n";
          break;
            lugarContador=0;           
      }
      else
        tableroIndividuos += "|           ";
    }
  }
  return tableroIndividuos;
}


void Jugador::comandoB()
{
  //Comando de Barca
  if(laBarca->getRobotEnBarca())
  { 
    laBarca->moverLaBarca();
  }
  else
  { 
    gotoxy(0,0);cout << "NOTIFICACIÓN: NO SE PUEDE MOVER LA BARCA SIN EL ROBOT.\n\n";
    sleep(2);
    system("clear");
  }
}


void Jugador::moverPersonaje(Personaje *personaje)
{
  // Personaje en la orilla izquierda
  if(personaje->getPos() == 0)
  {
    if(laBarca->getPos() == 1 && laBarca->numPasajeros() < 2)
    {
      personaje->avanzar();
      laBarca->cargarPersonaje(personaje);
      izquierda->borrarDelLugar(personaje);
    }
    else if( laBarca->numPasajeros() == 2 && laBarca->getPos()==1)
    {
      gotoxy(0,0);cout << "NOTIFICACIÓN: LA BARCA SOLO PUEDE TRANSPORTAR DOS PERSONAJES.\n\n";
      sleep(2);
      system("clear");
    }
    else
    {
      if(personaje->getId() == 'L')
      {
        cout << "\n-> La" << personaje->getNombre() << "se ha arrojado al agua." << endl;
      }
      else
      {
        cout << "\n-> El" << personaje->getNombre() << "se ha arrojado al agua." << endl;
      }
      setFinJuego(true);
    }
  }
  //Personaje en la orilla derecha
  else if(personaje->getPos() == 3)
  {
    if(laBarca->getPos() == 2 && laBarca->numPasajeros() < 2)
    {
      personaje->retroceder();
      laBarca->cargarPersonaje(personaje);
      derecha->borrarDelLugar(personaje);
    }
    else if( laBarca->numPasajeros() == 2 && laBarca->getPos()==2)
    {
      gotoxy(0,0);cout << "NOTIFICACIÓN: LA BARCA SOLO PUEDE TRANSPORTAR DOS PERSONAJES.\n\n";
      sleep(2);
      system("clear");
    }
    else
    {
      if(personaje->getId() == 'L')
      {
        cout << "\n-> La" << personaje->getNombre() << "se ha arrojado al agua.\n" << endl;
      }
      else
      {
        cout << "\n-> El" << personaje->getNombre() << "se ha arrojado al agua.\n" << endl;
      }
      setFinJuego(true);
    }
  }
  //Evalúa si Robot esta en Barca
  else if (personaje->getPos() == laBarca->getPos())
  {
    if (laBarca->getPos() == 1)
    {
      personaje->retroceder();
      izquierda->cargarPersonaje(personaje);
      laBarca->borrarDelLugar(personaje);
    }
    else
    {
      personaje->avanzar();
      derecha->cargarPersonaje(personaje);
      laBarca->borrarDelLugar(personaje);
    }
  }
}


bool Jugador::getFinJuego()
{
  return finJuego;
}


void Jugador::setFinJuego(bool valor)
{
  finJuego = valor;
}


void Jugador::validarDepredacion()
{
  int posRobot, posZorro, posConejo, posLechuga;
  posRobot = individuos[indicePorId('R')]->getPos(); //Indice robot
  posZorro = individuos[indicePorId('Z')]->getPos();
  posConejo = individuos[indicePorId('C')]->getPos();
  posLechuga = individuos[indicePorId('L')]->getPos();
  //Valida si Zorro se comió al Conejo
  if(((posConejo == 0 && posRobot == 2) || (posConejo == 3 && posRobot == 1)) && posZorro == posConejo) 
  {
    mostrarFinJuego('Z');
    setFinJuego(true);
  }//Valida si Conejo se comió a Lechuga
  else if(((posConejo == 0 && posRobot == 2) || (posConejo == 3 && posRobot == 1)) && posConejo == posLechuga) 
  {
    mostrarFinJuego('C');
    setFinJuego(true);
  }
}


void Jugador::mostrarFinJuego(char id)
{
  cout << "\nFIN DEL JUEGO" << endl;
  if(id == 'Z')
  {
    cout << "\n-> ¡EL ZORRO SE COMIÓ AL CONEJO!" << endl;
  }
  else
  {
    cout <<"\n-> ¡EL CONEJO SE COMIÓ A LA LECHUGA!" <<endl;
  }
}


void Jugador::validarGanar()
{
  int contador = 0;
  while(contador<individuos.size() && individuos[contador]->getPos() == 3)
    ++contador;

  if(contador == 4)
  {
    setFinJuego(true);
    cout << "\n¡FELICITACIONES, HAS GANADO!" << endl;
    cout << "FIN DEL JUEGO" << endl;
  }
}


int Jugador::indicePorId(char id)
{
  int indiceIndividuo;
   for(int i=0 ; i<individuos.size() ; i++)
   {
     if(individuos[i]->getId() == id)
     {
       indiceIndividuo = i;
       break;
     }
   }
  return indiceIndividuo;
}


void Jugador::comenzarJuego()
{
  //Cambia el atributo finJuego
  finJuego = false;
  
  //Borrar todos los personajes de izquierda, derecha y barca
  izquierda->reiniciarLugar();
  derecha->reiniciarLugar();
  laBarca->reiniciarLugar();
  
  //Carga los personajes en la Orillas izquierda. Además, cambia la posición de los personajes a 0
  for(int i=0 ; i < individuos.size() ; i++)
  {
    individuos[i]->setPosicion(0);
    izquierda->cargarPersonaje(individuos[i]);
  }
}


void Jugador::reintentar()
{
  char respuesta;

  do
  {
    cout << "\n¿Quieres Reintentar?" << endl;
    cout << "S: Sí" << endl << "N: No" << endl;
    cout << "Escribe una opción: ";
    cin >> respuesta;
    respuesta = toupper(respuesta);

    if(respuesta != 'S' && respuesta != 'N')
    {
      system("clear"); 
      cout<<"\n-> COMANDO NO VÁLIDO\n"<<endl; 
    }
    
  }while(respuesta != 'S' && respuesta != 'N');
  
  switch (respuesta)
  { 
    case 'S': system("clear"); comenzarJuego() ; break;
    case 'N': cout << "\nGRACIAS POR JUGAR..."; break;
  }

}

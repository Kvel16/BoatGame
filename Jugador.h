#ifndef JUGADOR_H
#define JUGADOR_H
#include "Lugar.h"
#include "Barca.h"
#include "Orilla.h"
#include "Personaje.h"
#include <string>
#include <vector>
#include <iostream>
using namespace std;

/*
Archivo: Jugador.h
Autores (Grupo 8): 
  ♦ José Palma <jose.palma@correounivalle.edu.co> - 2125182-3743.
  ♦ Isabela Rosero <isabela.rosero@correounivalle.com> - 2128720-3743.
  ♦ Santiago Torres <santiago.torres@correounivalle.edu.co> - 2140010-3743.
  ♦ Jhon Suescun <suescun.jhon@correounivalle.edu.co> 2124648-3743.
  ♦ Kevin Velez <kevin.alejandro.velez@correounivalle.edu.co> - 2123281-3743.
Fecha Creación: 2022/02/23
Fecha Última Modificación: 2022/03/19
Licencia: GNU-GPL.
*/

/*
Clase: Jugador.h
Intención: La clase Jugador carga los diferentes lugares en los que se lleva a cabo la acción del juego (orillas izquierda y derecha, río, etc)
Relaciones:
Conoce a Barca, Orilla y Personaje.
*/

using namespace std;

class Jugador {
  
private:
    vector <Personaje*> individuos;
    Barca *laBarca;
    Orilla *izquierda;
    Orilla *derecha;
    bool finJuego;


public:
    //Constructor
    Jugador(Orilla *izquierda, Orilla *derecha, Barca *barca, vector<Personaje*> individuos);

    //Destructor
    virtual ~Jugador();

    //Recibe coordenadas X y Y, coloca char en las coordenadas indicadas. Reemplaza la funcion gotoxy() de la libreria conio.h de windows.
    void gotoxy(int x, int y);

    //Permite leer tecla presionada por parte del jugador. Reemplaza la funcion getch() de la libreria conio.h de windows.
    int getch(void);

    //Muestra el menu del juego
    void menuPrincipal();

    //Retorna la opcion indicada por el jugador
    int menu(const char *separador, const char *titulo, const char *instrucciones, const char *opciones[], int n);

    //Muestra la fila de nombres de los lugares(izquierda, barca y derecha)
    string mostrarLugares();

    //Muesta la matriz de personajes
    string mostrarIndividuos();

    //Realiza el comando para la tecla B (mover barca)
    void comandoB();

    //Mueve cualquier personajes(robot,conejo,zorro y lechuga)
    void moverPersonaje(Personaje *personaje);

    //Retorna el estado del atributo finDelJuego
    bool getFinJuego();

    //Modifica el estado del atributo finDelJuego
    void setFinJuego(bool valor);

    //Detectar cuando un personaje se come a otro. Notifica en pantalla.
    void validarDepredacion();

    //Notifica el fin del juego
    void mostrarFinJuego(char id);

    //Detecta cuando todos los personajes están en la orilla izquierda
    void validarGanar();

    //Retorna el indice del individuo cuando está en un vector.
    int indicePorId(char id);

    //Carga a los personajes en la orilla izquierda al principio del juego.
    void comenzarJuego();

    //Muestra la opción de reintentar después de ganar o perder el juego.
    void reintentar();
};

#endif
#ifndef PERSONAJE_H
#define PERSONAJE_H
#include <string>
#include <iostream>
using namespace std;

/*
Archivo: Personaje.h
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

/*
Clase: Personaje.h
Intención: Clase base que instancia los objetos personaje, contiene un nombre, una letra o caracter que es el id (inicial del nombre), un id del personaje el cual es su presa (por ejemplo para zorro el idPresa seria "C" ya que el zorro se come al conejo) y por ultimo contiene un entero que indica la posicion en el tablero que se mostrara en consola.
Relaciones: Ninguna
*/

class Personaje 
{

private:
  string nombre;
  char id;
  char idPresa;
  int posicion;
   
public:
  //Constructor.
  // Cazador
  Personaje(string nombre, char IdIndividuo, char idPresa);
  // presa
  Personaje(string nombre, char IdIndividuo);

  //Destructor.
  ~Personaje();

  //Retorna el id del personaje.
  char getId();

  //Retorna la posicion del personaje.
  int getPos();

  //Resta 1 a la posicion de personaje, haciendolo retroceder.
  int retroceder();

  //Suma 1 a la posicion de personaje, haciendolo avanzar.
  int avanzar();

  //Retorna el id de la presa. 
  char getIdPresa();

  //Retorna el nombre del personaje
  string getNombre();

  //Cambia la posición del individuo
  void setPosicion(int);
};

#endif
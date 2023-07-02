#ifndef BARCA_H
#define BARCA_H
#include "Lugar.h"
#include <iostream>
using namespace std; 

/*
Archivo: Barca.h
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
Clase: Barca.h
Intención: La clase barca transporta a personajes a través del río.
Relaciones:
Es parecido a Lugar (Hereda los atributos y metodos de Lugar, pero añade algunos nuevos).
Conoce a Personaje. 
*/ 

class Barca: public Lugar
{
protected:
  int posicion;//posicion de la barca
  bool robotEnBarca;

public:
  //Constructor.
  Barca(string lugarNombre);

  //Destructor
  virtual ~Barca();

  //Muestra los pasajeros que estan en barca (muestra la longitud del vector de personajes de barca).
  int numPasajeros();

  //Retorna la posicion del tablero en la cual se encuentra la barca.
  int getPos();

  //Mueve la barca y junto con ella los personajes que estan en ella (almacenados en el vector de barca).
  void moverLaBarca();

  //Nos dice si el robot esta o no en la barca (true: esta en la barca, false: no esta en la barca).
  bool getRobotEnBarca();

  //Cambia el estado "estaRobot" a falso, borra todos lo personajes y cambia la posición a 1
  virtual void reiniciarLugar();

  //Cargar el personaje pasado por parametro a la barca. Además, si el personaje es el robot,cambia el atributo "estaRobot" a verdadero
  virtual void cargarPersonaje(Personaje *);

  //Borra del la barca al personaje dado por parametro. Además, si el personaje es el robot, cambia el atributo "estaRobot" a verdadero
  virtual void borrarDelLugar(Personaje *);


};

#endif

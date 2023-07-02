#ifndef Orilla_H
#define Orilla_H
#include <string>
#include <vector>
#include "Barca.h"
#include "Lugar.h"
#include <iostream>
using namespace std;

/*
Archivo: Orilla.h
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
Clase: Orilla
Intención: Servir como molde para las orillas del programa, en este caso izquierda y derecha 
Relaciones: Es un lugar (Hereda de lugar)
*/

class Orilla : public Lugar
{
public:
  //Constructor
  Orilla(string nombre);
  
  //Destructor
  virtual ~Orilla();

  //Borra todos los personajes del lugar
  virtual void reiniciarLugar();

  //Carga el personaje a la orilla
  virtual void cargarPersonaje(Personaje *);

  //Quita un personaje del lugar
  virtual void borrarDelLugar(Personaje *);
};
#else
class Orilla;
#endif
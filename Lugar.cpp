#include "Personaje.h"
#include "Lugar.h"
#include <iostream>
#include <vector>
using namespace std;

/*
Archivo: Lugar.cpp
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

Lugar::Lugar(string nombre) 
{
  this->nombre = nombre;
}


Lugar::~Lugar()
{

}


void Lugar::mostrarPersonajes()
{
  for(int i=0 ; i < personajes.size() ; i++)
  {
    cout << personajes[i]->getNombre();
  }
}


string Lugar::getNombre()
{
  return nombre;
}


string Lugar::mostrarNombrePersonaje(int fila)
{
  return personajes[fila]->getNombre();
}




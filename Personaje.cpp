#include "Personaje.h"
#include <iostream>
#include <string>
using namespace std;

/*
Archivo: Personaje.cpp
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

Personaje::Personaje(string nombre, char id, char idPresa)
{
  this->nombre = nombre;
  this->id = id;
  this->idPresa = idPresa;
  posicion = 0;
}

Personaje::Personaje(string nombre, char id)
{
  this->nombre = nombre;
  this->id = id;
  posicion = 0;
}

Personaje::~Personaje(){}


string Personaje::getNombre()
{
  string titulo = nombre;
  int distancia = 11 - titulo.length();
  for(int espaciosIzq =0; espaciosIzq< distancia/2; espaciosIzq++)
  {
    titulo = " " + titulo;
  }
  for(int espaciosDer =0; espaciosDer< distancia/2 + distancia%2; espaciosDer++)
  {
    titulo += " ";
  }
  return titulo;
}


char Personaje::getId()
{
  return id;
}


int Personaje::getPos(){
  return posicion;
}


int Personaje::retroceder()
{
  return posicion--;
}


int Personaje::avanzar()
{
  return posicion++;
}


char Personaje::getIdPresa()
{
  return idPresa;
}


void Personaje::setPosicion(int pos)
{
  posicion = pos;
}
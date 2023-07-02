#include "Barca.h"
#include <iostream>
using namespace std; 

/*
Archivo: Barca.cpp
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
Barca::Barca(string nombre): Lugar(nombre){
  posicion = 1;
  robotEnBarca = false;
}

//Destructor
Barca::~Barca()
{
}

//Metodos
int Barca::getPos(){
  return posicion;
}


void Barca::moverLaBarca(){
  if(getPos()==1)
  {
    posicion++;
    for(int i=0 ; i<personajes.size() ; i++)
      personajes[i]->avanzar();
  }
  else
  {
    posicion--;
    for(int i=0 ; i<personajes.size() ; i++)
      personajes[i]->retroceder();
  }
}


bool Barca::getRobotEnBarca()
{
  return robotEnBarca;
}


int Barca::numPasajeros()
{
  return personajes.size();
}


void Barca::reiniciarLugar()
{
  robotEnBarca = false;
  posicion = 1;
  personajes.clear();
}


void Barca::cargarPersonaje(Personaje *personaje)
{
  personajes.push_back(personaje);
  if(personaje->getId() == 'R')
    robotEnBarca = true;
}


void Barca::borrarDelLugar(Personaje *personaje)
{
  int indiceQueSeBorra;
  for(int i=0 ; i < personajes.size() ; i++)
  {
    if(personajes.at(i)->getId()==personaje->getId()){
      indiceQueSeBorra = i;
      personajes.erase(personajes.begin()+indiceQueSeBorra);
    }
  }
  if(personaje->getId() == 'R') robotEnBarca = false;
  
}
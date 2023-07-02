#include "Lugar.h"
#include "Orilla.h"
#include <string>
#include <iostream>
using namespace std;

/*
Archivo: Orilla.cpp
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


Orilla::Orilla(string nombre): Lugar (nombre)
{
  
}

Orilla::~Orilla()
{
}


void Orilla::reiniciarLugar()
{
  personajes.clear();
}

void Orilla::cargarPersonaje(Personaje *personaje)
{
  personajes.push_back(personaje);
}


void Orilla::borrarDelLugar(Personaje *personaje)
{
  int indiceQueSeBorra;
  for(int i=0 ; i < personajes.size() ; i++)
  {
    if(personajes.at(i)->getId()==personaje->getId()){
      indiceQueSeBorra = i;
      personajes.erase(personajes.begin()+indiceQueSeBorra);
    }
  }
}
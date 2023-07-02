#ifndef LUGAR_H
#define LUGAR_H
#include "Personaje.h"
#include <vector>
#include <iostream>
using namespace std;

/*
Archivo: Lugar.h
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
Clase: Lugar.h
Intención: Crear el nombre de la clase (Lugar), y el vector de personajes, ademas de los metodos para almacenar los personajes en el lugar, mostrar sus respectivos nombres y borrarlos al momento de moverlos de un lugar a otro. 
Relaciones:
Conoce a Personaje
*/
class Lugar{
  protected:
    string nombre;
    vector <Personaje*> personajes;
    
  public:
    //Constructor.
    Lugar(string nombre);

    //Destructor.
    virtual ~Lugar();

    //Crea un objeto Personaje y lo introduce en el vector personajes.
    virtual void cargarPersonaje(Personaje *personaje) = 0;

    //Borra todos los personajes en algun lugar
    virtual void reiniciarLugar() = 0;

    //Borra de un lugar un personaje cuando este se mueve a otro.
    virtual void borrarDelLugar(Personaje *) = 0;

    //Retorna el nombre del lugar
    string getNombre();

    //Mostrar nombre Personaje
    string mostrarNombrePersonaje(int fila);

};
#endif
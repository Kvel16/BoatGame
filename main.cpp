#include "Jugador.h"
 #include "Lugar.h"
 #include "Barca.h"
 #include "Orilla.h"
 #include "Personaje.h"
 #include <iostream>
using namespace std;

/*
Archivo: main.cpp
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
Historia: Hay un robot que debe transportar un zorro, un conejo y una lechuga desde un lado del río hasta la otra orilla, usando una barca. En la barca solo cabe uno de los tres individuos, además del robot. El problema es que si el robot deja solos al zorro y al conejo, el zorro se comerá el conejo. Y si deja solos al conejo y la lechuga, el conejo se comerá la lechuga. El jugador debe controlar qué órdenes dar, para lograr que el robot transporte los tres individuos a la otra orilla, sanos y salvos.
*/

int main() 
{
  vector<Personaje *> individuos = 
  {
    new Personaje("Conejo", 'C', 'L'),
    new Personaje("Zorro", 'Z', 'C'),
    new Personaje("Lechuga", 'L'),
    new Personaje("Robot", 'R')
  };

  Jugador jugador(new Orilla("IZQUIERDA"), new Orilla ("DERECHA"), new Barca("BARCA"), individuos);

  jugador.comenzarJuego();
  do
  {
    jugador.menuPrincipal();
    jugador.validarDepredacion();
    jugador.validarGanar();
    
    if(jugador.getFinJuego())
      jugador.reintentar();
        
  }while(!jugador.getFinJuego());
     return 0;
} 
/********************************************************************************
* main.c: Demonstration av unioner för bitfält i C.
********************************************************************************/
#include "header.h"

/* Definition av globala objekt: */
union byte_ptr ddrb, portb, pinb;

/********************************************************************************
* setup: Initierar systemet. Först sätts byte-pekarna till att peka på
*        motsvarande I/O-register. Därefter kan vi ett- och nollställa enskilda
*        bitar med bit-pekaren.
*
*        Lysdioden sätts till utport genom att ettställa motsvarande bit i
*        i datariktningsregister DDRB (Data Direction Register B). Sedan
*        aktiveras den interna pullup-resistorn på tryckknappens pin genom att
*        ettställa motsvarande bit i dataregister PORTB.
********************************************************************************/
static void setup(void)
{
   ddrb.byte = &DDRB;
   portb.byte = &PORTB;
   pinb.byte = &PINB;

   ddrb.bits->bit0 = 1;
   portb.bits->bit5 = 1;
   return;
}

/********************************************************************************
* main: Ansluter en lysdiod till pin 8 (PORTB0) samt en tryckknapp till pin 13
*       (PORTB5). Vid nedtryckning av tryckknappen tänds lysdioden, annars
*       hålls den släckt.
*
*       För att läsa av tryckknappen läser vi av motsvarande bit 5 i registret
*       PINB. Vid nedtryckning är denna bit hög (1).För att tända och släcka
*       lysdioden ett- respektive nollställs motsvarande bit i dataregster
*       PORTB.
********************************************************************************/
int main(void)
{
   setup();

   while (1)
   {
      if (pinb.bits->bit5 == 1)
      {
         portb.bits->bit0 = 1;
      }
      else
      {
         portb.bits->bit0 = 0;
      }
   }

   return 0;
}


/********************************************************************************
* main.c: Demonstration av unioner f�r bitf�lt i C.
********************************************************************************/
#include "header.h"

/* Definition av globala objekt: */
union byte_ptr ddrb, portb, pinb;

/********************************************************************************
* setup: Initierar systemet. F�rst s�tts byte-pekarna till att peka p�
*        motsvarande I/O-register. D�refter kan vi ett- och nollst�lla enskilda
*        bitar med bit-pekaren.
*
*        Lysdioden s�tts till utport genom att ettst�lla motsvarande bit i
*        i datariktningsregister DDRB (Data Direction Register B). Sedan
*        aktiveras den interna pullup-resistorn p� tryckknappens pin genom att
*        ettst�lla motsvarande bit i dataregister PORTB.
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
*       (PORTB5). Vid nedtryckning av tryckknappen t�nds lysdioden, annars
*       h�lls den sl�ckt.
*
*       F�r att l�sa av tryckknappen l�ser vi av motsvarande bit 5 i registret
*       PINB. Vid nedtryckning �r denna bit h�g (1).F�r att t�nda och sl�cka
*       lysdioden ett- respektive nollst�lls motsvarande bit i dataregster
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


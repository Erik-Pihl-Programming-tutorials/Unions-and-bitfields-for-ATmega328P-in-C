/********************************************************************************
* header.h: Inneh�ller diverse deklarationer och definitioner f�r implementering
*           av det inbyggda systemet.
********************************************************************************/
#ifndef HEADER_H_
#define HEADER_H_

/* Inkluderingsdirektiv: */
#include <avr/io.h> /* Inneh�ller information om I/O-register s�som PORTB. */

/********************************************************************************
* bits: Strukt f�r att erh�lla enskilda bitar i en byte (�tta bitar), �ven
*       kallat ett bitf�lt.
********************************************************************************/
struct bits
{
   uint8_t bit0 : 1; /* Bit 0 - minst signifikant bit. */
   uint8_t bit1 : 1; /* Bit 1. */
   uint8_t bit2 : 1; /* Bit 2. */
   uint8_t bit3 : 1; /* Bit 3. */
   uint8_t bit4 : 1; /* Bit 4. */
   uint8_t bit5 : 1; /* Bit 5. */
   uint8_t bit6 : 1; /* Bit 6. */
   uint8_t bit7 : 1; /* Bit 7 - mest signifikant bit. */
};

/********************************************************************************
* byte_ptr: Union f�r att erh�lla refererad data som en byte eller som �tta
*           enskilda bitar i form av ett bitf�lt.
********************************************************************************/
union byte_ptr
{
   volatile uint8_t* byte;     /* Pekare till refererad data som en byte. */
   volatile struct bits* bits; /* Pekare till refererad data som enskilda bitar. */
};

/* Deklaration av globala objekt: */
extern union byte_ptr ddrb, portb, pinb;

#endif /* HEADER_H_ */
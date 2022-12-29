/********************************************************************************
* header.h: Innehåller diverse deklarationer och definitioner för implementering
*           av det inbyggda systemet.
********************************************************************************/
#ifndef HEADER_H_
#define HEADER_H_

/* Inkluderingsdirektiv: */
#include <avr/io.h> /* Innehåller information om I/O-register såsom PORTB. */

/********************************************************************************
* bits: Strukt för att erhålla enskilda bitar i en byte (åtta bitar), även
*       kallat ett bitfält.
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
* byte_ptr: Union för att erhålla refererad data som en byte eller som åtta
*           enskilda bitar i form av ett bitfält.
********************************************************************************/
union byte_ptr
{
   volatile uint8_t* byte;     /* Pekare till refererad data som en byte. */
   volatile struct bits* bits; /* Pekare till refererad data som enskilda bitar. */
};

/* Deklaration av globala objekt: */
extern union byte_ptr ddrb, portb, pinb;

#endif /* HEADER_H_ */
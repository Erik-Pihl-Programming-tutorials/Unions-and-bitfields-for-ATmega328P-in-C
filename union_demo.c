/********************************************************************************
* union_demo.c: Grunl�ggande demonstration av unioner.
********************************************************************************/
#include <stdio.h>

/********************************************************************************
* data: Union f�r att lagra ett tal antingen som ett flyttal eller ett heltal.
*       Medlemmerna i en union ligger p� samma minnesadress, vilket medf�r
*       mindre minnesm�ngd (unionens storlek s�tts till den st�rsta medlemmen,
*       h�r 8 byte p� grund av medlemmen decimal). Samtidigt medf�r detta att
*       enbart en av medlemmarna kan anv�ndas vid ett givet tillf�lle, vilket
*       �r den som senast tilldelades.
********************************************************************************/
union data
{
   double decimal; /* Flyttal. */
   int integer;    /* Heltal. */
};

/********************************************************************************
* main: Deklarerar en union f�r lagring av heltal och flyttal. F�rst tilldelas
*       heltalet -3 och skrivs ut i terminalen. Sedan tilldelas flyttalet 3.14
*       och skrivs ut i terminalen.
********************************************************************************/
int main(void)
{
   union data d1;

   d1.integer = -3;
   printf("Integer: %d\n", d1.integer);

   d1.decimal = 3.14;
   printf("Decimal: %lg\n", d1.decimal);

   printf("Size of struct data: %zu\n", sizeof(union data));

   return 0;
}
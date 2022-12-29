/********************************************************************************
* union_demo.c: Grunläggande demonstration av unioner.
********************************************************************************/
#include <stdio.h>

/********************************************************************************
* data: Union för att lagra ett tal antingen som ett flyttal eller ett heltal.
*       Medlemmerna i en union ligger på samma minnesadress, vilket medför
*       mindre minnesmängd (unionens storlek sätts till den största medlemmen,
*       här 8 byte på grund av medlemmen decimal). Samtidigt medför detta att
*       enbart en av medlemmarna kan användas vid ett givet tillfälle, vilket
*       är den som senast tilldelades.
********************************************************************************/
union data
{
   double decimal; /* Flyttal. */
   int integer;    /* Heltal. */
};

/********************************************************************************
* main: Deklarerar en union för lagring av heltal och flyttal. Först tilldelas
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
# Unioner och bitfält i C för mikrodator ATmega328P
Användning av unioner för läsning och skrivning till olika I/O-register via bifält.

Filen "header.h" innehåller deklaration av unionen byte samt strukten bits, som möjliggör att en 
innehållet i ett givet I/O-register kan erhållas som en enda enhet eller bitvis via pekare.

I filen "main.c" sker skrivning och läsning till I/O-register via tre unioner, som möjliggör att 
enskilda bitar kan avläsas, ett- och nollställas i givet register.

Filen "union_demo.c" utgör en grundläggande demonstration hur unioner fungerar via en enkel union döpt data,
som möjliggör att ett givet objekt kan lagra ett tal antingen som ett heltal eller flyttal. Samtidigt visas
att unionens storlek är samma som den största medlemmen i unionen, vilket i detta fall är 8 byte (på grund
av att ett flyttal av datatypen double upptar 8 byte när en x64-processor används).
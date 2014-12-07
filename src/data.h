#include <avr/pgmspace.h> //for use of Flash memory

// To add a text:
// update the counter below (1)
// copy an existing text and ELF number (2), update the sequence numbers and change the text and ELF (observing the length limits)
// update the lists at the end of this file (3, 4)

// (1)
//const int numTexts = 48;
const int numTexts = 3; //for testing

//All this data is stored in Flash memory where there's more space for it.
// (2)
//max 300 characters:        "------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------";

int elf1 = 20;
prog_char text1[] PROGMEM = "Santa can see your browser history, you know. We're giving you a lump of coal.";

int elf2 = 98;
prog_char text2[] PROGMEM = "You're too nice for your own good. We're sending you on a trip to Las Vegas.";

int elf3 = 55;
prog_char text3[] PROGMEM = "Helped a little old lady across the road once. We're giving you some nice lavender bath salts.";

// (3)
PROGMEM const char *texts[] = 	
{   
  text1,
  text2,
  text3,
};

//(4)
int elfs[] = 	
{   
  elf1,
  elf2,
  elf3
};

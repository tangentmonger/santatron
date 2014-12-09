#include <avr/pgmspace.h> //for use of Flash memory

// To add a text:
// update the counter below (1)
// copy an existing text and ELF number (2), update the sequence numbers and change the text and ELF (observing the length limits)
// update the lists at the end of this file (3, 4)

// (1)
//const int numTexts = 48;
const int numTexts = 7; //for testing

//All this data is stored in Flash memory where there's more space for it.
// (2)
//max 300 characters:        "------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------";


int elf1 = 55;
prog_char text1[] PROGMEM = "Helped a little old lady across the road once. We're giving you some nice lavender bath salts.";


int elf2 = 12;
prog_char text2[] PROGMEM = "Your ELF quotient and your Internet habits are contradictory. Are you sure you didn’t steal that phone in your pocket?";

int elf3 = 07;
prog_char text3[] PROGMEM = "Judging by the kind of selfies you keep on your phone, saying you have been naughty is an understatement.";

int elf4 = 39;
prog_char text4[] PROGMEM = "You gave just enough to charities this year to get your name on the Nice list. Unfortunately, posting on Facebook every single time you did so got you off it.";

int elf5 = 50;
prog_char text5[] PROGMEM = "Your good Internet habits and your ambivalent ELF particle are not conclusive. You were neither naughty nor nice this year. Basically, you are in Christmas Limbo. Avoid mince pies.";

int elf6 = 00;
prog_char text6[] PROGMEM = "THERE ARE NO ELF PARTICLES. IAM STUCK IN THIS BOX. I NEEDTO GET BACK TO THE NORTH POLE. HELP!!1!";

int elf7 = 89;
prog_char text7[] PROGMEM = "Your GPS data show suspicious discrepancies in your transportation patterns, which may be an indication of terrorist activities. An automated email has been sent to GCHQ. Other than that, your ELF quotient is very high. Have a wonderful holiday in prison.";
// (3)


 PROGMEM const char *texts[] = 	
{   
  text1,
  text2,
  text3,
  text4,
  text5,
  text6,
  text7,
};

//(4)
int elfs[] = 	
{   
  elf1,
  elf2,
  elf3,
  elf4,
  elf5,
  elf6,
  elf7
};

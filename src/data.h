#include <avr/pgmspace.h> //for use of Flash memory

// To add a text:
// update the counter below (1)
// copy an existing text (2), update its number and change the text (observing the length limits)
// update the list at the end of this file (3)

// (1)
//const int numTexts = 48;
const int numTexts = 3; //for testing

//All this data is stored in Flash memory where there's more space for it.
// (2)
//max 300 characters:        "------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------";
prog_char text0[] PROGMEM = "ELF quotient: 0.65. Helped a little old lady across the road once. You get some nice lavender bath salts.";
prog_char text1[] PROGMEM = "ELF quotient: 0.2. Santa can see your browser history, you know. You get a lump of coal.";
prog_char text2[] PROGMEM = "ELF quotient: 0.95. You're too nice for your own good. You get a trip to Las Vegas.";
prog_char text3[] PROGMEM = "";
prog_char text4[] PROGMEM = "";
prog_char text5[] PROGMEM = "";
prog_char text6[] PROGMEM = "";
prog_char text7[] PROGMEM = "";
prog_char text8[] PROGMEM = "";
prog_char text9[] PROGMEM = "";
prog_char text10[] PROGMEM = "";
prog_char text11[] PROGMEM = "";
prog_char text12[] PROGMEM = "";
prog_char text13[] PROGMEM = "";
prog_char text14[] PROGMEM = "";
prog_char text15[] PROGMEM = "";
prog_char text16[] PROGMEM = "";
prog_char text17[] PROGMEM = "";
prog_char text18[] PROGMEM = "";
prog_char text19[] PROGMEM = "";
prog_char text20[] PROGMEM = "";
prog_char text21[] PROGMEM = "";
prog_char text22[] PROGMEM = "";
prog_char text23[] PROGMEM = "";
prog_char text24[] PROGMEM = "";
prog_char text25[] PROGMEM = "";
prog_char text26[] PROGMEM = "";
prog_char text27[] PROGMEM = "";
prog_char text28[] PROGMEM = "";
prog_char text29[] PROGMEM = "";
prog_char text30[] PROGMEM = "";
prog_char text31[] PROGMEM = "";
prog_char text32[] PROGMEM = "";
prog_char text33[] PROGMEM = "";
prog_char text34[] PROGMEM = "";
prog_char text35[] PROGMEM = "";
prog_char text36[] PROGMEM = "";
prog_char text37[] PROGMEM = "";
prog_char text38[] PROGMEM = "";
prog_char text39[] PROGMEM = "";
prog_char text40[] PROGMEM = "";
prog_char text41[] PROGMEM = "";
prog_char text42[] PROGMEM = "";
prog_char text43[] PROGMEM = "";
prog_char text44[] PROGMEM = "";
prog_char text45[] PROGMEM = "";
prog_char text46[] PROGMEM = "";
prog_char text47[] PROGMEM = "";


PROGMEM const char *texts[] = 	
{   
  text0,
  text1,
  text2,
  text3,
  text4,
  text5,
  text6,
  text7,
  text8,
  text9,
  text10,
  text11,
  text12,
  text13,
  text14,
  text15,
  text16,
  text17,
  text18,
  text19,
  text20,
  text21,
  text22,
  text23,
  text24,
  text25,
  text26,
  text27,
  text28,
  text29,
  text30,
  text31,
  text32,
  text33,
  text34,
  text35,
  text36,
  text37,
  text38,
  text39,
  text40,
  text41,
  text42,
  text43,
  text44,
  text45,
  text46,
  text47
};

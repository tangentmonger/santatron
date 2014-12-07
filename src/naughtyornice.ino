// Version created November 2014 for Hack Circus Xmas party

// runs on arduino uno with Robs pcbs

#include "hardware.h" //definitions for Rob's PCB
#include "data.h" // output text

int currentSelection = -1;
int buttonStatus; //using button as if momentary :S
int FLASH_NUM = 5; //how often to flash red LED while "reading"
int PRINT_TIME = 21; //seconds

// sets up inputs, outputs etc
void setup() {

    pinMode(GO_BUTTON, INPUT);
	pinMode(LED13, OUTPUT);
	pinMode(RED_LED, OUTPUT);
	pinMode(GREEN_LED, OUTPUT);
    buttonStatus = digitalRead(GO_BUTTON);
}

// runs continuously, once the setup has run
void loop() {
	waitForGoButton();
    selectTextNumber();
	flashLights();
	char* text = generateText();
	char* elfQuotient = formatELFQuotient();
	printText(text, elfQuotient);
    glowResultLight();
    buttonStatus = digitalRead(GO_BUTTON);
} 

// wait for someone to press GO
void waitForGoButton(){
	while(digitalRead(GO_BUTTON) == buttonStatus){
		delay(10);
	}
}

// select which text to print next, by number
// first selection is "random", then proceed through the list and wrap around
void selectTextNumber(){
    if (currentSelection == -1){
        currentSelection = millis() % numTexts;
    } else {
        currentSelection = (currentSelection + 1) % numTexts;
    }
}

//Flash red LED FLASH_NUM times.
void flashLights(){
    for(int i=0;i<FLASH_NUM;i++){
        digitalWrite(RED_LED, HIGH);
        delay(250);
        digitalWrite(RED_LED, LOW);
        delay(250);
    }
}

//Retrieve ELF quotient and format it as text
char* formatELFQuotient(){
	char text[50];
    strcpy_P(text, "ELF quotient: ");
    char quotient[3];
    itoa(elfs[currentSelection], quotient, 10);
    strcat(text, quotient);
    strcat(text, "%");
	return text;
}
	
// Retrieve selected text
char* generateText(){
	char text[300];
    strcpy_P(text, (char*)pgm_read_word(&(texts[currentSelection])));
	return text;
}



// Word wrap the text and send to the printer
void printText(char* text, char* elfQuotient){
	Serial.begin(2400); 
	Serial.println("****************************************");
	Serial.println("*                                      *");
	Serial.println("*       SANTOMATIC: 2014 REPORT        *");
	Serial.println("*                                      *");
	Serial.println("****************************************");
	Serial.println();
	Serial.println(elfQuotient);
	Serial.println();


	//Break up the text to fit into the printer's line width.
	//Assumption: we only want to break on spaces, and those spaces can be lost (because they'll be at the start or end of a line)
	int printerWidth = 40;
	char *textEnd = strchr(text, '\0');
	char *lineStart = text;
	char *nextGoodBreakPosition = text;

	while(textEnd - lineStart > printerWidth)
	{
		//Serial.println((int)(textEnd - lineStart));
		nextGoodBreakPosition = lineStart;
		char *nextSpacePosition = strchr(lineStart, ' '); //assumption: there's at least one space. -1 if not
		while(nextSpacePosition != NULL && nextSpacePosition - lineStart <= printerWidth) // 0-39 = 40 characters
		{
			nextGoodBreakPosition = nextSpacePosition;
			nextSpacePosition = strchr(nextSpacePosition + 1, ' '); // might not be another space; that's ok
		}
		char toPrint[printerWidth + 1]; //eg. 40 characters plus null terminator
		memcpy(toPrint, lineStart, printerWidth); //usually copies too much; don't care, next line takes care of it
		toPrint[nextGoodBreakPosition - lineStart] = '\0';
		Serial.println(toPrint);
		lineStart = nextGoodBreakPosition+1;
	}

	char toPrint[printerWidth + 1]; //eg. 40 characters plus null terminator
	memcpy(toPrint, lineStart, printerWidth); //will copy \0 and then probably other garbage, don't care
	Serial.println(toPrint);


	//print a few blank lines
	Serial.println();
	Serial.println();
	Serial.println();
    Serial.println();
    Serial.println("****************************************");
	Serial.println("               Report ends              ");
    Serial.println("****************************************");    	
    Serial.println();
    Serial.println();
	Serial.println();
	Serial.println();
    Serial.println();
	Serial.println();
	Serial.println();
    Serial.println();
	Serial.println();
	Serial.println();
	Serial.println();
    Serial.println();
	Serial.println();
	Serial.println();
    Serial.println();
	Serial.println();
	Serial.println();

	Serial.end();
}

//Glow red or green (depending on ELF quotient) for roughly as
//long as it takes to print
void glowResultLight(){
    int colour;
    if (elfs[currentSelection] > 50){
        colour = GREEN_LED;
    } else {
        colour = RED_LED;
    }
    
    digitalWrite(colour, HIGH);
    delay(PRINT_TIME * 1000);
    digitalWrite(colour, LOW);
}


// each time this is called, change the LED light level (ie call frequently for a nice smooth pulse)
void pulseLEDs(){
  static float in[5] = {4.712, 5.712, 6.712, 7.712, 8.712};
  float out;

  for(int i=0; i<5; i++){
      in[i] = in[i] + 0.0004; //larger number for slower pulse
      if (in[i] > 10.995)
          in[i] = 4.712;
      out = 255 - (sin(in[i]) * 63.5 + 63.5);
      //analogWrite(LED_PWM[i], out);
  }
}



// for testing only
void testPrint(){
	digitalWrite(LED13, LOW); //light on 
	Serial.begin(2400); 
  	delay(1000);
  	Serial.println("PRINTER OK");
  	Serial.println("");
	Serial.end();
	digitalWrite(LED13, HIGH); //light off 
}

//NAME TO BE DETERMINED
//Firmware: V1.0.1

//WE <3 OPEN SOURCE
//This firmware falls under the Open Source Initiative and GNU
//General Public License.  Please use and alter as you'd like
//and let us know if you have any improvements for the community.

///////////////////////////////////////////////////////////////////
//Include libraries (don't have any yet...)!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
#include <Convert.h>

//Void Setup is the section where you can place commands for the
//system to run through during start up.  Anything within the setup
//section will only be run through once.
void setup(){
  //Serial.begin opens a 2-way communication port between the
  //device and your computer.
  Serial.begin(9600);
  //Here we will define the pins on the device's controller that we
  //will be communicating with.
  //Pins 4 & 13 is the Red LED.
  pinMode(4, OUTPUT); pinMode(13, OUTPUT);
}

//Void Loop is the section where you can place commands for the
//system to run through after start up.  Anything within the loop
//section will run continuously unless is is within a section 
//where conditions are not me: like "while" conditions.  The loop
//will run as quickly as the device can process each loop (not a 
//set speed.
void loop (){
  //Check to see if there is any data coming through the serial
  //port and if so, execute the code within the if-statement.
  if (Serial.available()) {
    //This will parse out the incoming serial data into small
    //sections (comma-seperated).  Each piece of data will be
    //temporarily stored under the variable "ActionPin".
    int ActionPin = Serial.parseInt();
      //We will now determine what the parsed information is and
      //use that information to determine how to handle the command.
      //When the correct Action Pin is found, "return" will let the
      //system go to the cooresponding action and exit this loop.
      if (ActionPin == 0){triggerLineEnd();return;}
      if (ActionPin == 1){triggerHigh(ActionPin);return;}
      if (ActionPin == 2){triggerHigh(ActionPin);return;}
      if (ActionPin == 3){triggerHigh(ActionPin);return;}
      if (ActionPin == 4){triggerHigh(ActionPin);return;}
      if (ActionPin == 6){triggerHigh(ActionPin);return;}
      if (ActionPin == 7){triggerHigh(ActionPin);return;}
      if (ActionPin == 8){triggerHigh(ActionPin);return;}
      if (ActionPin == 9){triggerHigh(ActionPin);return;}
      if (ActionPin == 10){triggerHigh(ActionPin);return;}
      if (ActionPin == 11){triggerHigh(ActionPin);return;}
      if (ActionPin == 12){triggerHigh(ActionPin);return;}
      if (ActionPin == 13){triggerLongHigh(ActionPin);return;}
      if (ActionPin == 14){triggerHigh(ActionPin);return;}
      if (ActionPin == 16){triggerHigh(ActionPin);return;}
      if (ActionPin == 17){triggerHigh(ActionPin);return;}
      if (ActionPin == 18){triggerHigh(ActionPin);return;}
      if (ActionPin == 19){triggerHigh(ActionPin);return;}
      //If the code has processed this far, no Action Pin has been
      //found and we need to trigger an error.
      triggerError();
  }
}

//Voids are the section where you can place commands for the
//system to run through once when directed to from either
//another void, setup, or loop.  
//Void "triggerHigh" is the action void that deals with High/Low
void triggerHigh(int pin){
  digitalWrite(pin, HIGH);
  delay(250);
  digitalWrite(pin, LOW);
  Serial.println("High Success.");
}
//Void "triggerLongHigh" is the action void that deals with Long Highs
void triggerLongHigh(int pin){
  digitalWrite(pin, HIGH);
  delay(1000);
  digitalWrite(pin, LOW);
  Serial.println("Long Success.");
}
//This is a trigger to determine when the serial line has ended.  It is the
//first variable checked because in serial communication, the ASCII for 0
//and submit appear the same.
void triggerLineEnd(){
  Serial.println("Line End.");
}
//This is a generic error trigger for when an action pin has not been found.
void triggerError(){
  Serial.println("ERROR: Invalid action pin.  This command has been skipped.");
}


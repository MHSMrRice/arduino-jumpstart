/* servo.ino Example sketch for IRLib2
 *  Illustrate how to now to control a servo using IR signals.
 *  
 *  1/11/2018 This example has been stripped of all of its servo parts, and 
 *  contains simple placeholder parts to show that a sketch can act on 
 *  receiving a signal.
 */
#include <IRLibDecodeBase.h> // First include the decode base
#include <IRLib_P02_Sony.h>  // Include only the protocol you are using

IRdecodeSony myDecoder; // Now declare an instance of that decoder.

#include <IRLibRecv.h> 
IRrecv myReceiver(2); //pin number for the receiver

void setup() { 
  myReceiver.enableIRIn();
  Serial.begin(9600);
} 

// if you are in control of the sender as well, just remember to make 
// sure that you are sening these specific codes to drive the switch-case
#define MYPROTOCOL SONY
#define BUTTON_0 0x90bca
#define BUTTON_1 0x00bca
#define BUTTON_2 0x80bca
#define BUTTON_3 0x40bca
#define BUTTON_4 0xc0bca
#define BUTTON_5 0x20bca
#define BUTTON_6 0xa0bca
#define BUTTON_7 0x60bca
#define BUTTON_8 0xe0bca
#define BUTTON_9 0x10bca

void loop() { 
  if (myReceiver.getResults()) {    //if you have recieved results
    if(myDecoder.decode()) {        //then decode those results to determine the code
      switch(myDecoder.value) {     //use the decoded value to drive a switch-case
        case BUTTON_0:      
          Serial.print("0x90bca"); 
          break;                      //the BUTTON_1 switch case will be used to show how a switch-case works:
        case BUTTON_1:                //ex: identify the button value that is driving the switch-case
          Serial.print("0x00bca");    //ex: do whatever you want as a result of recieving that button code > this can be many lines long...
          break;                      //ex: 'break' exits you from the switch-case 
        case BUTTON_2:      
          Serial.print("0x80bca"); 
          break;
        case BUTTON_3:      
          Serial.print("0x40bca"); 
          break;
        case BUTTON_4:      
          Serial.print("0xc0bca"); 
          break;
        case BUTTON_5:      
          Serial.print("0x20bca"); 
          break;
        case BUTTON_6:      
          Serial.print("0xa0bca"); 
          break;
        case BUTTON_7:      
          Serial.print("0x60bca"); 
          break;
        case BUTTON_8:      
          Serial.print("0xe0bca"); 
          break;
        case BUTTON_9:      
          Serial.print("0x10bca"); 
          break;
      }
    }
    myReceiver.enableIRIn();
  }
}

/* send.ino Example sketch for IRLib2
 *  Illustrates how to send a code.
 *  
 *  1/11/2018 This example was changed to simplify the example, 
 *  and show how to send a code if a button is being pressed.
 */

#include <IRLibSendBase.h>    // First include the send base
#include <IRLib_P02_Sony.h>   
#include <IRLibCombo.h>     // After all protocols, include this
// All of the above automatically creates a universal sending
// class called "IRsend" containing only the protocols you want.
// Now declare an instance of that sender.

IRsend mySender;    //initalize the sender object

#define button 3 //you can ger rid of all button lines, if you would like to send codes based on something else

void setup() {
  Serial.begin(9600);
  pinMode(button, INPUT_PULLUP);
}

// if you are in control of the reciever as well, just remember to make 
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
    if(digitalRead(button) == LOW){
      mySender.send(MYPROTOCOL, BUTTON_0, 20); //Sony DVD. 'BUTTON_0'=90bca, 20 bits  
      //in order to send, you will need all three parameters to the .send() method, but only change the middle one...
  }
}

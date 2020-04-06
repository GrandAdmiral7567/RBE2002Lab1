#include "button.h"



//corresponds to the A button on our Zumo
const uint8_t buttonPin = 14; 
//create out button
Button pushButton(buttonPin,15);



void setup() 
{
  //set up serial monitor
  Serial.begin(9600);
  //initialize our button
  pushButton.Init();
}

//how many times is the button pressed (first press will show count, so start at 1)
unsigned long pushCount = 1;

void loop() 
{
  //if pushed...
  if(pushButton.CheckButtonPress()) 
  {
    //update count
    Serial.println(pushCount++);
  }
}

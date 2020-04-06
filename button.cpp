#include "button.h"


Button::Button(uint8_t pin, uint32_t db)
{
  //pin is A button
  aButton = pin;

  //the period of the debounce
  debounceTime = db;

}


void Button::Init() {

  	pinMode(aButton, INPUT_PULLUP);
}


//are we pressing the button?
bool Button::CheckButtonPress(void) {

  //button position temporary value
  newBPos = bPos;

  //read the A button
  bPos = digitalRead(aButton);

  switch (bS) {
    //stable case
    case STABLE:
	 
      //did our position change
      if (bPos == newBPos) {
        return false;
      }


      //we actually changed
      if (bPos != newBPos) {
	   
        //record when we last bounced
        prevBounce = millis();

	   //change state
        bS = UNSTABLE;

        //end
        return false;
      }

      //end of case
      break;




    //unstable case
    case UNSTABLE:
      //have we bounced again?
      if (millis() >= prevBounce + debounceTime) {


        if (bPos == 0) {

	     if(newBPos == 0){
			//change state
          		bS = STABLE;

          		return true;
		}
        }

        else {

          bS = STABLE;

          return false;
        }
      } 

      else if (bPos != newBPos) { 
	   //record last bounce
        prevBounce = millis();

        return false;
      }

      break;
  }


}






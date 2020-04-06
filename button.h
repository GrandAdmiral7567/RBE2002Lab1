#include <Arduino.h>
#ifndef __BUTTON_H
#define __BUTTON_H

//button class with state machine for debouncing
class Button
{
  private:

    //enumeration for button states
    enum BUTTON_STATE {STABLE, UNSTABLE};

    //initial state is stable
    BUTTON_STATE bS = STABLE;

    //when did we bounce last
    uint32_t prevBounce = 0;

    //period of the bounce (ms)
    uint32_t debounceTime = 15;

    uint8_t newBPos = HIGH;

    uint8_t buttonP = HIGH;  //assumes active LOW

    //button pins and position

    int8_t bPos = 1;

    int8_t aButton = -1;

  public:
    //create button
    Button(uint8_t pin, uint32_t db = 15);

    //init and run check
    void Init();
    bool CheckButtonPress(void);


};

#endif

#include "Mouse.h"

/*----------------define the button pins---------------------------*/
const int upButton = 3;
const int downButton = 4;
const int leftButton = 5;
const int rightButton = 6;
const int centerButton = 7;

// output range of X or Y movement; affects movement speed
int range = 1;
int init_range = 1;
int max_range = 40;

int begin_num = 0;
int end_num = 120;
int step_num = 2;
int x_dig = 0;
int y_dig = 0;

// response delay of the mouse, in ms
int responseDelay = 1;

// Define variables used in sketch
int click_state;
unsigned long left_state;
unsigned long old_left_state;
unsigned long right_state;
unsigned long old_right_state;
unsigned long up_state;
unsigned long old_up_state;
unsigned long down_state;
unsigned long old_down_state;

int x_position;
int y_position;

void setup()
{
  // initialize the buttons' inputs:
  pinMode(upButton, INPUT);
  pinMode(downButton, INPUT);
  pinMode(leftButton, INPUT);
  pinMode(rightButton, INPUT);
  pinMode(centerButton, INPUT);

  // initialize mouse control:
  Mouse.begin();
  Serial.begin(112500);
}

void loop()
{

  delay(responseDelay);

  left_state = digitalRead(leftButton);
  right_state = digitalRead(rightButton);
  up_state = digitalRead(upButton);
  down_state = digitalRead(downButton);
  click_state = digitalRead(centerButton);

  if (left_state != old_left_state)
  {
    Mouse.move(-range, 0, 0);
    old_left_state = left_state;
    x_dig++;
  }
  if (right_state != old_right_state)
  {
    Mouse.move(range, 0, 0);
    old_right_state = right_state;
    x_dig++;
  }

  if (up_state != old_up_state)
  {
    Mouse.move(0, -range, 0);
    old_up_state = up_state;
    y_dig++;
  }
  if (down_state != old_down_state)
  {
    Mouse.move(0, range, 0);
    old_down_state = down_state;
    y_dig++;
  }

  if (begin_num == end_num)
  {
    begin_num = 0;
    x_dig = 0;
    y_dig = 0;
  }
  if (begin_num < end_num)
  {
    begin_num++;
    range = init_range + (x_dig + y_dig) * step_num;
    if (range > max_range)
    {
      range = max_range;
    }
  }

  /*-------------Mouse Button Left Click------------------------------*/
  // if the mouse button left is pressed:
  if (click_state == LOW)
  {
    // if the mouse is not pressed, press it:
    if (!Mouse.isPressed(MOUSE_LEFT))
    {
      Mouse.press(MOUSE_LEFT);
      // Mouse.click(MOUSE_LEFT);
    }
  }
  // else the mouse button left is not pressed:
  else
  {
    // if the mouse is pressed, release it:
    if (Mouse.isPressed(MOUSE_LEFT))
    {
      Mouse.release(MOUSE_LEFT);
    }
  }
}
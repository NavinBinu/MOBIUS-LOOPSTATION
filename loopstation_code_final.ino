/*
 *LOOPSTATION MADE FROM ARDUINO LEONARDO
 *WORKS ONLY ON ARDUINO PRO MICRO, LEONARDO OR DUE
 *SOFTWARE- MOBIUS BY CIRCULAR LABS
 *https://www.circularlabs.com/
 *MOBIUS SCRIPTS - ISRAEL E.B
 *https://github.com/IsraEB/Mobius_Fork/tree/master/scripts/IsraelEB
 * 25 JULY 2021 
 *NAVIN BINU - MATHEW P HANS
 *TEXT ME ON INSTAGRAM IF YOU WANT ME TO MAKE ONE OR NEED ANY HELP
 *I MADE THIS PROJECT WHEN I AM 14, I DON'T HAVE MUCH EXPERIENCE IN ARDUINO, BUT EVERYTHING WORKS PERFECT :-D
 *
 *https://www.instagram.com/navin_binu/
 *
 *I USED MOMENTARY FOOT SWITHES AS THE FOOT PEDALS, MAKE SURE ITS NORMALLY OPEN AND NOT NORMALLY CLOSED
 *I USED 1K OHM RESISTOR FOR THE LEDS
 *A 15.5 INCH MONITOR WAS ATTACHED ON TOP OF THE LOOPSTATION 
 *I USED AN MICRO USB- B BREAKOUT, TOOK AN USB CABLE AND CONNECTED IT TO THE ARDUINO, THEN REMOVED THE USB PART AND
 *ATTACHED IT TO THE FEMALE BREAKOUT, IT HELPED ME TO MAKE THE USB CABLE REMOVABLE AND EASIER TO SCREW ON THE LOOPSTATION 
 *THIS PROJECT USES SIMPLE KEYBOARD INPUT INSTEAD OF MIDI INPUT
 *
 *
 *
 *THIS CODE IS MADE ONLY FOR ARDUINO LEONARDO, IN ORDER TO USE WITH DUE OR PRO MICRO, CHANGE THE PINS
*/

#include <Keyboard.h>

//LED PINS  
int LED1 = 18; //ANALOG PIN A0
int LED2 = 19; //ANALOG PIN A1
int LED3 = 20; //ANALOG PIN A2
int LED4 = 21; //ANALOG PIN A3
int LED5 = 22; //ANALOG PIN A4
int LED6 = 23; //ANALOG PIN A5

int stateLED1 = LOW;
int stateLED2 = LOW;
int stateLED3 = LOW;
int stateLED4 = LOW;
int stateLED5 = LOW;

long time = 0;
long debounce = 200;

bool leda1;
bool leda2;
bool leda3;
bool leda4;
bool leda5;

bool ledb1;
bool ledb2;
bool ledb3;
bool ledb4;
bool ledb5;

bool ready1;
bool ready2;
bool ready3;
bool ready4;
bool ready5;
bool ready6;

bool ledsts1; //stands for led status 1
bool ledsts2; 
bool ledsts3;
bool ledsts4; 
bool ledsts5;
bool ledsts6;

void setup() {
//LED STATUS BOOL
ledsts1 = false;
ledsts2 = false; 
ledsts3 = false;
ledsts4 = false; 
ledsts5 = false;
ledsts6 = false;

//READY LED BOOL
ready1 = false; 
ready2 = false;
ready3 = false;
ready4 = false;
ready5 = false;
ready6 = true; //LED6 DOESN'T IGNORE 1ST PRESS

//CLEAR TRACK LED BOOL
leda1 = false;
leda2 = false;
leda3 = false;
leda4 = false;
leda5 = false;

//CONTINOUS TRACK RECORDING BOOL
ledb1 = false;
ledb2 = false;
ledb3 = false;
ledb4 = false;
ledb5 = false;

pinMode(LED1, OUTPUT); // LEDS 
pinMode(LED2, OUTPUT);
pinMode(LED3, OUTPUT);
pinMode(LED4, OUTPUT);
pinMode(LED5, OUTPUT);
pinMode(LED6, OUTPUT);
pinMode(0,INPUT_PULLUP);  // sets pin 0 to input & pulls it high w/ internal resistor
pinMode(1,INPUT_PULLUP);  // sets pin 1 to input & pulls it high w/ internal resistor
pinMode(2,INPUT_PULLUP);  // sets pin 2 to input & pulls it high w/ internal resistor
pinMode(3,INPUT_PULLUP);  // sets pin 3 to input & pulls it high w/ internal resistor
pinMode(4,INPUT_PULLUP);  // sets pin 4 to input & pulls it high w/ internal resistor
pinMode(5,INPUT_PULLUP);  // sets pin 5 to input & pulls it high w/ internal resistor
pinMode(6,INPUT_PULLUP);  // sets pin 6 to input & pulls it high w/ internal resistor
pinMode(7,INPUT_PULLUP);  // sets pin 7 to input & pulls it high w/ internal resistor
pinMode(8,INPUT_PULLUP);  // sets pin 8 to input & pulls it high w/ internal resistor
pinMode(9,INPUT_PULLUP);  // sets pin 9 to input & pulls it high w/ internal resistor

digitalWrite (LED1, LOW); //ALL LEDS ARE OFF AT START
digitalWrite (LED2, LOW);
digitalWrite (LED3, LOW);
digitalWrite (LED4, LOW);
digitalWrite (LED5, LOW);
digitalWrite (LED6, LOW);

;Serial.begin(9600);       // begin serial comms for debugging
}

void loop() {
  Keyboard.begin();         //begin keyboard 
 
 //----------------------------------------------------------------------------------------
  if (digitalRead(0) == 0)  
  { Keyboard.write('r');  // RECORD
     delay(200);           //LED6 DOESN'T IGNORE 1ST PRESS
  if(ready6 == true)
{
if (ledsts6 == false)
   {
    digitalWrite( LED6, HIGH); 
    ledsts6 = true;
   }
   else
   {
    digitalWrite( LED6, LOW);
    ledsts6 = false;
   }
    }
  }
  //TRACKS RECORD ON THEIR OWN AT START, RECORD BUTTON IS USED TO RECORD AFTER CLEARING A SINGLE TRACK OR TO OVERDUB
//----------------------------------------------------------------------------------------
  else if (digitalRead(1) == 0){  
     Keyboard.write('m');  // GLOBAL MUTE
    delay(200);
   //DOES NOT AFFECT THE LEDS 
  }
//----------------------------------------------------------------------------------------
  else if (digitalRead(2) == 0){  
     Keyboard.write('v');  // CLEAR
    delay(200);
//TURNS OFF SELECTED TRACK'S LED
//THE TRACK LED IGNORES 1ST PRESS WHILE IN THE FIRST
       if(leda1 == true)
        {digitalWrite (LED1, LOW);
          ready1 = false;
          ledsts1 = false;}
          
          if(leda2 == true)
          {digitalWrite (LED2, LOW);
          ready2 = false;
          ledsts2 = false;}
          
          if(leda3 == true)
          {digitalWrite (LED3, LOW);
          ready3 = false;
          ledsts3 = false;}
        
          if(leda4 == true)
          {digitalWrite (LED4, LOW);
          ready4 = false;
          ledsts4 = false;}
          
          if(leda5 == true)
          {digitalWrite (LED5, LOW);
          ready5 = false;
          ledsts5 = false;}
    //CLEAR TRACK WHILE TRACK LED IS ON TO AVOID MISCONFIGURATION 
}
//---------------------------------------------------------------------------------------- 
else if (digitalRead(3) == 0){  
     Keyboard.write('n');  // UNDO
    delay(200);
  }
//----------------------------------------------------------------------------------------
else if (digitalRead(4) == 0){  
     Keyboard.write('x');  // GLOBAL RESET
    delay(200);
//ALL LEDS GET TURN OFF, ALL TRACKS ARE CLEARED AND THE LOOPSTATION RESTARTS
digitalWrite (LED1, LOW);
digitalWrite (LED2, LOW);
digitalWrite (LED3, LOW);
digitalWrite (LED4, LOW);
digitalWrite (LED5, LOW);
digitalWrite (LED6, LOW);

ledsts1 = false;
ledsts2 = false; 
ledsts3 = false;
ledsts4 = false; 
ledsts5 = false;
ledsts6 = false;

ready1 = false; 
ready2 = false;
ready3 = false;
ready4 = false;
ready5 = false;
ready6 = true;

leda1 = false;
leda2 = false;
leda3 = false;
leda4 = false;
leda5 = false;

ledb1 = false;
ledb2 = false;
ledb3 = false;
ledb4 = false;
ledb5 = false;


}
//----------------------------------------------------------------------------------------
  
    else if (digitalRead(5) == 0){  
     Keyboard.write('1');  //TRACK 1
    delay(200);
if(ready1 == true)
{
  leda1 = true; //EVERYTIME WE PRESS, TRACK 1 GETS SELECTED IN ARDUINO
  leda4 = false;
  leda2 = false;
  leda3 = false;
  leda5 = false;
  
if (ledb1 == true)
{digitalWrite (LED1, HIGH);
ledb1 = false;}

if (ledsts1 == false)
   {
    digitalWrite( LED1, HIGH); 
    ledsts1 = true;
   }
   else
   {
    digitalWrite( LED1, LOW);
    ledsts1 = false;
   }
}
if (ready1 == false)
{
  ready1 = true;
  leda1 = true;
  ledb1 = true;
  
  //INORDER TO CONTINOUSLY RECORD TRACKS WITH LED CONFIGURATION
        if(leda2 == true)
        {
          digitalWrite (LED2, HIGH);
          leda2 = false;
          ledsts2 = true;
        }
        if(leda3 == true)
        { 
          digitalWrite (LED3, HIGH);
          leda3 = false;
          ledsts3 = true;
        }
        if(leda4 == true)
        {
          digitalWrite (LED4, HIGH);
          leda4 = false;
          ledsts4 = true;
        }
        if(leda5 == true)
        {
          digitalWrite (LED5, HIGH);
          leda5 = false;
          ledsts5 = true;
        }
}
}

//----------------------------------------------------------------------------------------

else if (digitalRead(6) == 0){  
     Keyboard.write('2'); // TRACK 2
    delay(200);

if(ready2 == true)
{
  leda2 = true; //EVERYTIME WE PRESS, TRACK 2 GETS SELECTED IN ARDUINO
  leda1 = false;
  leda4 = false;
  leda3 = false;
  leda5 = false;
  
  if (ledb2 == true)
{digitalWrite (LED2, HIGH);}
if (ledsts2 == false)
   {
    digitalWrite( LED2, HIGH); 
    ledsts2 = true;
   }
   else
   {
    digitalWrite( LED2, LOW);
    ledsts2 = false;
   }
 }
if (ready2 == false)
{
ready2 = true;
  leda2 = true;
  ledb2 = true;
  //INORDER TO CONTINOUSLY RECORD TRACKS WITH LED CONFIGURATION
        if(leda1 == true)
        {
          digitalWrite (LED1, HIGH);
          leda1 = false;
          ledsts1 = true;
        }
        if(leda3 == true)
        { 
          digitalWrite (LED3, HIGH);
          leda3 = false;
          ledsts3 = true;
        }
        if(leda4 == true)
        {
          digitalWrite (LED4, HIGH);
          leda4 = false;
          ledsts4 = true;
        }
        if(leda5 == true)
        {
          digitalWrite (LED5, HIGH);
          leda5 = false;
          ledsts5 = true;
        }
}
}

//---------------------------------------------------------------------------------------- 
   else if (digitalRead(7) == 0){  
     Keyboard.write('3');  //TRACK 3
    delay(200);

if(ready3 == true)
{
  leda3 = true; //EVERYTIME WE PRESS, TRACK 3 GETS SELECTED IN ARDUINO
  leda1 = false;
  leda2 = false;
  leda4 = false;
  leda5 = false;
  
  if (ledb3 == true)
{digitalWrite (LED3, HIGH);
ledb3 = false;}

if (ledsts3 == false)
   {
    digitalWrite( LED3, HIGH); 
    ledsts3 = true;
   }
   else
   {
    digitalWrite( LED3, LOW);
    ledsts3 = false;
   }
    }
if (ready3 == false)
{
ready3 = true;
  leda3 = true;
  ledb3 = true;
  //INORDER TO CONTINOUSLY RECORD TRACKS WITH LED CONFIGURATION
        if(leda1 == true)
        {
          digitalWrite (LED1, HIGH);
          leda1 = false;
          ledsts1 = true;
        }
        if(leda2 == true)
        { 
          digitalWrite (LED2, HIGH);
          leda2 = false;
          ledsts2 = true;
        }
        if(leda4 == true)
        {
          digitalWrite (LED4, HIGH);
          leda4 = false;
          ledsts4 = true;
        }
        if(leda5 == true)
        {
          digitalWrite (LED5, HIGH);
          leda5 = false;
          ledsts5 = true;
        }
}

}
//----------------------------------------------------------------------------------------
else if (digitalRead(8) == 0){  
     Keyboard.write('4');  // TRACK 4
    delay(200);


if(ready4 == true)
{
  leda4 = true; //EVERYTIME WE PRESS, TRACK 4 GETS SELECTED IN ARDUINO
  leda1 = false;
  leda2 = false;
  leda3 = false;
  leda5 = false;
if (ledsts4 == false)
   {
    digitalWrite( LED4, HIGH); 
    ledsts4 = true;
   }
   else
   {
    digitalWrite( LED4, LOW);
    ledsts4 = false;
   }
    }
if (ready4 == false)
{
ready4 = true;
leda4 = true;
ledb4 = true;

if(leda1 == true)
   //INORDER TO CONTINOUSLY RECORD TRACKS WITH LED CONFIGURATION     
          {digitalWrite (LED1, HIGH);
          leda1 = false;
          ledsts1 = true;}
        
        if(leda3 == true)
        { 
          digitalWrite (LED3, HIGH);
          leda3 = false;
          ledsts3 = true;
        }
        if(leda2 == true)
        {
          digitalWrite (LED2, HIGH);
          leda2 = false;
          ledsts2 = true;
        }
        if(leda5 == true)
        {
          digitalWrite (LED5, HIGH);
          leda5 = false;
          ledsts5 = true;
        }}
}
 
//---------------------------------------------------------------------------------------- 
   else if (digitalRead(9) == 0){  
     Keyboard.write('5');  //TRACK 5
    delay(200);

if(ready5 == true)
{
  leda5 = true; //EVERYTIME WE PRESS, TRACK 5 GETS SELECTED IN ARDUINO
  leda1 = false;
  leda2 = false;
  leda3 = false;
  leda4 = false;
if (ledsts5 == false)
   {
    digitalWrite( LED5, HIGH); 
    ledsts5 = true;
   }
   else
   {
    digitalWrite( LED5, LOW);
    ledsts5 = false;
   }
    }
if (ready5 == false)
{
ready5 = true;
leda5 = true;
ledb5 = true;

if(leda1 == true)
        {//INORDER TO CONTINOUSLY RECORD TRACKS WITH LED CONFIGURATION
          digitalWrite (LED1, HIGH);
          leda1 = false;
          ledsts1 = true;
        }
        if(leda3 == true)
        { 
          digitalWrite (LED3, HIGH);
          leda3 = false;
          ledsts3 = true;
        }
        if(leda4 == true)
        {
          digitalWrite (LED4, HIGH);
          leda4 = false;
          ledsts4 = true;
        }
        if(leda2 == true)
        {
          digitalWrite (LED2, HIGH);
          leda2 = false;
          ledsts2 = true;
        }}
}
//----------------------------------------------------------------------------------------  
  Keyboard.end();                 //stops keyboard
}

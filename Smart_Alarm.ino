#include "notes.h"
#include "LED.h"
#include "Display.h"
#include "Countdown.h"
#include "Speaker.h"
#include "Clock.h"
//#include "WIFI.h"

//WIFI esp;
LED redled(A4, 100, 400);
Display screen(4,1,0,5,6,7,8, 10,11,12,13);
//Countdown CD(screen);
Speaker speaker(A0);
Clock klok(12,00);

bool alarmtiggered = false;
bool alarmon = true;
int alarmtime = 1201;
unsigned long alarmMillis = millis();
unsigned long buttonpressed = millis();
unsigned long analogread = millis();


void setup() {
  // put your setup code here, to run once:
   //Serial.begin(9600);
   pinMode(A5, INPUT);
   pinMode(A2, INPUT);
  speaker.play(NOTE_C5, 200);
}

void loop() {
  //esp.Update();
  if(millis() - analogread > 5000){
    screen.number = analogRead(A2);
    analogread = millis();
  }
  
  redled.Update();
  //CD.Update();
  klok.Update();
  screen.number = klok.number;
  
  if(digitalRead(A5) == HIGH && millis() - buttonpressed > 1000){
    alarmtime = klok.number + 1;
    alarmon = true;
    buttonpressed = millis();
  }
  
  /*
   * Check Alarm
   */
  if(alarmon == true){
    redled.state = 2;
  } else if(alarmon == false && alarmtiggered == true){
    redled.state = 1;
  } else {
    redled.state = 0;
  }
  if(klok.number == alarmtime && alarmon == true && alarmtiggered == false){
    speaker.alarmOn();
    alarmtiggered = true;
    alarmon = false;
    alarmMillis = millis();
    buttonpressed = millis();
  }
  
  /*
   * Disable Alarm
   */
  if((alarmtiggered == true) && (millis() - alarmMillis >= 5000)){
     if(millis() - analogread > 1000){
      if(analogRead(A2) > 600){
        speaker.alarmOff();
        alarmtiggered = false;
      }
      analogread = millis();
     }
    
  }
  speaker.Update();
  screen.Update();
}

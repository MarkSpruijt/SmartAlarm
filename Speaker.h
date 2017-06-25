  
    class Speaker
    {
      // Class Member Variables
      // These are initialized at startup
      
      // These maintain the current state
      unsigned long previousMillis;   // will store last time LED was updated
      int pin;

      /*
       *  PULSE SETTINGS
       */
      int pulse_note;
      int pulse_duration;
      int pulse_delay;
      int pulse_amount = 0;

      /*
       * Bomb settings
       */
       int bomb_interval;

      /*
       * Alarm
       */
       bool alarm_onoff = false;
      
      // Constructor - creates a Countdown 
      // and initializes the member variables and state
      public:
      int state = 0;
      Speaker(int _pin)
      {
        pin = _pin;
        previousMillis = millis();
      }
     
      void Update()
      {
        // check to see if it's time to change the state of the LED
        unsigned long currentMillis = millis();
        if(state == 0){
          runpulse(currentMillis);
        } else if(state == 1){
          runpulse(currentMillis, true);
        }
        
      }

      void play(int note, int duration){
        tone(pin, note, duration);
      }

      void pulse(int note, int duration, int _delay, int amount){
        previousMillis = millis();
        pulse_note = note;
        pulse_duration = duration;
        pulse_delay = _delay;
        pulse_amount = amount;        
      }

      void runpulse(unsigned long dt, bool _bomb=false){
        if((pulse_amount > 0) && (dt - previousMillis >= pulse_delay)){
          play(pulse_note, pulse_duration);
          previousMillis = millis();
          pulse_amount--;
          if(_bomb){
            pulse_delay -= 10;
            if(pulse_delay <= 0){
              pulse_delay=5;
            }
            if(pulse_amount == 0){
              bomb();
            }
          }
          if(alarm_onoff == false){
            pulse_amount = 0;
          }
        }
      }
      
      void alarmOn(){
        alarm_onoff = true;
        bomb();
        //pulse(NOTE_D8, 150, 300, 99999);
      }

      void alarmOff(){
        alarm_onoff = false;
      }

      void bomb(){
        previousMillis = millis();
        pulse_note = NOTE_G6;
        pulse_duration = 100;
        pulse_delay = 300;
        pulse_amount = 150;
        state = 1; 
      }
      void bingbingbong(){
        
      }
      
    };

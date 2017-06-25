    class LED
    {
      // Class Member Variables
      // These are initialized at startup
      int ledPin;      // the number of the LED pin
      long OnTime;     // milliseconds of on-time
      long OffTime;    // milliseconds of off-time
     
      // These maintain the current state
      int ledState;                 // ledState used to set the LED
      unsigned long previousMillis;   // will store last time LED was updated
      
      // Constructor - creates a Flasher 
      // and initializes the member variables and state
      public:
      /*
       * 0: Off
       * 1: Blink
       * 3: On
       */
      int state = 0;
      LED(int pin, long on, long off)
      {
      ledPin = pin;
      pinMode(ledPin, OUTPUT);    
        
      OnTime = on;
      OffTime = off;

      
      
      ledState = LOW; 
      previousMillis = 0;
      }
     
      void Update()
      {
        // check to see if it's time to change the state of the LED
        unsigned long currentMillis = millis();
        if(state == 0 && ledState == HIGH){
          ledState = LOW;
          digitalWrite(ledPin, ledState);          
        }
        if(state == 1){
          if((ledState == HIGH) && (currentMillis - previousMillis >= OnTime))
          {
            ledState = LOW;  // Turn it off
            previousMillis = currentMillis;  // Remember the time
            digitalWrite(ledPin, ledState);  // Update the actual LED
          }
          else if ((ledState == LOW) && (currentMillis - previousMillis >= OffTime))
          {
            ledState = HIGH;  // turn it on
            previousMillis = currentMillis;   // Remember the time
            digitalWrite(ledPin, ledState);   // Update the actual LED
          }
        }
        if(state == 2 && ledState == LOW){
          ledState = HIGH;
          digitalWrite(ledPin, ledState);          
        }
        
      }
    };

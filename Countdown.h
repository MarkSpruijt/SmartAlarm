  
    class Countdown
    {
      // Class Member Variables
      // These are initialized at startup
      
      // These maintain the current state
      unsigned long previousMillis;   // will store last time LED was updated
     
      // Constructor - creates a Countdown 
      // and initializes the member variables and state
      public:
      int number;
      Countdown(Display _screen, int _number = 9999)
      {
        number = _number;
        previousMillis = millis();
      }
     
      void Update()
      {
        // check to see if it's time to change the state of the LED
        unsigned long currentMillis = millis();
        
        if(previousMillis + 1000 == currentMillis)
        {
            number = number - 1;
            previousMillis =  currentMillis;
        }
      }

      
    };

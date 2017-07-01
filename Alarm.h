  
    class Alarm
    {
      // Class Member Variables
      // These are initialized at startup
      
      // These maintain the current state
      unsigned long previousMinute;
      unsigned long buttonpressed;

      int hour;
      int minutes;
      
      // Constructor - creates a Countdown 
      // and initializes the member variables and state
      public:
      int alarm = 0;
      int number;
      Alarm(int _hour = 6, int _minutes = 0)
      {
        pinMode(A3, INPUT);
        hour = _hour;
        minutes = _minutes;
        number = (hour * 100) + minutes;
        buttonpressed = millis();
      }
     
      void Update(bool allowbutton = true)
      {
        // check to see if it's time to change the state of the LED
        unsigned long currentMillis = millis();
        if((digitalRead(A3) == HIGH && currentMillis - buttonpressed  > 100))
        {
            minutes = minutes + 1;
            if(minutes == 60){
              minutes = 0;
              hour = hour + 1;
              if(hour >= 24){
                hour = 0;
              }          
            }
            buttonpressed = currentMillis;
        }
        number = (hour * 100) + minutes;
      }

      
    };

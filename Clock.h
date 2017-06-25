  
    class Clock
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
      Clock(int _hour = 12, int _minutes = 0)
      {
        pinMode(A3, INPUT);
        hour = _hour;
        minutes = _minutes;
        number = (hour * 100) + minutes;
        previousMinute = millis();
        buttonpressed = millis();
      }
     
      void Update()
      {
        // check to see if it's time to change the state of the LED
        unsigned long currentMillis = millis();
        if((previousMinute + 60000 == currentMillis) || ((digitalRead(A3) == HIGH && currentMillis - buttonpressed  > 100)))
        {
            minutes = minutes + 1;
            if(minutes == 60){
              minutes = 0;
              hour = hour + 1;
              if(hour >= 24){
                hour = 0;
              }          
            }
            previousMinute =  currentMillis;
            buttonpressed = currentMillis;
            if(digitalRead(A3) == HIGH){
              int x;
              alarm = minutes + 1;
              if(alarm == 60){
              alarm = 0;
              x = hour + 1;
              if(x == 24){
                x = 0;
              }
                  
            }
            alarm = (x * 100) + alarm; 
            }
        }
        number = (hour * 100) + minutes;
      }

      
    };

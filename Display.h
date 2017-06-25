    class Display
    {
      // Class Member Variables
      // These are initialized at startup
      int pinA;
      int pinB;
      int pinC;
      int pinD;
      int pinE;
      int pinF; 
      int pinG;
      int D1;
      int D2;
      int D3;
      int D4;
     
      // These maintain the current state
      unsigned long previousMillis;
      unsigned long digitMillis;
     
      // Constructor - creates a Display 
      // and initializes the member variables and state
      public:
      int number;
      Display(){}
      Display(int A, int B, int C, int D, int E, int F, int G, int _D1, int _D2, int _D3, int _D4)
      {
      previousMillis = millis();
      digitMillis = millis();
      pinMode(A0, OUTPUT);
      // setup pins bars
      pinA = A;
      pinB = B;
      pinC = C;
      pinD = D;
      pinE = E;
      pinF = F; 
      pinG = G;
      D1 = _D1;
      D2 = _D2;
      D3 = _D3;
      D4 = _D4;
      number = 9876;
      pinMode(pinA, OUTPUT);
      pinMode(pinB, OUTPUT);
      pinMode(pinC, OUTPUT);
      pinMode(pinD, OUTPUT);
      pinMode(pinE, OUTPUT);
      pinMode(pinF, OUTPUT);
      pinMode(pinG, OUTPUT);
      pinMode(D1, OUTPUT);
      pinMode(D2, OUTPUT);
      pinMode(D3, OUTPUT);
      pinMode(D4, OUTPUT);
      digitalWrite(pinA, LOW);
      digitalWrite(pinB, LOW);
      digitalWrite(pinC, LOW);
      digitalWrite(pinD, LOW);
      digitalWrite(pinE, LOW);
      digitalWrite(pinF, LOW);
      digitalWrite(pinG, LOW);

      /*
       * Column
       */
      pinMode(A2, OUTPUT);
      pinMode(9, OUTPUT);
      
      
      }
     
      void Update()
      {

        unsigned long currentMillis = millis(); 
        // check to see if it's time to change the state of the LED
        if(currentMillis - digitMillis == 3){
          digitalWrite(D1, LOW);
          digitalWrite(D2, LOW);
          digitalWrite(D3, LOW);
          digitalWrite(D4, LOW);
          digitalWrite(A2, LOW);
          digitalWrite(9, LOW);
        }
        int cnt = 4;
               
        if((currentMillis - previousMillis == cnt))
        {
            digitalWrite(D1, HIGH);
            if(number > 999){
               shownumber((number / 1000) % 10); 
            } else{
               shownumber(0); 
            }
           
            digitMillis = currentMillis;
        }
        else if ((currentMillis - previousMillis == cnt + cnt))
        {
            digitalWrite(D2, HIGH);
            if(number > 99){
               shownumber((number / 100) % 10); 
            } else{
               shownumber(0);
            }
            digitMillis = currentMillis;
        }
        else if ((currentMillis - previousMillis == cnt + cnt*2))
        {
            digitalWrite(D3, HIGH);
            if(number > 9){
               shownumber((number / 10) % 10);  
            } else{
               shownumber(0); 
            }
            digitMillis = currentMillis;
        }
        else if ((currentMillis - previousMillis == cnt + cnt*3))
        {
            digitalWrite(D4, HIGH);
            shownumber(number % 10);
            digitMillis = currentMillis;
        }
        else if (currentMillis - previousMillis > cnt + cnt*4)
        {
            digitalWrite(A2, HIGH);
            digitalWrite(9, HIGH);
            previousMillis = currentMillis;
            digitMillis = currentMillis;
            
        }
      }

      void shownumber(int n){
        digitalWrite(pinA, HIGH);
        digitalWrite(pinB, HIGH);
        digitalWrite(pinC, HIGH);
        digitalWrite(pinD, HIGH);
        digitalWrite(pinE, HIGH);
        digitalWrite(pinF, HIGH);
        digitalWrite(pinG, HIGH);
        switch(n){
          case 0:
            digitalWrite(pinA, LOW);
            digitalWrite(pinB, LOW);
            digitalWrite(pinC, LOW);
            digitalWrite(pinD, LOW);
            digitalWrite(pinE, LOW);
            digitalWrite(pinF, LOW);
            digitalWrite(pinG, HIGH);
            break;
          case 1:
            digitalWrite(pinA, HIGH);
            digitalWrite(pinB, LOW);
            digitalWrite(pinC, LOW);
            digitalWrite(pinD, HIGH);
            digitalWrite(pinE, HIGH);
            digitalWrite(pinF, HIGH);
            digitalWrite(pinG, HIGH);
            break;
          case 2:
            digitalWrite(pinA, LOW);
            digitalWrite(pinB, LOW);
            digitalWrite(pinC, HIGH);
            digitalWrite(pinD, LOW);
            digitalWrite(pinE, LOW);
            digitalWrite(pinF, HIGH);
            digitalWrite(pinG, LOW);
            break;
          case 3:
            digitalWrite(pinA, LOW);
            digitalWrite(pinB, LOW);
            digitalWrite(pinC, LOW);
            digitalWrite(pinD, LOW);
            digitalWrite(pinE, HIGH);
            digitalWrite(pinF, HIGH);
            digitalWrite(pinG, LOW);
            break;
          case 4:
            digitalWrite(pinA, HIGH);
            digitalWrite(pinB, LOW);
            digitalWrite(pinC, LOW);
            digitalWrite(pinD, HIGH);
            digitalWrite(pinE, HIGH);
            digitalWrite(pinF, LOW);
            digitalWrite(pinG, LOW);
            break;
          case 5:
            digitalWrite(pinA, LOW);
            digitalWrite(pinB, HIGH);
            digitalWrite(pinC, LOW);
            digitalWrite(pinD, LOW);
            digitalWrite(pinE, HIGH);
            digitalWrite(pinF, LOW);
            digitalWrite(pinG, LOW);
            break;
          case 6:
            digitalWrite(pinA, LOW);
            digitalWrite(pinB, HIGH);
            digitalWrite(pinC, LOW);
            digitalWrite(pinD, LOW);
            digitalWrite(pinE, LOW);
            digitalWrite(pinF, LOW);
            digitalWrite(pinG, LOW);
            break;
          case 7:
            digitalWrite(pinA, LOW);
            digitalWrite(pinB, LOW);
            digitalWrite(pinC, LOW);
            digitalWrite(pinD, HIGH);
            digitalWrite(pinE, HIGH);
            digitalWrite(pinF, HIGH);
            digitalWrite(pinG, HIGH);
            break;
          case 8:
            digitalWrite(pinA, LOW);
            digitalWrite(pinB, LOW);
            digitalWrite(pinC, LOW);
            digitalWrite(pinD, LOW);
            digitalWrite(pinE, LOW);
            digitalWrite(pinF, LOW);
            digitalWrite(pinG, LOW);
            break;
          case 9:
            digitalWrite(pinA, LOW);
            digitalWrite(pinB, LOW);
            digitalWrite(pinC, LOW);
            digitalWrite(pinD, LOW);
            digitalWrite(pinE, HIGH);
            digitalWrite(pinF, LOW);
            digitalWrite(pinG, LOW);
            break;
          default:
            digitalWrite(pinA, HIGH);
            digitalWrite(pinB, HIGH);
            digitalWrite(pinC, HIGH);
            digitalWrite(pinD, HIGH);
            digitalWrite(pinE, HIGH);
            digitalWrite(pinF, HIGH);
            digitalWrite(pinG, LOW);
            break;
        }
      }

      
    };

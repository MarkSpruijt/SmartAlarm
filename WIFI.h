  #include <SoftwareSerial.h>
    class WIFI
    {
      // Class Member Variables
      // These are initialized at startup
      
      // These maintain the current state
      unsigned long previousMillis;   // will store last time LED was updated
      bool working = true;
      SoftwareSerial ESPSerial;
      
      // Constructor - creates a Countdown 
      // and initializes the member variables and state
      public:
      WIFI()
/      {
        ESPSerial = new SoftwareSerial(3,2);
        Serial.begin(115200);
        previousMillis = millis();
      }
     
      void Update()
      {
        // check to see if it's time to change the state of the LED
        unsigned long currentMillis = millis();
        if(working){
          if(currentMillis - previousMillis == 4000){
            String cmd = "AT+CIPSTART=\"TCP\",\"";  //make this command: AT+CPISTART="TCP","146.227.57.195",80
            cmd += "www.markspruijt.nl";
            cmd += "\",80";
            ESPSerial.println(cmd);
            Serial.println("Linked");
          }
          if(currentMillis - previousMillis == 6000){
            cmd =  "GET / HTTP/1.0\r\n";  //construct http GET request
            cmd += "Host: www.markspruijt.nl\r\n\r\n";
            ESPSerial.print("AT+CIPSEND=");
            ESPSerial.println(cmd.length());
            Serial.println("Send size");
          }
          if(currentMillis - previousMillis == 6100){
            if(ESPSerial.find(">"))    //prompt offered by esp8266
            {
             // Serial.println("found > prompt - issuing GET request");  //a debug message
              ESPSerial.println(cmd);  //this is our http GET request
              Serial.println("Send request");
            }
            else
            {
              ESPSerial.println("AT+CIPCLOSE");  //doesn't seem to work here?
              Serial.println("No '>' prompt received after AT+CPISEND");
            }
          }
          if(currentMillis - previousMillis == 7100){
            if (ESPSerial.find("Date: ")) //get the date line from the http header (for example)
            {
              for (int i=0;i<31;i++)  //this should capture the 'Date: ' line from the header
              {
                if (ESPSerial.available())  //new cahracters received?
                {
                  char c=ESPSerial.read();  //print to console
                  Serial.write(c);
                }
                else i--;  //if not, keep going round loop until we've got all the characters
              }
            }
            ESPSerial.println("AT+CIPCLOSE");
            working = false;
          }
        }
      }

      
    };

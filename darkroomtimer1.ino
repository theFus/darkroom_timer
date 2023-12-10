// C++ code
//                                                                                                                                                                                                                                                                                                                            
# include "DFRobot_LedDisplayModule.h"

DFRobot_LedDisplayModule LED(&Wire, 0x48);



int CountdownSecs = 0;

int DisplayBrightness = 0;

int workLoop = 0;



void setup()
{
  digitalWrite(LED_BUILTIN, LOW);
  pinMode(A0, INPUT);
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(6, INPUT);
  pinMode(12, OUTPUT);
  pinMode(3, INPUT);
  pinMode(A1, INPUT);
  pinMode(11, OUTPUT);
  Serial.begin(115200);
  
  while(LED.begin(LED.e4Bit) != 0)
  {
    Serial.println("Failed to initialize the chip , please confirm the chip connection!");
    delay(1000);
  }
 LED.setDisplayArea(2,3);

 LED.print("Y","O");

 delay(1000);

 LED.setDisplayArea(2,3); 

 LED.print("F","U");

 delay(1000);

 LED.setDisplayArea(2,3);
 
 

}

void loop()
{
  digitalWrite(LED_BUILTIN, LOW);
  digitalWrite(11, LOW); 
  
  if (CountdownSecs < 10) { LED.setDisplayArea(3); 
  }
  if (CountdownSecs > 10) { LED.setDisplayArea(2,3); 
  }  
  if (CountdownSecs > 100) { LED.setDisplayArea(2,3,4); 
  }  
  
  DisplayBrightness = map(analogRead(A1), 0, 1023, 0, 7);
  CountdownSecs = map(analogRead(A0), 0, 1023, 0, 99);
  LED.print(CountdownSecs);
    
  
  
  
  if (digitalRead(6) == HIGH) {
    workLoop += 1 ;
    delay(1000); // Wait for 200 millisecond(s)
    while (workLoop == 1) {
      
      LED.setDisplayArea(2,3);
      LED.print("-","-");
      digitalWrite(11, HIGH);
      digitalWrite(LED_BUILTIN, HIGH);
      tone(12, 29, 1000); 
      delay(1000); 
      if (digitalRead(6) == HIGH) {
        digitalWrite(11, LOW);        
        workLoop -= 1 ;
        delay(3000); // Wait for 500 millisecond(s)
        
      }      
    }
  }
    
  if (digitalRead(3) == HIGH) {
    while (CountdownSecs > 0) {
      if (CountdownSecs < 10) { LED.setDisplayArea(3); 
       }
      if (CountdownSecs > 10) { LED.setDisplayArea(2,3); 
       }  
      if (CountdownSecs > 100) { LED.setDisplayArea(2,3,4); 
      }  
      digitalWrite(LED_BUILTIN, HIGH);
      digitalWrite(11, HIGH);
      LED.print(CountdownSecs);
      tone(12, 29, 1000); // play tone 10 (A#0 = 29 Hz)
      delay(1000); // Wait for 1000 millisecond(s)
      CountdownSecs = (CountdownSecs - 1);
    }
  }
  
  if (DisplayBrightness == 0) {
    LED.setBrightness(1);
  }
  if (DisplayBrightness == 1) {
    LED.setBrightness(2);
  }
  if (DisplayBrightness == 2) {
    LED.setBrightness(3);
  }
  if (DisplayBrightness == 3) {
    LED.setBrightness(4);
  }
  if (DisplayBrightness == 4) {
    LED.setBrightness(5);
  }
  if (DisplayBrightness == 5) {
    LED.setBrightness(6);
  }
  if (DisplayBrightness == 6) {
    LED.setBrightness(7);
  }
  if (DisplayBrightness == 7) {
    LED.setBrightness(8);
  }
   
}
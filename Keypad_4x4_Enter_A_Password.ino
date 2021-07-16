//KeyPad 4x4

#include <Keypad.h>
#include <String.h>

const byte numRows= 4;
const byte numCols= 4;

String pass;

char keymap[numRows][numCols]= { {'1', '2', '3', 'A'},
{'4', '5', '6', 'B'},
{'7', '8', '9', 'C'},
{'*', '0', '#', 'D'} };

byte rowPins[numRows] = {9,8,7,6}; //Rows 0 to 3 

byte colPins[numCols]= {5,4,3,2}; //Columns 0 to 3 

Keypad myKeypad= Keypad(makeKeymap(keymap), rowPins, colPins, numRows, numCols); 

void setup() {

    Serial.begin(9600); 
    int k;
    for(int k=0;k<3;k++) //only 3 chances for correct key
        { 
          Serial.print("Enter 4-digit key:");
          pass="";
          for(int i=0;i<4;i++) //length of the key is 4
              {
                  char keypressed = myKeypad.getKey();
                  while(keypressed == NO_KEY)    
                      {
                        keypressed = myKeypad.getKey();
                      }
                  if (keypressed != NO_KEY)
                    {
                    pass+=keypressed;
                    Serial.print(keypressed);
                    }
              }
            if(pass=="1090"){
            Serial.println("Correct key");
            k=3;
            //loop();
            }
            else Serial.println("False key");          
        }
        
        if(k==3 || pass!="1090"){
        Serial.println("You have no more chances.");
        while(1);
        }
}



void loop() {
  Serial.print("If key is correct, continue with code here...");
  delay(10000);
}

#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
int button1 = 13;  
int button2 = 9;  
int button3 = 8;  
int button4 = 6;  
int button5 = 7;  
void setup() 
{
  Serial.begin(9600); // nel caso serva
  lcd.begin(16, 2);
  pinMode(button1,INPUT);
  pinMode(button2,INPUT);
  pinMode(button3,INPUT);
  pinMode(button4,INPUT);
  pinMode(button5,INPUT);
}

void loop() 
{


}

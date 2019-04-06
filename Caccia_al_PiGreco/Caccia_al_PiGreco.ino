#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
int button1 = 13;  
int button2 = 9;  
int button3 = 8;  
int button4 = 7;  
int button5 = 6;  
void setup() 
{
  Serial.begin(9600); // nel caso serva
  lcd.begin(16, 2);
  pinMode(button1,INPUT);
  pinMode(button2,INPUT);
  pinMode(button3,INPUT);
  pinMode(button4,INPUT);
  pinMode(button5,INPUT);
  Serial.println("0"); 
    lcd.setCursor(0,0);
  lcd.print("Test del display");
  lcd.setCursor(0,1);
  lcd.print("Test del display");

}

void loop() 
{
Inizio();

}
void Inizio()
{ 
  
  while (digitalRead(button1) == HIGH)
  {
   Serial.println("1"); 
  }
    while (digitalRead(button2) == HIGH)
  {
   Serial.println("2"); 
  }
    while (digitalRead(button3) == HIGH)
  {
   Serial.println("3"); 
  }
    while (digitalRead(button4) == HIGH)
  {
   Serial.println("4"); 
  }
    while (digitalRead(button5) == HIGH)
  {
   Serial.println("5"); 
  }
}

#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
int button1 = 6;
int button2 = 7;
int button3 = 8;
int button4 = 9;
int button5 = 13;
int vittoria =0;

int risF;
int continua = 0;
int Npartita = 1;
int ButtDisp[5][2] = {{6, 0}, {7, 1}, {8, 2}, {9, 3}, {13, 4}};

byte Cuore[8] =
{
  B00000, B01010, B11111, B11111, B11111, B01110, B00100, B00000
};
byte PiGreco[8] =
{
  B11111, B01010, B01010, B01010, B01010, B01010, B01010, B10000
};
byte Omega[8] =
{
  B00000, B01110, B10001, B10001, B10001, B01010, B11011, B00000
};
byte Smile[8] =
{
  B00000, B10001, B00000, B00000, B10001, B01110, B00000
};


void setup()
{
  Serial.begin(9600); // nel caso serva
  lcd.begin(16, 2);
  pinMode(button1, INPUT);
  pinMode(button2, INPUT);
  pinMode(button3, INPUT);
  pinMode(button4, INPUT);
  pinMode(button5, INPUT);
  risF = 0;
  lcd.createChar(1, Cuore); //byte(0) per scriverlo
  lcd.createChar(2, PiGreco);
  lcd.createChar(3, Omega);
  lcd.createChar(4, Smile);
}

void loop()
{
  Inizio();
  //Istruzioni();
  while (continua == 0)
  {
    Partita();
    Npartita++;
    Continuare();
  }
}
void Inizio()
{
  continua = 0;
  lcd.setCursor(0, 0);
  lcd.print("< Caccia al    >");
  lcd.setCursor(12, 0);
  lcd.write(byte(2));
  lcd.setCursor(0, 1);
  lcd.print("Premi un        ");
  delay(1500);
  lcd.setCursor(0, 1);
  lcd.print("pulsante per    ");
  delay(1500);
  lcd.setCursor(0, 1);
  lcd.print("iniziare        ");
  delay(1500);
  lcd.setCursor(0, 1);
  lcd.print("                ");

  while (digitalRead(button1) == LOW && digitalRead(button2) == LOW && digitalRead(button3) == LOW && digitalRead(button4) == LOW && digitalRead(button5) == LOW)
  {}
  lcd.setCursor(0, 0);
  lcd.print("Avvio gioco in ");
  lcd.setCursor(0, 1);
  lcd.print("corso          ");
  delay(1000);
}
void Istruzioni()
{
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("<  Ist. Gioco  >");
  lcd.setCursor(0, 1);
  lcd.print("Lo scopo e'     ");
  delay(1250);
  lcd.setCursor(0, 1);
  lcd.print("premere il      ");
  delay(1250);
  lcd.setCursor(0, 1);
  lcd.print("pulsante che    ");
  delay(1250);
  lcd.setCursor(0, 1);
  lcd.print("corrisponde al  ");
  lcd.setCursor(15, 1);
  lcd.write(byte(2));
  delay(1250);
  lcd.setCursor(0, 1);
  lcd.print("attenzione!.....");
  delay(1250);
  lcd.setCursor(0, 1);
  lcd.print("non devi premere");
  delay(1250);
  lcd.clear();
  lcd.setCursor(0, 1);
  lcd.print("il simbolo omega");
  lcd.setCursor(14, 0);
  lcd.write(byte(3));
  delay(1500);
  lcd.setCursor(0, 0);
  lcd.print("<  Ist. Gioco  >");
  lcd.setCursor(0, 1);
  lcd.print("perche' senno'  ");
  delay(1250);
  lcd.clear();
  lcd.setCursor(0, 1);
  lcd.print("perderai vita   ");
  lcd.setCursor(12, 0);
  lcd.write(byte(1));
  lcd.setCursor(13, 0);
  lcd.write(byte(1));
  lcd.setCursor(14, 0);
  lcd.write(byte(1));
  delay(1500);
  lcd.setCursor(0, 0);
  lcd.print("<  Ist. Gioco  >");
  lcd.setCursor(0, 1);
  lcd.print("ne hai 3 in tot ");
  delay(1250);
  lcd.clear();
  lcd.setCursor(0, 1);
  lcd.print("+ quelle extra  ");
  lcd.setCursor(14, 0);
  lcd.write(byte(4));
  delay(1250);
  lcd.setCursor(0, 1);
  lcd.print("max 5 vite     ");
  delay(1250);
}
void Partita()
{
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Avvio partita ");
  lcd.setCursor(0, 1);
  lcd.print("in corso      ");
  delay(1000);


  int vita = 3;
  int omega = 0;
  int pigreco = 0;
  int jolly = 0;
  int contatore = 1;
  int tempo = 4000;
  bool presjolly = false;

  while (vita > 0)
  {
     if (contatore == 19)
    {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("COMPLIMENTI   ");
      lcd.setCursor(0, 1);
      lcd.print("HAI VINTO!!!  ");
      vittoria ++;
      delay(1000);
      return;
    }
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Partita       ");
      lcd.setCursor(13, 0);
      lcd.print(contatore);
      delay(750);
      contatore++;
      
   
    if (!presjolly)
    {
      bool controllo = true; // assegnazione posizione
      while (controllo)
      {
        omega = random(0, 4);
        pigreco = random(0, 4);
        if (omega != pigreco)
        {
          controllo = false;
        }
      }
      if (vita > 5) // assegna vita
      {
        vita = 5;
      }
      lcd.clear();
      for (int i = 0; i < vita; i++)
      {
        lcd.setCursor(15 - i, 0);
        lcd.write(byte(1));
      }

     stampaCARATTERE(pigreco, 2);

      stampaCARATTERE(omega, 3);

      while (digitalRead(button1) == LOW && digitalRead(button2) == LOW && digitalRead(button3) == LOW && digitalRead(button4) == LOW && digitalRead(button5) == LOW) {}

      // da qui aspetta input da parte dell'utente  || da sistemare
      
      if (digitalRead(button1) == HIGH) 
      {
        delay(200);
        Serial.println("1");
        if(omega==0)
        {
         vita=vita-2;
        }
        else if(pigreco!=0)
        {
          vita=vita-1;
        }
      }
      if (digitalRead(button2) == HIGH) 
      {
        delay(200);
        if(omega==1)
        {
         vita=vita-2;
        }
        else if(pigreco!=1)
        {
          vita=vita-1;
        }
      }
      if (digitalRead(button3) == HIGH) 
      {
        delay(200);
        if(omega==2)
        {
         vita=vita-2;
        }
        else if(pigreco!=2)
        {
          vita=vita-1;
        }
      }
      if (digitalRead(button4) == HIGH) 
      {
        delay(200);
        if(omega==3)
        {
         vita=vita-2;
        }
        else if(pigreco!=3)
        {
          vita=vita-1;
        }
      }
      if (digitalRead(button5) == HIGH) 
      {
         delay(200);
         if(omega==4)
        {
         vita=vita-2;
        }
        else if(pigreco!=4)
        {
          vita=vita-1;
        }
      }

    }
    
    
  }

}

void Continuare()
{
  lcd.clear();
  if (vittoria = 0)
  {
  lcd.setCursor(0, 0);
  lcd.print("Ahia,hai perso");
  lcd.setCursor(0, 1);
  lcd.print("vuoi riprovare");
  delay(1000);
  lcd.setCursor(0, 1);
  lcd.print("a vincere?    ");
  delay(1000);
  }
  lcd.setCursor(0, 0);
  lcd.print("btn1 - Riprova");
  lcd.setCursor(0, 1);
  lcd.print("btn2 - Riavvio");
  while (digitalRead(button1) == LOW && digitalRead(button2) == LOW)
  {}
  if (digitalRead(button2) == HIGH) 
  {
    continua++;
  }
}

void stampaCARATTERE(int carattere, int numByte)
{
   if (carattere == 0) // visualizzatore display
      {
        lcd.setCursor(1, 1); lcd.write(byte(numByte));
      }
      else if (carattere == 1)
      {
        lcd.setCursor(4, 1); lcd.write(byte(numByte));
      }
      else if (carattere == 2)
      {
        lcd.setCursor(7, 1); lcd.write(byte(numByte));
      }
      else if (carattere == 3)
      {
        lcd.setCursor(10, 1); lcd.write(byte(numByte));
      }
      else if (carattere == 4)
      {
        lcd.setCursor(13, 1); lcd.write(byte(numByte));
      }
}

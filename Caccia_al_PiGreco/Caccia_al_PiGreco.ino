#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
int button1 = 6;
int button2 = 7;
int button3 = 8;
int button4 = 9;
int button5 = 13;
int vittoria = 0;
int risF;
int continua = 0;
int Npartita = 1;
bool presojolly = false;
int vita;
int tempo = 5000;
int tt;
int dt;
int record=0;
byte Cuore[8] =
{B00000, B01010, B11111, B11111, B11111, B01110, B00100, B00000};
byte PiGreco[8] =
{B11111, B01010, B01010, B01010, B01010, B01010, B01010, B10000};
byte Omega[8] =
{B00000, B01110, B10001, B10001, B10001, B01010, B11011, B00000};
byte Smile[8] =
{B00000, B10001, B00000, B00000, B10001, B01110, B00000};

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
  inizio();
  //istruzioni();
  while (continua == 0)
  {
    partita();
    Npartita++;
    continuare();
  }
}
void inizio()
{
  continua = 0;
  lcd.setCursor(0, 0);
  lcd.print("< Caccia al    >");
  lcd.setCursor(12, 0);
  lcd.write(byte(2));
  lcd.setCursor(0, 1);
  lcd.print("Premi un        ");
  delay(750);
  lcd.setCursor(0, 1);
  lcd.print("pulsante per    ");
  delay(750);
  lcd.setCursor(0, 1);
  lcd.print("iniziare        ");
  delay(750);
  lcd.setCursor(0, 1);
  lcd.print("                ");

  while (digitalRead(button1) == LOW && digitalRead(button2) == LOW && digitalRead(button3) == LOW && digitalRead(button4) == LOW && digitalRead(button5) == LOW)
  {}
  lcd.setCursor(0, 0);
  lcd.print("Avvio gioco in ");
  lcd.setCursor(0, 1);
  lcd.print("corso          ");
  delay(750);
}
void istruzioni()
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
void partita()
{
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Avvio partita ");
  lcd.setCursor(0, 1);
  lcd.print("in corso      ");
  delay(1000);

  vita = 3;
  int omega = 0;
  int pigreco = 0;
  int contatore = 1;
  int tempo = 4000;
  int bkpigreco = -1;
  int bkomega = -1;

  while (vita > 0)
  {
    bool presjolly = false;
    int jolly;
    if (contatore == 19)
    {
      if (contatore>record)
      {
        record = vita;
      }
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Record:");
      lcd.setCursor(15, 0);
      lcd.print(record);
      lcd.setCursor(0, 1);
      lcd.print("Partita:");
      lcd.setCursor(15, 1);
      lcd.print(vita);
      delay(1250);
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("COMPLIMENTI   ");
      lcd.setCursor(0, 1);
      lcd.print("HAI VINTO!!!  ");
      vittoria ++;
      delay(1250);
      return;
    }
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Livello       ");
    lcd.setCursor(13, 0);
    lcd.print(contatore);
    delay(600);

    if (contatore == 6 || contatore == 12 || contatore == 18)
    {
      Serial.write("r");
      presjolly = true;
    }

    bool controllo = true; // assegnazione posizione
    while (controllo)
    {
      omega = random(0, 5);
      pigreco = random(0, 5);
      if (omega != pigreco && omega != bkomega && pigreco != bkpigreco)
      {
        controllo = false;
      }
    }

    if (presjolly == true)
    {
      controllo = true;
      while (controllo)
      {
        jolly = random(0, 5);
        if ( jolly != pigreco && jolly != omega)
        {
          controllo = false;
        }
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

    if (presjolly == true)
    {
      Serial.write("s");
      stampaCARATTERE(jolly, 4);
    }
    tt = millis();
    double tempo1 = false;

    while (digitalRead(button1) == LOW && digitalRead(button2) == LOW && digitalRead(button3) == LOW && digitalRead(button4) == LOW && digitalRead(button5) == LOW) {}
    dt = millis();
    if (dt - tt > tempo && presjolly == false)
    {
      vita--;
      lcd.setCursor(0, 0);
      lcd.print("Tempo!!");
      delay(500);
      tempo1 == true;
    }
    button (0, button1, omega, pigreco, jolly, presjolly, tempo1);
    button (1, button2, omega, pigreco, jolly, presjolly, tempo1);
    button (2, button3, omega, pigreco, jolly, presjolly, tempo1);
    button (3, button4, omega, pigreco, jolly, presjolly, tempo1);
    button (4, button5, omega, pigreco, jolly, presjolly, tempo1);

    if (presjolly == true && tempo1 == false)
    {
      while (digitalRead(button1) == LOW && digitalRead(button2) == LOW && digitalRead(button3) == LOW && digitalRead(button4) == LOW && digitalRead(button5) == LOW) {}
      dt = millis();
      if (dt - tt > tempo)
      {
        vita--;
        lcd.setCursor(0, 0);
        lcd.print("Tempo!!");
        delay(500);
        tempo1 == true;
      }
      button (0, button1, omega, pigreco, jolly, false, tempo1);
      button (1, button2, omega, pigreco, jolly, false, tempo1);
      button (2, button3, omega, pigreco, jolly, false, tempo1);
      button (3, button4, omega, pigreco, jolly, false, tempo1);
      button (4, button5, omega, pigreco, jolly, false, tempo1);
    }
    bkpigreco = pigreco;
    bkomega = omega;
    contatore++;
    tempo = tempo - 200;
  }
}

void continuare()
{
  lcd.clear();
  if (vittoria < 1)
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
  if (carattere == 0)
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

int button (int num, int button, int omega1, int pigreco1, int jolly1, bool presjolly1, double tempo1)
{
  if (digitalRead(button) == HIGH && tempo1 == false)
  {
    delay(200);
    if (omega1 == num)
    {
      vita = vita - 2;
    }
    else if (pigreco1 != num && jolly1 != num)
    {
      vita--;
    }
    else if (presjolly1 == true && jolly1 == num)
    {
      presojolly = true;
      vita++;
    }
  }
}

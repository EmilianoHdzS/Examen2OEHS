#include <LiquidCrystal.h>

double fuerza=0.0;
double masa=0.0;
double r=0.0;
double g=9.81;
float in=0.0;
float out=0.0;

LiquidCrystal lcd(12,11,5,4,3,2);

void setup()
{
  lcd.begin(16, 2);
  pinMode(A0,INPUT);
  Serial.begin(1000);
}

void loop()
{
  in=(analogRead(A0));
  out=(5*in)/1023;
  r=10*((5/out)-1);
 
  if(in<481)
  {
     fuerza=pow((r/3.6295),-1.992031873);
     if(fuerza<0)
     {
      fuerza+.1;
     }
    else
    {
      fuerza=fuerza;
    }
  }
  else
  {
 fuerza=pow(r/5.81,-1.45782696);
  }
 
  masa=((fuerza/g)*1000);
  lcd.clear();
  lcd.setCursor(1,0);
  lcd.print("Fuerza:");
  lcd.print(fuerza,3);
  lcd.print("N");
  lcd.setCursor(3,2);
  lcd.print("Peso:");
  lcd.print(masa,2);
  lcd.print("g");
  delay(1000);
  lcd.clear();
}

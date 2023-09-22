#include <LiquidCrystal.h>

LiquidCrystal lcd_1(12, 11, 5, 4, 3, 2);

#define trig 0 
#define echo 1


void setup()
{
  pinMode(trig,OUTPUT);
  pinMode(echo,INPUT);
  digitalWrite(trig,LOW);
  lcd_1.begin(16, 2);
  lcd_1.setCursor(0,0);
  lcd_1.print("Distancia");     
}

void loop()
{
  long t; //tiempo
  long d; //dist 
  digitalWrite(trig,HIGH);
  delayMicroseconds(10);
  digitalWrite(trig,LOW);
  t = pulseIn(echo,HIGH);
  d = t/58.2; // t/v(dathasset)

  
  lcd_1.setCursor(0, 1);
  lcd_1.print(d + String(" cm "));
  delay(50);
}
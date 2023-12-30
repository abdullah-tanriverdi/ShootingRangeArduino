#include <Servo.h>
#include <Adafruit_NeoPixel.h>

#define PIN        2
#define NUMPIXELS 30

Servo HedefAServo;
Servo HedefBServo;
Servo HedefCServo;
Servo HedefDServo;

int skor = 0;
int sayac = 0;

unsigned long ilkZaman;
unsigned long OncekiZaman = 0;

Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
#define DELAYVAL 5

void setup(){
  pinMode(2,OUTPUT);
  HedefAServo.attach(3);
  HedefBServo.attach(5);
  HedefCServo.attach(6);
  HedefDServo.attach(9);
  randomSeed(analogRead(4));
  pixels.begin();
  pixels.show();
}

void loop(){
  delay(5000);
  ilkZaman = millis();
  oyun();
}

void oyun(){
while ((millis()-ilkZaman)<3000)
{
  int c=(millis()-ilkZaman)/1000;
pixels.setPixelColor(c,pixels.Color(0,0, 150));
  pixels.show();
HedefAServo.write(15);
HedefBServo.write(140);
HedefCServo.write(140);
HedefDServo.write(140);
OncekiZaman = millis();
int a = random(1,5);
if (a == 1){
  while (analogRead(0) < 900){
    HedefAServo.write(110);
    if((millis()-OncekiZaman) > 1000)
  oyun();
  } skor++;  kontrol();
}
if (a == 2) {
  while (analogRead(1) < 900){
    HedefBServo.write(10);
    if ((millis()- OncekiZaman) > 1000)
  oyun();  
  }skor++;  kontrol();
}
if (a == 3){
  while (analogRead(2) <900){
    HedefCServo.write(10);
    if((millis()- OncekiZaman)>1000)
  oyun();  
  }skor++;  kontrol();
}

if(a == 4){
  while (analogRead(3) <900){
    HedefDServo.write(10);
    if((millis()- OncekiZaman) > 1000)
  oyun();
  }skor++;  kontrol();
}

}sonSkor();

}

void kontrol(){
  if ((millis()- OncekiZaman) > 1000){
    pixels.setPixelColor(sayac,pixels.Color(150,0, 0));
    pixels.show();
    sayac++;
    if(sayac == 30){
      sonSkor();
    }
    else{oyun();}
  } else oyun();
}

void sonSkor(){
  pixels.clear();
  for (int y = 0; y<skor; y++)
  {
    pixels.setPixelColor(y, pixels.Color(0, 150, 0));
    pixels.show();
    delay(250);
  }

  pixels.clear();
  for (int y = 0; y < skor; y++){
    pixels.setPixelColor(y, pixels.Color(150, 0,0));
    pixels.show();
    delay(150);
  }

  pixels.clear();
  for (int y = 0;y < skor; y++){
    pixels.setPixelColor(y,pixels.Color(0, 0,150));
    pixels.show();
    delay(50);
  }
  delay(1000);
  sayac=0;
  skor=0;
}



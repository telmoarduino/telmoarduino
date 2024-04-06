/*Medir la distancia co ultrasonidos y mostrarla en el LCD y si es menor que 10 se activa el buzzer*/
#include <Wire.h>                 // libreria necesaria para bus I2C
#include <LiquidCrystal_I2C.h>    // libreria necesaria para display I2C 
LiquidCrystal_I2C lcd(0x27,16,2);  // configuramos el LCD en la direccion de bus I2C que es
                                  //    0x27 y el tamaño columnas x filas 16x2
const int EchoPin = 5;
const int TriggerPin = 6;
const int BuzzerPin = 8;

void setup() 
{
  lcd.init();                     // initialza el lcd 
  lcd.backlight();                // enciende la luz de fondo del display
  lcd.setCursor(0,0);             // apuntamos el cursor a la primera fila y primer caracter e

  pinMode(TriggerPin, OUTPUT);//configuramos el
  pinMode(EchoPin, INPUT);
  pinMode (BuzzerPin, OUTPUT);

int cm = ping(TriggerPin, EchoPin);
}
void loop() {
   int cm = ping(TriggerPin, EchoPin);
     Serial.begin(9600);
  Serial.print("Distancia: ");
   Serial.println(cm);
    lcd.print("Distancia:");
   lcd.print(cm);
   lcd.print("cm");
   delay(1000);
   lcd.clear();
   if (cm < 10) {digitalWrite(8, HIGH);}
   if (cm > 10) {digitalWrite(8, LOW);}

}
int ping(int TriggerPin, int EchoPin) {
   long duration, distanceCm;
   
   digitalWrite(TriggerPin, LOW);  //para generar un pulso limpio ponemos a LOW 4us
   delayMicroseconds(4);
   digitalWrite(TriggerPin, HIGH);  //generamos Trigger (disparo) de 10us
   delayMicroseconds(10);
   digitalWrite(TriggerPin, LOW);


   duration = pulseIn(EchoPin, HIGH);  //medimos el tiempo entre pulsos, en microsegundos
   
   distanceCm = duration * 10 / 292/ 2;   //convertimos a distancia, en cm
   return distanceCm;
   
   
}

   

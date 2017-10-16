/*  Sistema anti-intrusos usando 1 Buzzer activo KY-012,
 *  un sensor ultrasonico HC-SR04 y un Arduino UNO. 
 *  
 *  HC - SR04 trigger = Pin 6 
 *  HC - SR04 echo = pin 7
 *  KY-012 = pin 8
 *  
 *  El sistema esta creado sin usar librerias adicionales.
*/

#define trigger 6
#define echo 7
#define buzzer 8

void setup() {
Serial.begin (9600);
pinMode(trigger, OUTPUT);
pinMode(echo, INPUT);
pinMode(buzzer, OUTPUT);
}

void loop() {
int duracion, distancia;
digitalWrite(trigger, HIGH);
delay(1);
digitalWrite(trigger, LOW);
duracion = pulseIn(echo, HIGH);
distancia = (duracion/2) / 29.1;
if (distancia >= 60 || distancia <= 0){
digitalWrite(buzzer, LOW);

}
else {
Serial.println("Intruso detectado");
Serial.println(distancia);
tone(buzzer, 400); // play 400 Hz tone for 500 ms
delay(500);
tone(buzzer, 800); // play 800Hz tone for 500ms
delay(500);
tone(buzzer, 400); // play 400 Hz tone for 500 ms
delay(500);
tone(buzzer, 800); // play 800Hz tone for 500ms
delay(500);
tone(buzzer, 400); // play 400 Hz tone for 500 ms
delay(500);
tone(buzzer, 800); // play 800Hz tone for 500ms
delay(500);
noTone(buzzer);
}
delay(100); // Espera 100 milisegundos y reinicia el codigo
}

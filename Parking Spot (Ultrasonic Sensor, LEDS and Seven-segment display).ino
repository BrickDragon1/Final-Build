//Seven Segment Display
int a = 11; //top
int f = 9; //top left
int b = 12; //top right
int g = 10; //middle
int c= 7; //bottom right
int e = 6; //bottom left
int d = 2; //bottom

//Ultrasonic Sensor
#include <NewPing.h>

#define TRIGGER_PIN  12  
#define ECHO_PIN     11  
#define MAX_DISTANCE 11 

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); // NewPing setup of pins and maximum distance.

void setup(){
//Ultrasonic Sensor
Serial.begin(9600);

//Seven Segment Display
pinMode(a, OUTPUT);
pinMode(b, OUTPUT);
pinMode(c, OUTPUT);
pinMode(d, OUTPUT);
pinMode(e, OUTPUT);
pinMode(f, OUTPUT);
pinMode(g, OUTPUT);
}
//Seven Segment Display
int pins[7] = {a, b, c, d, e, f, g};
void displayNumber(int *number) {
  for (int i = 0; i < 7; i++) {
    digitalWrite(pins[i], number[i]);
  }
}

void Ultrasonic(){
  delay(50);                   
  Serial.print("Ping: ");
  Serial.print(sonar.ping_cm());
  Serial.println("cm");
}
 
void loop(){
//Seven Segment Display
int numberCount = 2;
 
int numbers[numberCount][7] = {
  {1, 1, 1, 1, 1, 1, 0}, // 0
  {0, 1, 1, 0, 0, 0, 0}, // 1
};

Ultrasonic();
 
for (int i = 0; i < numberCount; i++) {
  displayNumber(numbers[i]);
  delay(1000);
}
}
 

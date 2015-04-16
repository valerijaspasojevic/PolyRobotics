#include <dht11.h>
dht11 DHT;  
#define DHT11_PIN 4 // Temperatura
int flame = A5 ; //Detekcija vatre
int val = 0 ; //Promenljiva za detekciju vatre
int value= 0;
byte data; // Solarna ploca
int Relay = 8; //Relay
int solarMax = 80; // Solarna Maksimalna velicina

void setup() { 
  pinMode(Relay, OUTPUT); 
  pinMode (flame, INPUT) ;
  Serial.begin(9600); 
} 

void loop() { 
  int chk; //Temperatura
  chk = DHT.read(DHT11_PIN);
  data = analogRead(0); 
 
  if (data >= solarMax ) {
    digitalWrite(Relay, HIGH);  
   
  } else {
    digitalWrite(Relay, LOW); 
    
  } 
 
  val = analogRead (flame) ;
  
  
  
  //Solarna ploca
  Serial.print("Solar panel = ");
  Serial.println(data);
  
  //Print fire
  if (val == 0) {
     Serial.println("Fire detected!");
  } else {
    Serial.print("");
  }
  
   //Print temperature
  Serial.print("Humidity = ");
  Serial.print(DHT.humidity, 1);
  Serial.print(", Temp = ");
  Serial.println(DHT.temperature,1);
  
   
  delay(1000);
}

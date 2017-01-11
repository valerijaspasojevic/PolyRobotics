#include <dht11.h>
dht11 DHT;  
#define DHT11_PIN 4 
int flame = A5 ;
int val = 0 ;
int value= 0;
byte data; 
int Relay = 8; 
int solarMax = 80; 

void setup() { 
  pinMode(Relay, OUTPUT); 
  pinMode (flame, INPUT) ;
  Serial.begin(9600); 
} 

void loop() { 
  int chk; 
  chk = DHT.read(DHT11_PIN);
  data = analogRead(0); 
 
  if (data >= solarMax ) {
    digitalWrite(Relay, HIGH);  
   
  } else {
    digitalWrite(Relay, LOW); 
    
  } 
 
  val = analogRead (flame) ;
  
  Serial.print("Solar panel = ");
  Serial.println(data);
  
  if (val == 0) {
     Serial.println("Fire detected!");
  } else {
    Serial.print("");
  }
  
  Serial.print("Humidity = ");
  Serial.print(DHT.humidity, 1);
  Serial.print(", Temp = ");
  Serial.println(DHT.temperature,1);
  
   
  delay(1000);
}

#include <ESP8266WiFi.h>

#include <WiFiClient.h>
#include <ThingSpeak.h>
const char * myWriteAPIKey = "VCTXIXX01JJ1V8E7";
const char *ssid =  "OnePlus6T";     
const char *pass =  "123456789"; // Enter your 
unsigned long myChannelNumber = 2134329;
WiFiClient client;

int trigPin = D6;
int echoPin = D7;
int Chocolate=0;
int Icecream=0;

int trig1Pin = D1;
int echo1Pin = D2;
void setup() {
 
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  
  pinMode(trig1Pin, OUTPUT);
  pinMode(echo1Pin, INPUT);
  Serial.begin(115200);
  ThingSpeak.begin(client);
  Serial.println("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, pass);
  while (WiFi.status() != WL_CONNECTED) 
     {
            delay(550);
            Serial.print(".");
     }
      Serial.println("");
      Serial.println("WiFi connected");
}

void loop(){
     Product1();
     Product2();
  }

void Product1(){
delay(500);// reading will be taken after ....miliseconds
Serial.println("\n");
int duration, distance;
    digitalWrite (trigPin, HIGH);
    delayMicroseconds (10);
    digitalWrite (trigPin, LOW);
    duration = pulseIn (echoPin, HIGH);
    distance = (duration/2) / 29.1;
   
    if (distance <23/3) {  // Change the number for long or short distances.
    Icecream=5;
    Serial.println("\n");
    Serial.print(Icecream); 
    Serial.print("  Icecream");
    }
    if (distance >23/3 && distance <35/3) {  // Change the number for long or short distances.
    Icecream=4;
    Serial.println("\n");
    Serial.print(Icecream);
    Serial.print("  Icecream"); 
    }
    if (distance >35/3 && distance <47/3) {  // Change the number for long or short distances.
    Icecream=3;
    Serial.println("\n");
    Serial.print(Icecream);
    Serial.print("  Icecream"); 
    }
    if (distance >47/3 && distance <60/3) {  // Change the number for long or short distances.
    Icecream=2;
    Serial.println("\n");
    Serial.print(Icecream);
    Serial.print("  Icecream"); 
    }
    if (distance >60/3 && distance <70/3) {  // Change the number for long or short distances.
    Icecream=1;
    Serial.println("\n");
    Serial.print(Icecream); 
    Serial.print("  Icecream");
    }
    if(distance >70/3){
    Icecream= 0; 
    Serial.println("\n");    
    Serial.print(Icecream);
    Serial.print("  Icecream");
    }
    ThingSpeak.writeField(myChannelNumber, 1,Icecream, myWriteAPIKey);
 
      }
    
void Product2(){
delay(500);
Serial.println("\n");
int duration, distance;
    digitalWrite (trig1Pin, HIGH);
    delayMicroseconds (10);
    digitalWrite (trig1Pin, LOW);
    duration = pulseIn (echo1Pin, HIGH);
    distance = (duration/2) / 29.1;
   
    if (distance <23/3) {  // Change the number for long or short distances.
    Chocolate=5;
    Serial.println("\n");
    Serial.print(Chocolate);
    Serial.print("Chocolate"); 
    }
    if (distance >23/3 && distance<35/3) {  // Change the number for long or short distances.
    Chocolate=4;
    Serial.println("\n");
    Serial.print(Chocolate); 
    Serial.print("  Chocolate");
    }
    if (distance >35/3 && distance< 47/3) {  // Change the number for long or short distances.
    Chocolate=3;
    Serial.println("\n");
    Serial.print(Chocolate); 
    Serial.print("  Chocolate");
    }
    if (distance >47/3 && distance< 60/3) {  // Change the number for long or short distances.
    Chocolate=2;
    Serial.println("\n");
    Serial.print(Chocolate);
    Serial.print("  Chocolate"); 
    }
    if (distance >60/3 && distance< 70/3) {  // Change the number for long or short distances.
    Chocolate=1;
    Serial.println("\n"); 
    
    Serial.print(Chocolate);
    Serial.print("  Chocolate"); 
    }
    if(distance>70/3){
    Chocolate= 0; 
    Serial.print(Chocolate);
    Serial.print("  Chocolate");
     
    }
    
    ThingSpeak.writeField(myChannelNumber, 2,Chocolate, myWriteAPIKey);

    }

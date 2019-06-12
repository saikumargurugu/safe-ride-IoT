#define BLYNK_PRINT Serial


#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "34f4b3202b33423b8bbbd15c36e41fd4";

// Your WiFi credentials.
// Set password to "" for open networks.

//char ssid[] = "Mokka";
//char pass[] = "9063112299";

char ssid[] = "Gopi";
char pass[] = "loveumom";

//char ssid[] = "sai kumar";
//char pass[] = "123456677";

//char ssid[] = "adminstator";
//char pass[] = "administator";

int mainon= D4;

int start1=D0;
int start2=D1;
int start3=D2;
int start4=D3;
void setup()
{
  // Debug console
  Serial.begin(9600);

  Blynk.begin(auth, ssid, pass);

  pinMode(start1, INPUT);
   pinMode(start2, INPUT);
    pinMode(start3, INPUT);
   pinMode(start4, INPUT);
  // You can also specify server:
  //Blynk.begin(auth, ssid, pass, "blynk-cloud.com", 80);
  //Blynk.begin(auth, ssid, pass, IPAddress(192,168,1,100), 8080);
}

void loop()
{
  int d;
  d= digitalRead(mainon);
  if(d == HIGH){
    Serial.println(",Power");
    }
  int j;
  j=digitalRead(start1);
  if(j == HIGH){
    Serial.println(",front");
    }
  int k;
  k=digitalRead(start3);
  if(k == HIGH){
    Serial.print(",left");
    }
int n;
n= digitalRead(start2);
    if(n== HIGH){
      Serial.print(",Back");
      }
int p;
p= digitalRead(start4);
    if(p== HIGH){
      Serial.print("right");
      }

Blynk.run();
}

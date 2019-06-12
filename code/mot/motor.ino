#include<IRremote.h>

#include<Wire.h>
#include<LiquidCrystal_I2C.h>

const int receiver=22;

#define Button_1 0xFF30CF
#define Button_2 0xFF18E7
#define Button_3 0xFF7A85
#define Button_4 0xFFA25D

int inp=14;
int inp2=16;
int inp1=15;
int inp3=17;


int switchon=19;


int trigPin=11, echoPin= 12;
float duration, distance;



const int IN5 = 2,IN6 = 3,IN7 = 4,IN8 = 7;
 const int en1=5, en2=6;
 int SPEED=0;

 IRrecv irrecv(receiver);
decode_results result;

LiquidCrystal_I2C lcd(0x27, 2,1,0,4,5,6,7,3, POSITIVE);


void setup() {
  // put 
  //your setup code here, to run once:
Serial.begin(9600);

 irrecv.enableIRIn();
          
            lcd.begin(16,2);
            lcd.clear();

  pinMode(switchon , INPUT);

 pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  pinMode(IN5 , OUTPUT);
  pinMode(IN6 , OUTPUT);
  pinMode(IN7 , OUTPUT);
  pinMode(IN8 , OUTPUT);
  pinMode(en1 , OUTPUT);
  pinMode(en2 , OUTPUT);
  
  pinMode(inp, INPUT);
  pinMode(inp2, INPUT);
  pinMode(inp1, INPUT);
  pinMode(inp3, INPUT);
}

void loop() {

 
 
 int b;
b = digitalRead(inp2);

int m;
m=  digitalRead(inp1);

  int c;
c= digitalRead(inp3);

int s;
s= digitalRead(switchon);
Serial.println(s);
 if(s == HIGH) {

int i;
i=digitalRead(inp);
  

 
 // digitalWrite(sup, HIGH);

 digitalWrite(trigPin, LOW);
delayMicroseconds(2);

digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
duration = pulseIn(echoPin, HIGH);
distance= (duration/2)/29.1;
 
 if(i == HIGH && b== LOW && c==LOW && m==LOW){  
  
   Serial.println(i); 
  if(distance < 10){
   SPEED=0;
   Serial.println(SPEED);
   Serial.println(distance);
   Serial.println(distance);
  analogWrite(en1,SPEED);
  analogWrite(en2,SPEED);

  digitalWrite(IN5, HIGH);
  digitalWrite(IN6, LOW);
  digitalWrite(IN7, HIGH);
  digitalWrite(IN8, LOW);
   }
   else if(distance> 10.00 && distance<39.00){
   SPEED=90;
Serial.println(SPEED);
Serial.println(distance);
  analogWrite(en1,SPEED);
  analogWrite(en2,SPEED);

  digitalWrite(IN5, HIGH);
  digitalWrite(IN6, LOW);
  digitalWrite(IN7, HIGH);
  digitalWrite(IN8, LOW);
   }
   
  else if (distance>40){
  SPEED=225;}
  Serial.println(SPEED);
  analogWrite(en1,SPEED);
  analogWrite(en2,SPEED);

  digitalWrite(IN5, HIGH);
  digitalWrite(IN6, LOW);
  digitalWrite(IN7, HIGH);
  digitalWrite(IN8, LOW);
  
  }

  

if(m == HIGH && b== LOW && c==LOW && i==LOW){
  Serial.println(m);
 // digitalWrite(sup1, HIGH);
 
  SPEED=225;
 
  Serial.println(SPEED);
  analogWrite(en1,SPEED);
  analogWrite(en2,SPEED);

  digitalWrite(IN5, LOW);
  digitalWrite(IN6, HIGH);
  digitalWrite(IN7, LOW);
  digitalWrite(IN8, HIGH);
  
  }

 else if((m == LOW) || (i==HIGH && m== HIGH && b== HIGH && c == HIGH )  ){
  SPEED==0;

  
     analogWrite(en1,SPEED);
  analogWrite(en2,SPEED);

  digitalWrite(IN5, HIGH);
  digitalWrite(IN6, LOW);
  digitalWrite(IN7, HIGH);
  digitalWrite(IN8, LOW);
  }

  
  if(m == HIGH && b== HIGH)
  {

  Serial.println(SPEED);
  analogWrite(en1,SPEED);
  analogWrite(en2,20);

  digitalWrite(IN5, LOW);
  digitalWrite(IN6, HIGH);
  digitalWrite(IN7, LOW);
  digitalWrite(IN8, HIGH);
  }

  else if(i== HIGH && b == HIGH)
  {  if(distance < 10){
   SPEED=0;}
   else if(distance>10 && distance<39)
   SPEED=90;
  else if (distance>40){
  SPEED=225;}
    

  Serial.println(SPEED);
  analogWrite(en1,SPEED);
  analogWrite(en2,0);

  digitalWrite(IN5, HIGH);
  digitalWrite(IN6, LOW);
  digitalWrite(IN7, HIGH);
  digitalWrite(IN8, LOW);
  }


  if(m == HIGH && c == HIGH){

  Serial.println(SPEED);
  analogWrite(en1,0);
  analogWrite(en2,SPEED);

  digitalWrite(IN5, LOW);
  digitalWrite(IN6, HIGH);
  digitalWrite(IN7, LOW);
  digitalWrite(IN8, HIGH);
  }

  else if(i == HIGH && c == HIGH)
  {

  Serial.println(SPEED);
  analogWrite(en1,20);
  analogWrite(en2,SPEED);

  digitalWrite(IN5, HIGH);
  digitalWrite(IN6, LOW);
  digitalWrite(IN7, HIGH);
  digitalWrite(IN8, LOW);
  }

}

  
 else if(s== LOW) {
     
     SPEED=0;
     analogWrite(en1,SPEED);
  analogWrite(en2,SPEED);

  digitalWrite(IN5, HIGH);
  digitalWrite(IN6, LOW);
  digitalWrite(IN7, HIGH);
  digitalWrite(IN8, LOW);
    }

  if(irrecv.decode(&result))
           {
           
                Serial.println(result.value, HEX);
                irrecv.resume();
                
                switch(result.value)
                      {
                      case Button_1 :
                            lcd.clear();
                            lcd.setCursor(0,0);
                            lcd.print("Break down");
                            lcd.setCursor(0,1);
                            lcd.print("<--diversion-->");
                            break;
                      
                      case Button_2 :
                             lcd.clear();
                            lcd.setCursor(0,0);
                            lcd.print("MEDICAL EMERGENCY");
                            lcd.setCursor(0,1);
                            lcd.print("<--diversion-->");
                            break;
          
                      case Button_3 :
                             lcd.clear();
                            lcd.setCursor(0,0);
                            lcd.print("TRAFFIC  AHEAD"); 
                            lcd.setCursor(0,1);
                            lcd.print("<--diversion-->") ;
                            break;

                      case Button_4 :
                             lcd.clear();
                             break;
                      
                      default :
                              lcd.print(distance); 
                      }
          }
 
}

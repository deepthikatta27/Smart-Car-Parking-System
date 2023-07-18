#include <LiquidCrystal_I2C.h>
#include <SoftwareSerial.h>
#include <Servo.h>
SoftwareSerial nodemcu(10, 11);
LiquidCrystal_I2C lcd(0x27, 16, 2);
const int trig_1 = 2;
const int echo_1 = 3;
const int trig_2 = 4;
const int echo_2 = 5;

int IRentry=13;
int IRexit=12;

int ser1 = 7;
int ser2 = 8;
Servo servo1;
Servo servo2;
int angle1 = 0;
int angle2 = 0; 

float distanceCM_1 = 0, resultCM_1 = 0;
float distanceCM_2 = 0, resultCM_2 = 0;
long Time_1, Time_2;
float car_1, car_2;
float Dist_1 = 8.0, Dist_2 = 8.0;
int total = 0;

String espsen1,espsen2;
String cdata ="";

void setup()
{
  nodemcu.begin(115200);
  Serial.begin(115200);
  pinMode(trig_1, OUTPUT);
  pinMode(trig_2, OUTPUT);
  pinMode(echo_1, INPUT);
  pinMode(echo_2, INPUT);
  
  pinMode(IRentry,INPUT);
  pinMode(IRexit,INPUT);

  servo1.attach(ser1);
  servo2.attach(ser2);
  
  digitalWrite(trig_1, LOW);
  digitalWrite(trig_2, LOW);
  lcd.begin(16,2);
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print(" IoT CAR PARK");
  Serial.print(" IoT CAR PARK");
  lcd.setCursor(0, 1);
  lcd.print(" MONITOR SYSTEM");
  Serial.println(" MONITOR SYSTEM");
  delay(2000);
  lcd.clear();
}

void loop()
{
  total = 0;
  car_1 = sensor_1();
  car_2 = sensor_2();

   cdata = cdata + espsen1 +"," + espsen2 +",";
   Serial.println(cdata); 
   nodemcu.println(cdata);
   delay(600); 
   cdata = "";
  
  lcd.setCursor(0, 0);
  lcd.print("CAR1:");
  Serial.print("CAR1:");
  if (car_1 <= Dist_1)
  {
    lcd.print("OK ");
    Serial.println("OK");
    espsen1="255";
  }
  else
  {
    total += 1;
    lcd.print("NO ");
    Serial.println("NO");
    espsen1="0";
  }
  lcd.print("CAR2:");
  Serial.print("CAR2:");
  if (car_2 <= Dist_2)
  {
    lcd.print("OK ");
    Serial.println("OK ");
    espsen2="255";
  }
  else
  {
    total += 1;
    lcd.print("NO ");
    Serial.println("NO ");
    espsen2="0";
  }
  lcd.setCursor(0, 1);
  lcd.print("FREE:");
  Serial.print("FREE:");
  lcd.print(total);
  Serial.println(total);
  Entry(total);
  Exit();
  delay(100);
}

float sensor_1(void)
{
  digitalWrite(trig_1, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig_1, LOW);
  Time_1 = pulseIn(echo_1, HIGH);
  distanceCM_1 = Time_1 * 0.034;
  return resultCM_1 = distanceCM_1 / 2;
}

float sensor_2(void)
{
  digitalWrite(trig_2, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig_2, LOW);
  Time_2 = pulseIn(echo_2, HIGH);
  distanceCM_2 = Time_2 * 0.034;
  return resultCM_2 = distanceCM_2 / 2;
}

void Entry(int total){
  if(digitalRead(IRentry)){
    Serial.println("Entry Closed");
  }
  else{
    if(total!=0){
   Serial.println("Entry Opened"); 
    for(angle1 = 0; angle1 < 90; angle1++) {
        servo1.write(angle1);
        delay(15);
    }
    delay(1000);
    for(angle1 = 90; angle1 > 0; angle1--) {
        servo1.write(angle1);
        delay(15);
    }
    }
  }
}

void Exit(void){
  if(digitalRead(IRexit)){
    Serial.println("Exit Closed");
    }
  else{
   Serial.println("Exit Opened"); 
    for(angle2 = 0; angle2 < 90; angle2++) {
        servo2.write(angle2);
        delay(15);
    } 
    delay(1000);
    for(angle2 = 90; angle2 > 0; angle2--) {
        servo2.write(angle2);
        delay(15);
    }
   }
}

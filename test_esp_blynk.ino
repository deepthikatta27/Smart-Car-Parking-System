#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <SoftwareSerial.h>
#define BLYNK_TEMPLATE_ID "TMPLTgYDbMc-"
#define BLYNK_DEVICE_NAME "smart parking"
//#define BLYNK_AUTH_TOKEN "JHu_n5E9nn9_sMVL-ncTVrxwjdzqUPl7"

char auth[] = "JHu_n5E9nn9_sMVL-ncTVrxwjdzqUPl7";

char ssid[] = "ACT101633907900";
char pass[] = "22347260";

BlynkTimer timer;
 
String myString=""; // complete message from arduino, which consistors of sensors data
char rdata; // received characters
 

int led1,led2;


void myTimerEvent()
{
    // You can send any value at any time.
    // Please don't send more that 10 values per second.
    Blynk.virtualWrite(V1, millis() / 1000);

}

void setup()
{
 
  Serial.begin(115200);
 
  Blynk.begin(auth, ssid, pass,"blynk.cloud",80);
 
    timer.setInterval(1000L,sensorvalue1); 
    timer.setInterval(1000L,sensorvalue2); 
  
 
}
 
void loop()
{  
  if (Serial.available() > 0 ) 
  {
    rdata = Serial.read(); 
    myString = myString + rdata; 
    Serial.println(rdata);
    if( rdata == '\n')
    {
    Serial.println(myString); 
     
     String l = getValue(myString, ',', 0);
     String m = getValue(myString, ',', 1);
 
     // these leds represents the leds used in Blynk application
     led1 = l.toInt();
     led2 = m.toInt();
     
     Serial.print(led1); 
     Serial.print(" and ");
     Serial.println(led2);

      myString = "";
    }
    
  }

       Blynk.run();
       timer.run(); 
}
 
void sensorvalue1()
{
  int sdata = led1;
  Blynk.virtualWrite(V5, sdata);
 
}

void sensorvalue2()
{
  int sdata = led2;
  Blynk.virtualWrite(V6, sdata);
 
}
 
 
String getValue(String data, char separator, int index)
{
    int found = 0;
    int strIndex[] = { 0, -1 };
    int maxIndex = data.length() - 1;
 
    for (int i = 0; i <= maxIndex && found <= index; i++) {
        if (data.charAt(i) == separator || i == maxIndex) {
            found++;
            strIndex[0] = strIndex[1] + 1;
            strIndex[1] = (i == maxIndex) ? i+1 : i;
        }
    }
    return found > index ? data.substring(strIndex[0], strIndex[1]) : "";
}

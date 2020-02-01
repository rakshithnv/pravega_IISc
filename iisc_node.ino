#include <FirebaseArduino.h>
#include <Firebase.h>  
#include <FirebaseCloudMessaging.h>  
#include <FirebaseError.h>  
#include <FirebaseHttpClient.h>  
#include <FirebaseObject.h>
#include  <ESP8266WiFi.h>
#include<SoftwareSerial.h>
SoftwareSerial SUART(4, 5); //SRX=Dpin-D2; STX-DPin-D1
//-------------------------
#define FIREBASE_HOST "tuto-1482a.firebaseio.com"
#define FIREBASE_AUTH "AxlFsc2rexQ2QsCBsEuBxhoB74bPBQQqYqcvYxD7"
#define WIFI_SSID "Hotspot"
#define WIFI_PASSWORD "qwerty123"
//--------------------------------------------
String s0,s2,s1;
void setup()
{
  Serial.begin(9600); //enable Serial Monitor
  SUART.begin(115200); //enable SUART Port
WiFi.begin (WIFI_SSID, WIFI_PASSWORD);
   while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print("Connecting.");
  Firebase.begin(FIREBASE_HOST,FIREBASE_AUTH);
}
}
void firebasereconnect()
{
  Serial.println("Trying to reconnect");
    Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  }
void loop()
{
  byte n = SUART.available(); //n != 0 means a character has arrived
  while (n != 0)
  {
  // SUART.read();
    s0 = SUART.readStringUntil(',');
    Serial.print(s0);
    SUART.read();
     s1 = SUART.readStringUntil(' ');
        Serial.print(s1);
   SUART.read();
     s2 = SUART.readStringUntil(',');
        Serial.print(s2);//read character        //show character on Serial Monitor
      Firebase.setString ("ppm",s0);
      Firebase.setString ("EC",s1);
       Firebase.setString ("ph",s2);
       
}
}

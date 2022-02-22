#define BLYNK_PRINT Serial
#include <Wire.h>
#include <LCD.h>
#include <LiquidCrystal_I2C.h>
//LiquidCrystal_I2C lcd(0x3F , 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);
LiquidCrystal_I2C lcd(0x27 , 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
float Volt;
float read1;
// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "JQcmDoY1mw9vLtDRLldNYtRqjxU3rSAy";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "abcde";
char pass[] = "12345678";
int read = A0;

void setup()
{
  // Debug console
  Serial.begin(9600);
    lcd.begin(16,2);
    pinMode(A0,INPUT);
lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Heat Energy Using");
    lcd.setCursor(0,1);
  lcd.print("Battery Charging");
  delay(100);
  Blynk.begin(auth, ssid, pass);
  // You can also specify server:
  //Blynk.begin(auth, ssid, pass, "blynk-cloud.com", 80);
  //Blynk.begin(auth, ssid, pass, IPAddress(192,168,1,100), 8080);
}

void loop()
{
  Blynk.run();
 read1 = analogRead(A0);
 Volt = read1/1670*5;
lcd.clear();
  lcd.setCursor(0,0);
  lcd.print(".Battery Charging.");




  
    lcd.setCursor(0,1);
  lcd.print("Voltage:");
   lcd.setCursor(9,1);
     Serial.print(Volt);

  lcd.print(Volt);
  delay(500);
}

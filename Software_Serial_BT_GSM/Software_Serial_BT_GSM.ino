#include <SoftwareSerial.h>

SoftwareSerial mySerial(2, 3); // RX, TX

void setup() 
{
  mySerial.begin(9600);
  Serial.begin(9600);
}

void loop() 
{ 
  if(mySerial.available() == 1) 
  {
    String val = mySerial.readString();
    Serial.print("Message from Phone: ");
    Serial.println(val);
    if(val == "A")
    {
      Serial.println("AT+CMGF=1");
      delay(1000);
      Serial.println("AT+CMGS=\"+91XXXXXXXXXX\"\r");
      delay(1000);
      Serial.println("Switch 1 is ON now!");
      delay(1000);
      Serial.println((char)26);
      delay(1000);
    }
    if(val == "a")
    {
      Serial.println("AT+CMGF=1");
      delay(1000);
      Serial.println("AT+CMGS=\"+91XXXXXXXXXX\"\r");
      delay(1000);
      Serial.println("Switch 1 is OFF now!");
      delay(1000);
      Serial.println((char)26);
      delay(1000);
    }
  }
}

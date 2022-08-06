#include "FirebaseESP8266.h"
#include <ESP8266WiFi.h>

const char *ssid = "WIFI-NAME";
const char *password = "WIFI-PASSWORD";

int dev1 = 4;
int dev2 = 5;
int dev3 = 12;
int dev4 = 13;
int dev5 = 14;

FirebaseData firebaseData;

void setup()
{
    Serial.begin(9600);
    WiFi.begin(ssid, password);

    pinMode(dev1, OUTPUT);
    pinMode(dev2, OUTPUT);
    pinMode(dev3, OUTPUT);
    pinMode(dev4, OUTPUT);
    pinMode(dev5, OUTPUT);

    //  Device 1 self Test
    digitalWrite(dev1, HIGH);
    delay(200);
    digitalWrite(dev1, LOW);
    ////Device 2 Self test
    digitalWrite(dev2, HIGH);
    delay(200);
    digitalWrite(dev2, LOW);
    ////Device 3 Self Test
    digitalWrite(dev3, HIGH);
    delay(200);
    digitalWrite(dev3, LOW);
    //// Device 4 Self Test
    digitalWrite(dev4, HIGH);
    delay(200);
    digitalWrite(dev4, LOW);
    //// Device 5 Self Test
    digitalWrite(dev5, HIGH);
    delay(200);
    digitalWrite(dev5, LOW);

    while (WiFi.status() != WL_CONNECTED)
    {
        delay(500);
        Serial.print(".");
    }

    Serial.println(".......");
    Serial.println("WiFi Connected....IP Address:");
    Serial.println(WiFi.localIP());

    Firebase.begin("https://iotblink.firebaseio.com/", "XCcw7LURaMjV6r2mmGYupwHQQ9VhCiljl2m3xzMR");
}

void loop()
{

    if (Firebase.getInt(firebaseData, "/a1"))
    {
        if (firebaseData.dataType() == "int")
        {
            int val = firebaseData.intData();
            Serial.print(val);
            if (val == 1)
            {
                digitalWrite(dev1, HIGH);
            }
            else
            {
                digitalWrite(dev1, LOW);
            }
        }
    }
    if (Firebase.getInt(firebaseData, "/a2"))
    {
        if (firebaseData.dataType() == "int")
        {
            int val = firebaseData.intData();
            Serial.print(val);
            if (val == 1)
            {
                digitalWrite(dev2, HIGH);
            }
            else
            {
                digitalWrite(dev2, LOW);
            }
        }
    }
    if (Firebase.getInt(firebaseData, "/a3"))
    {
        if (firebaseData.dataType() == "int")
        {
            int val = firebaseData.intData();
            Serial.print(val);
            if (val == 1)
            {
                digitalWrite(dev3, HIGH);
            }
            else
            {
                digitalWrite(dev3, LOW);
            }
        }
    }
    if (Firebase.getInt(firebaseData, "/a4"))
    {
        if (firebaseData.dataType() == "int")
        {
            int val = firebaseData.intData();
            Serial.print(val);
            if (val == 1)
            {
                digitalWrite(dev4, HIGH);
            }
            else
            {
                digitalWrite(dev4, LOW);
            }
        }
    }
    if (Firebase.getInt(firebaseData, "/a5"))
    {
        if (firebaseData.dataType() == "int")
        {
            int val = firebaseData.intData();
            Serial.print(val);
            if (val == 1)
            {
                digitalWrite(dev5, HIGH);
            }
            else
            {
                digitalWrite(dev5, LOW);
            }
        }
    }
    Serial.println();
}


#define BLYNK_PRINT Serial


#include <Adafruit_NeoPixel.h>
#include <ESP8266WiFi.h>
#include <SPI.h>
#include <BlynkSimpleEsp8266.h>

#define PIN D5
#define NUMPIXELS 6
#define BLYNK_PRINT Serial
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "Z0uWyDkpnORs8VSLxo51UQbjQv0rx7kJ";
char ssid[] = "asus";
char pass[] = "t9indigo";





void setup()
{
Serial.begin(9600);
Blynk.begin("Authentication Token", "SSID", "Password");
pixels.begin();
}
BLYNK_WRITE(V1)
{

int R = param[0].asInt();
int G = param[1].asInt();
int B = param[2].asInt();
Serial.println(R);
Serial.println(G);
Serial.println(B);
for(int i=0;i<NUMPIXELS;i++){

pixels.setPixelColor(i, pixels.Color(R,G,B));

pixels.show();
}
}

void loop()
{
Blynk.run();
}

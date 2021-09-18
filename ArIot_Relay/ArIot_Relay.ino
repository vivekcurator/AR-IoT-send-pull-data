/* Comment this out to disable prints and save space */
#define BLYNK_PRINT Serial

/* Fill-in your Template ID (only if using Blynk.Cloud) */
//#define BLYNK_TEMPLATE_ID   "YourTemplateID"


#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

#define relay 15  // Relay pin

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "fnYpqvofeaOowcFyGalfdTizYVNXtefr";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "Vivek";
char pass[] = "12345678";

BLYNK_WRITE(V1)
{
  int pinValue = param.asInt(); // assigning incoming value from pin V1 to a variable
  digitalWrite(relay,pinValue);
  // process received value
}


void setup()
{
  // Debug console
  Serial.begin(9600);
  pinMode(relay,OUTPUT);
  Blynk.begin(auth, ssid, pass);
}

void loop()
{
  Blynk.run();
}

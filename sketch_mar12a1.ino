#include <ESP8266WiFi.h>
#include <ThingSpeak.h>

const char *ssid = "vivo 1807";
const char *pass = "Revathi393";
int a;

WiFiClient client;

long myChannelNumber = 2465715;
const char myWriteAPIKey[] = "Q0WR5UMY77A6J68Y";

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
WiFi.begin(ssid, pass);
while (WiFi.status() != WL_CONNECTED)
{
  delay(200);
  Serial.print("..");
}
Serial.println();
Serial.println("NodeMCU is Connected!");
Serial.println(WiFi.localIP());
ThingSpeak.begin(client);
}

void loop() {
  // put your main code here, to run repeatedly:
ThingSpeak.writeField(myChannelNumber, 1, a, myWriteAPIKey);
Serial.println("DATA UPDATED ......!");
a++;
delay(13000);

}

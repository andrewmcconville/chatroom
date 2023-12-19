#include <Adafruit_NeoPixel.h>

#define LED_PIN 6
#define LED_COUNT 64
Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);

#define SOLINOID 7
#define NOOD 8

int flicker = 4;
int led = 5;

void setup()
{
  pinMode(SOLINOID, OUTPUT);
  pinMode(NOOD, OUTPUT);
  strip.begin();
  strip.show();
  strip.setBrightness(50);
}

void loop()
{
  for (int i = 0; i < flicker; i++)
  {
    strip.setPixelColor(led, strip.Color(50, 40, 40));
    strip.show();
    digitalWrite(SOLINOID, HIGH);
    digitalWrite(NOOD, HIGH);
    delay(random(8, 100));

    strip.clear();
    strip.show();
    digitalWrite(SOLINOID, LOW);
    digitalWrite(NOOD, LOW);
    delay(random(40, 60));
  }

  flicker = random(2, 24);
  led = random(0, 64);

  delay(random(100, 1000));
}

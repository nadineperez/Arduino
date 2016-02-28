#include <Adafruit_NeoPixel.h>

Adafruit_NeoPixel leds = Adafruit_NeoPixel(2, 15, NEO_GRB + NEO_KHZ800);

void setup() {
  Serial.begin(9600);
  Serial.println("Hello World");

  leds.begin();
  leds.show();

}

void loop() {
  // put your main code here, to run repeatedly:
  static uint32_t last_switched = 0;
  static uint8_t blink_state = 0;

  static uint32_t switch_speed = 200;

  static uint8_t r_l = 0;
  static uint8_t g_l = 0;
  static uint8_t b_l = 0;

  uint8_t r = 0;
  uint8_t g = 0;
  uint8_t b = 0;

  do {
    r = 255 * random(0, 2);
    g = 255 * random(0, 2);
    b = 255 * random(0, 2);
  } while (((r + g + b) == 0) || (r == r_l && g == g_l && b == b_l));

  r_l = r;
  b_l = b;
  g_l = g;

  if (blink_state == 1) {
    blink_state = 0;

    leds.setPixelColor(0, r, g, b);
    leds.setPixelColor(1, 0, 0, 0);

  } else {
    blink_state =   1;

    leds.setPixelColor(1, r, g, b);
    leds.setPixelColor(0, 0, 0, 0);
  }


  leds.setBrightness(100);

  leds.show();

  delay(250);



}

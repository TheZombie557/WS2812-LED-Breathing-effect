#include <FastLED.h>

#define DATA_PIN    7     // Change this to your data pin
#define NUM_LEDS    10      // Change this to the number of LEDs in your strip

CRGB leds[NUM_LEDS];        // Define the array to hold LED colors

void setup() {
    FastLED.addLeds<WS2812B, DATA_PIN, GRB>(leds, NUM_LEDS); // Change LED type if needed
    FastLED.setBrightness(200); // Set initial brightness (0 to 255)
}

void loop() {
    breathingLights(3000); // Call the function with a duration of 3000 milliseconds
}

void breathingLights(int duration) {
    int breatheTime = duration / 2; // Time for each phase of the breath
    int fadeAmount = 255;           // Maximum brightness value

   breathingCycle(fadeAmount, CRGB(0, 102, 204), breatheTime);

    // Breathing cycle for pinkish red
    breathingCycle(fadeAmount, CRGB(255, 102, 102), breatheTime);

    // Breathing cycle for light green
    breathingCycle(fadeAmount, CRGB(102, 255, 102), breatheTime);
}

void breathingCycle(int fadeAmount, CRGB targetColor, int breatheTime) {
    for (int i = 0; i <= fadeAmount; i++) {
        int brightness = map(i, 0, fadeAmount, 0, 255);
        for (int j = 0; j < NUM_LEDS; j++) {
            leds[j] = targetColor;
            leds[j].fadeToBlackBy(255 - brightness);
        }
        FastLED.show();
        delay(breatheTime / fadeAmount);
    }

    for (int i = fadeAmount; i >= 0; i--) {
        int brightness = map(i, 0, fadeAmount, 0, 255);
        for (int j = 0; j < NUM_LEDS; j++) {
            leds[j] = targetColor;
            leds[j].fadeToBlackBy(255 - brightness);
        }
        FastLED.show();
        delay(breatheTime / fadeAmount);
    }
}
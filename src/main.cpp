#include <Arduino.h>
#include <LedControl.h>

#define PIN_DIN 3
#define PIN_CS 4
#define PIN_CLK 5

LedControl matrix = LedControl(PIN_DIN, PIN_CLK, PIN_CS);

void init_matrix() {
	matrix.shutdown(0, false);
	matrix.setIntensity(0, 8);
	matrix.clearDisplay(0);
}

__attribute__((unused)) void setup() {
	init_matrix();
}

__attribute__((unused)) void loop() {
	static uint32_t led_timer = millis();

	uint8_t led_x, led_y;

	for (led_y = 0; led_y < 8; led_y++) {
		for (led_x = 0; led_x < 8;) {
			if (millis() - led_timer >= 100) {
				led_timer = millis();
				matrix.setLed(0, led_x, led_y, true);
				led_x++;
			}
		}
	}

	for (led_y = 0; led_y < 8; led_y++) {
		for (led_x = 0; led_x < 8;) {
			if (millis() - led_timer >= 100) {
				led_timer = millis();
				matrix.setLed(0, led_x, led_y, false);
				led_x++;
			}
		}
	}
}

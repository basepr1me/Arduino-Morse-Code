#include "Morse.h"

#define	WPM		 17
#define LEDP		 13 // most arduino LED pins
#define GSECS		 2000 // seconds between transmissions
#define DSECS		 4000

unsigned long	 current_gpio_millis, start_gpio_millis;
void		 setup(void);
void		 loop(void);


Morse		 morse(M_GPIO, LEDP, WPM);

// backticks will toggle digraph sending

String		 tx = "ab7cd de a7bcd k `ar`";

void
setup(void)
{
	Serial.begin(115200);

	pinMode(LEDP, OUTPUT);
	digitalWrite(LEDP, LOW);

	// setup millis
	start_gpio_millis = millis();
	current_gpio_millis = millis();

	delay(2000);
	Serial.println("LED setup");
}

void
loop(void)
{
	current_gpio_millis = millis();

	morse.gpio_watchdog();

	// it's up to the programmer to properly space transmissions
	if (!morse.gpio_transmitting() &&
	    (current_gpio_millis - start_gpio_millis >= GSECS)) {
		Serial.println("Transmit via LED");
		morse.gpio_tx(tx);
	} else if (morse.gpio_transmitting())
		start_gpio_millis = current_gpio_millis;
}

# Arduino Morse Code

Arduino Morse Code Library

This Morse Code library allows the programmer to generate Morse Code via a GPIO
pin.

Usage
-----

Clone the library to your project:

		git clone https://github.com/basepr1me/Arduino-Morse-Code.git libraries/Morse

Two class instantiation methods are in place:

		Morse(TYPE, PIN);
		Morse(TYPE, PIN, WPM);

Types available are:
		
		M_GPIO	// GPIO Pin Type

Pro-sign Morse Code can be generated using backticks:

		String tx = "ab2cd de a2bcd `sos`";

To enable the Morse Code, a watchdog is available:

		morse.gpio_watchdog();

Example
-------

See the [LED Example](examples/LED/LED.ino) file for more information.

Notes
-----

I don't pretend to know anything about writing Arduino libraries. This style is
OpenBSD style and may not look right in the Arduino IDE, since I don't use it.

Author
------

[Tracey Emery](https://github.com/basepr1me/)

If you like this software, consider [donating](https://k7tle.com/?donate=1).

See the [License](LICENSE.md) file for more information.

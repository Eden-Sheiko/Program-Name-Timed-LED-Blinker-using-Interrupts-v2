# Timed LED Blinker using Interrupts
This program demonstrates the usage of timers overflow interrupts to toggle the state of an LED every 0.5 seconds. It is designed to work with the Arduino platform, and it configures Timer2 with a prescaler of 64 to achieve the desired timing.

## Hardware Setup
To use this program, you will need an Arduino board and an LED connected to pin 13. The LED should be connected to ground through a current-limiting resistor.

## Usage
1. Connect your Arduino board to your computer using a USB cable.
2. Open the Arduino IDE and load this program onto your board.
3. The LED connected to pin 13 should now start blinking every 0.5 seconds.
## Program Explanation
The program uses Timer2 to generate interrupts at a rate of approximately 976 times per second. When the interrupt occurs, the program increments a counter variable and checks if it has reached a certain value (488 in this case), indicating that half a second has elapsed. If the counter value has reached the threshold, the program toggles the state of the LED and resets the counter.

## License
This program is released under the MIT License.

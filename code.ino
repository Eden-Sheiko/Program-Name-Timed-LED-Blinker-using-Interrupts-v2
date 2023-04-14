/*
 * Program Name: Timed LED Blinker using Interrupts
 * Description: This program demonstrates the usage of Timers Overflow Interrupts to toggle the state of an LED every 0.5 seconds.
 *              It configures a Timer with a prescaler of 64.
 *              The counting frequency of Timer2 = 16,000,000 / 64 = 250,000 [Hz].
 *              Timer2 is 8-bit, so it can store values between 0-255.
 *              The timer is expected to be "re-filled" at 250,000 / 256 = ~976 times per second.
 *              The LED is toggled every half a second (~0.5 seconds).
 */

#define ZERO 0
#define VAL 488

// Global variable to keep track of the number of timer overflows
volatile unsigned int timerCount = ZERO;

void setup()
{
  // Set pin 13 (PB5) as an output
  DDRB |= (1 << DDB5);

  // Disable interrupts
  cli();

  // Clear Timer2 control registers
  TCCR2A = ZERO;
  TCCR2B = ZERO;

  // Set Timer2 counter value to 0
  TCNT2 = ZERO;

  // Set Timer2 prescaler to 64
  TCCR2B |= (1 << CS22);

  // Enable Timer2 overflow interrupt
  TIMSK2 |= (1 << TOIE2);

  // Enable interrupts
  sei();
}

// Interrupt Service Routine (ISR) for Timer2 overflow interrupt
ISR(TIMER2_OVF_vect)
{
  // Increment the timerCount variable
  ++timerCount;

  // Toggle every half a second (~0.5 seconds)
  if (timerCount >= VAL)
  {
    PORTB ^= (1 << PORTB5);
    // Reset the timerCount variable
    timerCount = ZERO;
  }
}

void loop()
{
  // Nothing to do here since all timing and pin toggling is handled by the Timer2 overflow interrupt
}

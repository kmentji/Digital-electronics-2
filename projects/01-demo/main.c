/*
 * ---------------------------------------------------------------------
 * Author:      Tomas Fryza
 *              Dept. of Radio Electronics, Brno Univ. of Technology
 * Created:     2018-09-27
 * Last update: 2019-09-26
 * Platform:    ATmega328P, AVR 8-bit Toolchain 3.6.2
 * ---------------------------------------------------------------------
 * Description: Blink a LED with delay function.
 * TODO: Verify functionality of LED blinker.
 * NOTE: Macro _BV converts a bit number into a byte value (see AVR Libc
 * Reference Manual).
 */

/* Includes ----------------------------------------------------------*/
#include <avr/io.h>
#include <util/delay.h>

/* Typedef -----------------------------------------------------------*/
/* Define ------------------------------------------------------------*/
#define LED_GREEN   PB5
#define BLINK_DELAY 400
#define LED_RED   PB0
#define BLINK_DELAYY 500
/* Variables ---------------------------------------------------------*/
/* Function prototypes -----------------------------------------------*/

/* Functions ---------------------------------------------------------*/
/**
  * Brief:  Main program. Blink a LED with delay function.
  * Input:  None
  * Return: None
  */
int main(void)
{
    /* Set output pin */
    DDRB |= _BV(LED_GREEN);         /* DDRB = DDRB or (0010 0000) */

    /* Turn LED off */
    PORTB &= ~_BV(LED_GREEN);       /* PORTB = PORTB and (0010 0000) */


    /* Set output pin */
    DDRB |= _BV(LED_RED);         /* DDRB = DDRB or (0010 0000) */

    /* Turn LED off */
    PORTB &= ~_BV(LED_RED);       /* PORTB = PORTB and (0010 0000) */

    /* Infinite loop */
    for (;;)
    {
        /* Invert LED and delay */
        PORTB ^= _BV(LED_GREEN);    /* PORTB = PORTB xor (0010 0000) */
        PORTB ^= _BV(LED_GREEN);    /* PORTB = PORTB xor (0010 0000) */
        
        _delay_ms(BLINK_DELAY);     /* Wait for several milisecs */
        PORTB ^= _BV(LED_RED);    /* PORTB = PORTB xor (0010 0000) */
        PORTB ^= _BV(LED_GREEN);    /* PORTB = PORTB xor (0010 0000) */
        _delay_ms(BLINK_DELAYY);     /* Wait for several milisecs */

        
    }

    return (0);
}

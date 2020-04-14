/*	Author: huryan18
 *  Partner(s) Name:
 *	Lab Section:
 *	Assignment: Lab #  Exercise #
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

unsigned char GetBit(unsigned char x, unsigned char k) {
      return ((x & (0x01 << k)) != 0);
}

int main(void) {
      /* Insert DDR and PORT initializations */
      DDRA = 0x00; PORTA = 0xFF;
      DDRB = 0xFF; PORTB = 0x00;
      DDRC = 0xFF; PORTC = 0x00;
      /* Insert your solution below */

      while (1) {
            PORTB = (PINA & 0xF0) >> 4;
            PORTC = (PINA & 0x0F) << 4;
      }
      return 1;
}

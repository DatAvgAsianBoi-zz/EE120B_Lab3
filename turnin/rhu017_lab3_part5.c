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
      // DDRA = 0x00; PORTA = 0xFF;
      DDRB = 0xFE; PORTB = 0x01;
      // DDRC = 0xFF; PORTC = 0x00;
      DDRD = 0x00; PORTD = 0xFF;
      /* Insert your solution below */
      unsigned char weight = 0;
      while (1) {
            PORTB = PINB & 0x01;
            weight = PIND << 1;
            weight = weight | (PINB & 0x01);
            if(weight > 69)
                  PORTB = PINB |0x02;
            else if(weight > 5)
                  PORTB = PINB | 0x04;
      }
      return 1;
}

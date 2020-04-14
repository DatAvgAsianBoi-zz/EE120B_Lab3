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
      DDRB = 0x00; PORTB = 0xFF;
      DDRC = 0xFF; PORTC = 0x00;
      /* Insert your solution below */
      unsigned char count = 0;
      while (1) {
            count = 0;
            int i = 0;
            while(i < 8){
                  if(GetBit(PINA,i))
                        count++;
                  if(GetBit(PINB,i))
                        count++;
                  i++;
            }
            PORTC = count;
    }
    return 1;
}

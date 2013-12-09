/*
 * IRsensor.c
 *
 *  Created on: Dec 5, 2013
 *      Author: C15Ryan.Turner
 */
#include <msp430g2553.h>
#include "IRsensor.h"

unsigned int getLeft() {
	ADC10CTL0 &= ~ENC;
	ADC10CTL1 &= ~(INCH3|INCH2|INCH1|INCH0);
	ADC10CTL1 |= INCH_3;
	ADC10CTL0 |= ENC + ADC10SC;
	__bis_SR_register(CPUOFF + GIE);

	return ADC10MEM;
}

unsigned int getCenter() {
	ADC10CTL0 &= ~ENC;
	ADC10CTL1 &= ~(INCH3|INCH2|INCH1|INCH0);
	ADC10CTL1 |= INCH_5;
	ADC10CTL0 |= ENC + ADC10SC;
	__bis_SR_register(CPUOFF + GIE);

	return ADC10MEM;
}

unsigned int getRight() {
	ADC10CTL0 &= ~ENC;
	ADC10CTL1 &= ~(INCH3|INCH2|INCH1|INCH0);
	ADC10CTL1 |= INCH_4;
	ADC10CTL0 |= ENC + ADC10SC;
	__bis_SR_register(CPUOFF + GIE);

	return ADC10MEM;
}

// ADC10 interrupt service routine
#pragma vector=ADC10_VECTOR
__interrupt void ADC10_ISR(void) {
	__bic_SR_register_on_exit(CPUOFF);        // Clear CPUOFF bit from 0(SR)
}

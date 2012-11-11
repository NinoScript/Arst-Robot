/*
 * main.cc
 *
 *  Created on: Nov 9, 2012
 *      Author: lucho
 */

#include "pololu/3pi.h"

int adelante (int velmax){
	int tProp = 47500/velmax;	//47500 proporcion avance 20[cm]
	OrangutanMotors::setSpeeds(velmax,velmax);
	delay_ms(tProp);
	return tProp;
}

int giroIzquierda (int velmax){
	int tProp = 16000/velmax; //16000 proporcion giro 90

	OrangutanMotors::setSpeeds(-velmax,velmax);
	delay_ms(tProp);
	return tProp;
}

void detenerse(){
	OrangutanMotors::setSpeeds(0,0);
}

int ajustavelmax(int max){
	clear();
	while(!button_is_pressed(BUTTON_B)){
		OrangutanLCD::gotoXY(0,0);
		OrangutanLCD::print("Vel: ");
		OrangutanLCD::print(max);
		if(button_is_pressed(BUTTON_A)){
			max>10? max-=10: max;
			wait_for_button_release(BUTTON_A);
			clear();
		} else if(button_is_pressed(BUTTON_C)){
			max<246? max+=10: max;
			wait_for_button_release(BUTTON_C);
			clear();
		}
	}
	return max;
}

int main (){
	OrangutanBuzzer::play(">g32>>c32");
	int max = 125;
	while (1) {
		//set_analog_mode(MODE_8_BIT);
		//int max = read_trimpot();
		max = ajustavelmax(max);
		wait_for_button_release(BUTTON_B);

		clear();
		print("Press B");
		lcd_goto_xy(0,1);
		print("And Wait");
		wait_for_button_press(BUTTON_B);
		wait_for_button_release(BUTTON_B);
		delay_ms(300);

		adelante(max);

		clear();
		OrangutanLCD::print(giroIzquierda(max));
		detenerse();
		delay_ms(1200);
	}
}

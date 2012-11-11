/*
 * main.cc
 *
 *  Created on: Nov 9, 2012
 *      Author: lucho
 */

#include "pololu/3pi.h"

void adelante (int velmax){
	OrangutanMotors::setSpeeds(velmax,velmax);


}

void giroIzquierda (int velmax){
	int tProp = 16000/velmax; //1600 numero sacado de ejemplos de pololu
							//
	OrangutanMotors::setSpeeds(-velmax,velmax);
	delay_ms(tProp);
}

void detenerse(){
	OrangutanMotors::setSpeeds(0,0);
}

int ajustavelmax(int max){
	while(!button_is_pressed(BUTTON_B)){
		OrangutanLCD::gotoXY(0,0);
		OrangutanLCD::print("Vel: ");
		OrangutanLCD::print(max);
		if(button_is_pressed(BUTTON_A)){
			max>10? max-=10: max;
			wait_for_button_release(BUTTON_A);
		} else if(button_is_pressed(BUTTON_C)){
			max<246? max+=10: max;
			wait_for_button_release(BUTTON_C);
		}
	}
	return max;
}

int main (){
	int max = 125;
	while (1) {
		//set_analog_mode(MODE_8_BIT);
		//int max = read_trimpot();
		//
		max = ajustavelmax(max);
		wait_for_button_release(BUTTON_B);


		clear();
		print("Press B");
		lcd_goto_xy(0,1);
		print("And Wait");
		wait_for_button_press(BUTTON_B);
		wait_for_button_release(BUTTON_B);
		delay_ms(100);

		adelante(max);
		delay_ms(500);
		giroIzquierda(max);

		detenerse();
	}
}

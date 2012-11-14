/*
 * Movimiento.cc
 *
 *  Created on: Nov 10, 2012
 *      Author: ninoscript
 */

#include "Movimiento.h"

Movimiento::Movimiento(Pololu3pi & robot) : robot(robot) {
}

void Movimiento::calibrar() {
	unsigned int counter;
	for (counter=0; counter<80; counter++)
	  {
	    if (counter < 20 || counter >= 60)
	      OrangutanMotors::setSpeeds(40, -40);
	    else
	      OrangutanMotors::setSpeeds(-40, 40);

	    // This function records a set of sensor readings and keeps
	    // track of the minimum and maximum values encountered.  The
	    // IR_EMITTERS_ON argument means that the IR LEDs will be
	    // turned on during the reading, which is usually what you
	    // want.
	    robot.calibrateLineSensors(IR_EMITTERS_ON);

	    // Since our counter runs to 80, the total delay will be
	    // 80*20 = 1600 ms.
	    delay(20);
	  }
	  OrangutanMotors::setSpeeds(0, 0);
}

void Movimiento::seguirLineaHastaCruce() {

	int last_proportional = 0;
	long integral = 0;

	load_custom_characters();

	while (1) {
		// Normally, we will be following a line.  The code below is
		// similar to the 3pi-linefollower-pid example, but the maximum
		// speed is turned down to 60 for reliability.

		// Get the position of the line.
		unsigned int position = robot.readLine(sensors, IR_EMITTERS_ON);
		//uint8_t volume = static_cast<float>(position) * 255.0f / 4000.0f;

	    OrangutanLCD::clear();
	    OrangutanLCD::print(position);
	    //OrangutanLCD::gotoXY(0, 1);
		//display_readings(sensors);
		//OrangutanBuzzer::playFrequency(440,10,volume);
		//delay_ms(20);


		// The "proportional" term should be 0 when we are on the line.
		int proportional = ((int) position) - 2000;

		// Compute the derivative (change) and integral (sum) of the
		// position.
		int derivative = proportional - last_proportional;
		integral += proportional;

		// Remember the last position.
		last_proportional = proportional;

		// Compute the difference between the two motor power settings,
		// m1 - m2.  If this is a positive number the robot will turn
		// to the left.  If it is a negative number, the robot will
		// turn to the right, and the magnitude of the number determines
		// the sharpness of the turn.
		int power_difference = proportional / 20 + integral / 10000
				+ derivative * 3 / 2;

		// Compute the actual motor settings.  We never set either motor
		// to a negative value.
		if (power_difference > velocidad_maxima_avance)
			power_difference = velocidad_maxima_avance;
		if (power_difference < -velocidad_maxima_avance)
			power_difference = -velocidad_maxima_avance;

		if (power_difference < 0)
			OrangutanMotors::setSpeeds(
					velocidad_maxima_avance + power_difference,
					velocidad_maxima_avance);
		else
			OrangutanMotors::setSpeeds(velocidad_maxima_avance,
					velocidad_maxima_avance - power_difference);

		// We use the inner three sensors (1, 2, and 3) for
		// determining whether there is a line straight ahead, and the
		// sensors 0 and 4 for detecting lines going to the left and
		// right.

		if (sensors[0] > 500 && sensors[4] > 500) {
			// Found an intersection.
			break;
		}

	}
	// Drive straight while slowing down, as before.
	const uint8_t pasos = 5;
	for (uint8_t i = pasos-1; i>0; i--) {
		uint8_t velocidad = velocidad_maxima_avance*i/pasos;
		OrangutanMotors::setSpeeds(velocidad,velocidad);
		delay_ms(200/pasos);
	}
	OrangutanMotors::setSpeeds(0,0);
	delay_ms(50);
}

const char Movimiento::levels[]  = { 0b00000, 0b00000, 0b00000, 0b00000,
		0b00000, 0b00000, 0b00000, 0b11111, 0b11111, 0b11111, 0b11111, 0b11111,
		0b11111, 0b11111 };

void Movimiento::load_custom_characters() {
	OrangutanLCD::loadCustomCharacter(levels + 0, 0); // no offset, e.g. one bar
	OrangutanLCD::loadCustomCharacter(levels + 1, 1); // two bars
	OrangutanLCD::loadCustomCharacter(levels + 2, 2); // etc...
	OrangutanLCD::loadCustomCharacter(levels + 3, 3);
	OrangutanLCD::loadCustomCharacter(levels + 4, 4);
	OrangutanLCD::loadCustomCharacter(levels + 5, 5);
	OrangutanLCD::loadCustomCharacter(levels + 6, 6);
	OrangutanLCD::clear(); // the LCD must be cleared for the characters to take effect
}

// This function displays the sensor readings using a bar graph.
void Movimiento::display_readings(const unsigned int *calibrated_values) {
	unsigned char i;

	for (i = 0; i < 5; i++) {
		// Initialize the array of characters that we will use for the
		// graph.  Using the space, an extra copy of the one-bar
		// character, and character 255 (a full black box), we get 10
		// characters in the array.
		const char display_characters[10] = { ' ', 0, 0, 1, 2, 3, 4, 5, 6, 255 };

		// The variable c will have values from 0 to 9, since
		// calibrated values are in the range of 0 to 1000, and
		// 1000/101 is 9 with integer math.
		char c = display_characters[calibrated_values[i] / 101];

		// Display the bar graph character.
		OrangutanLCD::print(c);
	}
}

void Movimiento::avanzarUnCuadrado(uint8_t cm) {
	if (cm != 0) {
		OrangutanMotors::setSpeeds(velocidad_maxima_avance,
				velocidad_maxima_avance);
		delay_ms(tiempo_velocidad*cm);
		detenerse();
	} else {
		seguirLineaHastaCruce();
	}

}

void Movimiento::girarDer() {
	OrangutanMotors::setSpeeds(velocidad_maxima_giro, -velocidad_maxima_giro);
	delay_ms(tiempo_giro);
	detenerse();
}

void Movimiento::girarIzq() {
	OrangutanMotors::setSpeeds(-velocidad_maxima_giro, velocidad_maxima_giro);
	delay_ms(tiempo_giro);
	detenerse();
}

void Movimiento::girarEnU() {
	girarDer();
	girarDer();
	detenerse();
}

void Movimiento::detenerse() {
	OrangutanMotors::setSpeeds(0, 0);
}

void Movimiento::actualizarFactores() {
	tiempo_velocidad = 10 * factor_distancia / (velocidad_maxima_avance);
	tiempo_giro = 10 * factor_angulo / velocidad_maxima_giro;
}

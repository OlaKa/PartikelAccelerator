/*
 * Particle.cpp
 *
 *  Created on: 31 jul 2017
 *      Author: ola
 */

#include "Particle.h"
#include <stdlib.h>
namespace monitor {

Particle::Particle() {
	m_x = ((2.0 * rand()) / RAND_MAX) - 1;
	m_y = ((2.0 * rand()) / RAND_MAX) - 1;

	x_speed = 0.001*((2.0*rand()/RAND_MAX) -1);
	y_speed = 0.001*((2.0*rand()/RAND_MAX) -1);

}

Particle::~Particle() {

}

void Particle::update() {

	m_x += x_speed;
	m_y += y_speed;

	if(m_x <= -1.0 || m_x>=1.0){
		x_speed = -x_speed;

	}

	if(m_y <= -1.0 || m_y>=1.0){
			y_speed = -y_speed;

		}
}

} /* namespace monitor */

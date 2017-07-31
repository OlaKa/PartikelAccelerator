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
	m_x = ((2.0*rand())/RAND_MAX) -1;
	m_y = ((2.0*rand())/RAND_MAX) -1;

}

Particle::~Particle() {

}

} /* namespace monitor */

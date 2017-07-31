/*
 * Swarm.cpp
 *
 *  Created on: 31 jul 2017
 *      Author: ola
 */

#include "Swarm.h"

namespace monitor {

Swarm::Swarm() {
	m_pParticles = new Particle[NPARTICLES];

}

Swarm::~Swarm() {
	delete [] m_pParticles;
}

} /* namespace monitor */

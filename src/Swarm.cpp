/*
 * Swarm.cpp
 *
 *  Created on: 31 jul 2017
 *      Author: ola
 */

#include "Swarm.h"

namespace monitor {

Swarm::Swarm():lastTime(0) {
	m_pParticles = new Particle[NPARTICLES];

}

Swarm::~Swarm() {
	delete[] m_pParticles;
}
void Swarm::update(int elapsed) {
	int interval = elapsed - lastTime;
	for (int i = 0; i < Swarm::NPARTICLES; i++) {
		m_pParticles[i].update(interval);
	}
}

} /* namespace monitor */

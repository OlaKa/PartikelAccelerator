/*
 * Swarm.h
 *
 *  Created on: 31 jul 2017
 *      Author: ola
 */

#ifndef SWARM_H_
#define SWARM_H_

#include "Particle.h"

namespace monitor {

class Swarm {
public:
	const static int NPARTICLES = 5000;
private:
	Particle * m_pParticles;
	int lastTime;

public:
	Swarm();
	virtual ~Swarm();
	const Particle * const getParticles(){return m_pParticles;}
	void update(int elapsed);
};

} /* namespace monitor */

#endif /* SWARM_H_ */

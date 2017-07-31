/*
 * Particle.h
 *
 *  Created on: 31 jul 2017
 *      Author: ola
 */

#ifndef PARTICLE_H_
#define PARTICLE_H_

namespace monitor {

struct Particle {
	double m_x;
	double m_y;

	double  x_speed;
	double  y_speed;

	Particle();
	virtual ~Particle();
	void update();
};

} /* namespace monitor */

#endif /* PARTICLE_H_ */

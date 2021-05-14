#include "ParticleSystem.h"

void ParticleSystem::init()
{
	init(100);
}

void ParticleSystem::update()
{
	for (int i = 0; i < psize; i++) {
		pp[i].x += pp[i].vx;
		pp[i].y += pp[i].vy;
	}
}

int ParticleSystem::getSize()
{
	return psize;
}

void ParticleSystem::init(int _psize)
{
	if (_psize > MAX_PARTICLE_SIZE)
		_psize = MAX_PARTICLE_SIZE;

	pp = new Particle[_psize];
	psize = _psize;

	for (int i = 0; i < psize; i++) {
		pp[i].x = random(0,1024);
		pp[i].y = random(0, 768);

		pp[i].vx = 0;
		pp[i].vy = 0;

		pp[i].r = 255;
		pp[i].g = 255;
		pp[i].b = 255;

		pp[i].size = random(1, 5);
	}
}

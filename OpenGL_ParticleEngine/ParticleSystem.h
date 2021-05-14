#pragma once
#ifndef PARTICLE_SYSTEM_H
#define PARTICLE_SYSTEM_H

#include <stdlib.h>
#include <iostream>

using namespace std;

#define MAX_PARTICLE_SIZE 1024

typedef struct {
    float x, y;     // Position in space
    float vx, vy;  // Velocity vector
    float r, g, b;     // Color of particle
    float size;        // Size of particle
} Particle;

class ParticleSystem
{
public:
    Particle* pp;

    void init();
    void update();

    int getSize();

private:
    void init(int _psize);
    unsigned int psize = 0;
};

static float random(int _min, int _max) {
 
    return _min + (rand() % (_max - _min));
}

#endif // PARTICLE_SYSTEM_H


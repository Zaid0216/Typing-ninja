#include "Utils.h"

float hireTimeInSeconds() {
	float t = (float) SDL_GetTicks();
	t /= 1000;
	return t;
}

float randomFloat() {
	return (float)rand() / (float)RAND_MAX;
}
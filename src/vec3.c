//#include <stdio.h>
#include "vec3.h"

//print vec3 values
void vec3_string(vec3 v, FILE *file) {
	fprintf(file, "%0.2f %0.2f %0.2f", v.x, v.y, v.z);
}

vec3 minus(vec3 * v) {
	vec3 u = {-(v->x), -(v->y), -(v->z)};
	return u;
}

vec3 add(vec3 *u, vec3 *v) {
	vec3 w = {u->x + v->x,
		u->y + v->y,
		u->z + v->z};
	return w;
}

vec3 mul(vec3 *v, float *t) {
	vec3 u = { v->x * *t, v->y * *t, v->z * *t};
	return u;
}
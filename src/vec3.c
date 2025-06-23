#include "vec3.h"
#include <math.h>

//print vec3 values
void vec3_string(vec3 v, FILE *file) {
	fprintf(file, "%0.2f %0.2f %0.2f", v.x, v.y, v.z);
}

vec3 neg(vec3 * v) {
	vec3 u = {-(v->x), -(v->y), -(v->z)};
	return u;
}

vec3 add(vec3 *u, vec3 *v) {
	vec3 w = {u->x + v->x,
		u->y + v->y,
		u->z + v->z};
	return w;
}

vec3 mul(vec3 *v, float t) {
	vec3 u = { v->x * t, v->y * t, v->z * t};
	return u;
}

vec3 subs(vec3 *u, vec3 *v) {
	vec3 w = {u->x - v->x,
		u->y - v->y,
		u->z - v->z};
	return w;
}

vec3 div(vec3 *v, float t) {
	vec3 u = mul(v, 1.0f / t);
	return u;
}

float length_squared(vec3* v) {
	return v->x * v->x + v->y * v->y + v->z * v->z;
}

float length(float l) {
	return sqrt(l);
}

vec3 unit_vector(vec3* v) {
	float l = length_squared(v);
	vec3 w = div(v, length(l));
	return w;
}

float dot(vec3* u, vec3* v) {
	return u->x * v->x + u->y * v->y + u->z * v->z;
}
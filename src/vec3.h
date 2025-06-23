#ifndef VEC3_H
#define VEC3_H

#include <stdio.h>

typedef struct vec3_t {
	float x;
	float y;
	float z;
} vec3;

typedef vec3 point3;

void vec3_string(vec3 v, FILE *file);
vec3 neg(vec3 *v);
vec3 add(vec3 *u, vec3 *v);
vec3 mul(vec3 *u, float t);
vec3 subs(vec3 *u, vec3 *v);
vec3 div(vec3 *v, float t);
float length(float l);
float length_squared(vec3* v);
vec3 unit_vector(vec3* v);
float dot(vec3* u, vec3* v);

#endif

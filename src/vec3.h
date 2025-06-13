#ifndef VEC3_H
#define VEC3_H

#include <stdio.h>

typedef struct vec3_t {
	float x;
	float y;
	float z;
} vec3;

//vec3 point; //point are also vec3

void vec3_string(vec3 v, FILE *file);
vec3 minus(vec3 *v);
vec3 add(vec3 *u, vec3 *v);
vec3 mul(vec3 *u, float *t);

#endif

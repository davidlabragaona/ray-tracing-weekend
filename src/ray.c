#include "ray.h"
#include "vec3.h"

const point3 at(ray *r, float t){
	vec3 dir = mul(&r->dir, t);
	point3 p = add(&r->orig, &dir);
	return p;
}
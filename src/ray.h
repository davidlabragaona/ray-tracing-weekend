#ifndef RAY_H
#define RAY_H

#include "vec3.h"

typedef struct ray_t {
  point3 orig;
  vec3 dir;
} ray;

#endif
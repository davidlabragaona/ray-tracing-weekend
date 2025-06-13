#include <criterion/criterion.h>
#include "../src/vec3.h"

//sudo apt-install apt-get install libcriterion-dev

//minus
Test(vec3, vec3_minus) {
    vec3 v = {1, 2, 3};
    vec3 vminus = minus(&v);
    cr_assert(-v.x == vminus.x && -v.y == vminus.y && -v.z == vminus.z, "Inverting sign: v{%f, %f, %f}: vminus{%f, %f, %f}\n",
        -v.x, -v.y, -v.z, vminus.x, vminus.y, vminus.z);
}

//add
Test(vec3, vec3_add) {
    vec3 u = {1, 2, 3};
    vec3 v = {3, 2, 1};
    vec3 r = add(&u, &v);
    cr_assert((r.x == u.x + v.x) && (r.y == u.y + v.y) && (r.z == u.z + v.z), "Add: u{%f, %f, %f} + v{%f, %f, %f} = r{%f, %f, %f}\n",
    u.x, u.y, u.z, v.x, v.y, v.z, r.x, r.y, r.z);
}

Test(vec3, vec3_mul) {
    vec3 v = {1, 2, 3};
    float f = 2.5;
    vec3 r = mul(&v, &f);
    cr_assert(r.x == (v.x * f), "mult: u{%f, %f, %f} f:%f r{%f, %f, %f}\n",
    v.x, v.y, v.z, f, r.x, r.y, r.z);
}
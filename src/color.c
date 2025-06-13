#include "color.h"

void write_color(FILE* file, const color *pixel_color) {
	float r = pixel_color->x;
	float g = pixel_color->y;
	float b = pixel_color->z;

	int rbyte = (int) 255.999 * r;
	int gbyte = (int) 255.999 * g;
	int bbyte = (int) 255.999 * b;

	fprintf(file, "%i %i %i\n", rbyte, gbyte, bbyte);
}
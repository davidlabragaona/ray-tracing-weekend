#include <stdio.h>
#include "color.h"
#include "ray.h"
#include "vec3.h"

int hit_sphere(point3* center, float radius, ray* r) {
	vec3 oc = subs(center, &r->orig);
	float a = dot(&r->dir, &r->dir);
	float b = -2.0f * dot(&r->dir, &oc);
	float c = dot(&oc, &oc) - radius * radius;
	float discriminant = b*b - 4.0f*a*c;
	return discriminant >= 0;
}

color ray_color(ray *r) {
	point3 p = {0.0f, 0.0f, -1.0f};
	if (hit_sphere(&p, 0.5f, r)) {
		color c = {1.0f, 0.0f, 0.0f};
		return c;
	}

	vec3 unit_direction = unit_vector(&r->dir);
	float a = 0.5f * (unit_direction.y + 1.0f);
	color c1 = {1.0f, 1.0f, 1.0f}; //white
	color c2 = {0.5f, 0.7f, 1.0f}; //light_blue
	c1 = mul(&c1, 1.0f - a);
	c2 = mul(&c2, a);
	return add(&c1, &c2);
}

main()
{
	// Image
	float aspect_ratio = 16.0f / 10.0f;
	int image_width = 400;

	//Calculate the image height, and ensure that is at least 1.
	int image_height = image_width / aspect_ratio;
	image_height = image_height < 1 ? 1 : image_height;

	//Camera
	float focal_length = 1.0f;
	float viewport_height = 2.0f;
	float viewport_width = viewport_height * (image_width / image_height);
	point3 camera_center = {0, 0, 0};

	//Calculate the vectors across the horizontal and down the vertical viewport edges.
	vec3 viewport_u = {viewport_width, 0, 0};
	vec3 viewport_v = {0, -viewport_height, 0};

	//Calculate the horizontal and vertical delta vectors from pixel to pixel
	point3 pixel_delta_u = div(&viewport_u, image_width);
	point3 pixel_delta_v = div(&viewport_v, image_height);

	//Calculate the location of the upper left pixel.
	vec3 u = {0, 0, focal_length};
	vec3 v = div(&viewport_u, 2.0f);
	vec3 w = div(&viewport_v, 2.0f);
	u = add(&u, &v);
	u = add(&u, &w);
	point3 viewport_upper_left = subs(&camera_center, &u);
	point3 pixel00_loc = add(&pixel_delta_u, &pixel_delta_v);
	pixel00_loc = mul(&pixel00_loc, 0.5f);
	pixel00_loc = add(&viewport_upper_left, &pixel00_loc);

	// Render
	printf("P3\n%d %d\n255\n", image_width, image_height);
	for (int j = 0; j < image_height; j++) {
		fprintf(stderr, "\rScanlines remaining: %d", (image_height - j));
		for (int i = 0; i < image_width; i++) {
			u = mul(&pixel_delta_u, i);
			v = mul(&pixel_delta_v, j);
			v = add(&u, &v); 
			point3 pixel_center = add(&pixel00_loc, &v);
			point3 ray_direction = subs(&pixel_center, &camera_center);
			ray r = {camera_center, ray_direction};
			color pixel_color = ray_color(&r);
			write_color(stdout, &pixel_color);
		}
	}
	fprintf(stderr, "\rDone.                    \n");
}

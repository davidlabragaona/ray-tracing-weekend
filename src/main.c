#include <stdio.h>
#include "color.h"
#include "vec3.h"

main()
{
	// Image
	int width = 256;
	int height = 256;

	// Render
	printf("P3\n%d %d\n255\n", width, height);
	for (int j = 0; j < height; j++) {
		fprintf(stderr, "\rScanlines remaining: %d", (height - j));
		for (int i = 0; i < width; i++) {
			color pixel_color = {((float)i) / (width - 1),
				((float)j) / (height - 1), 0};
			write_color(stdout, &pixel_color);
		}
	}
	fprintf(stderr, "\rDone.                    \n");
}

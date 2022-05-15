#include <stdio.h>
#define SIZE 5


void print_image(int img[][SIZE], int xsize, int ysize)
{
	for (int i = 0; i < ysize; i++) {
		for (int j = 0; j < xsize; j++) {
			printf("%d ", img[i][j]);
		}
		printf("\n");
	}
	printf("\n\n");
}

void brighten_image(int img[][SIZE], int xsize, int ysize)
{
	for (int i = 0; i < ysize; i++) {
		for (int j = 0; j < xsize; j++) {
			int pixel = img[i][j] + 10;
			if (pixel > 255) pixel = 255;
			img[i][j] = pixel;
		}
	}
}

int hw112(void)
{
	int image[SIZE][SIZE] = {
		{ 10, 120, 130, 240, 250},
		{ 10, 120, 130, 240, 250},
		{ 10, 120, 130, 240, 250},
		{ 10, 120, 130, 240, 250},
		{ 10, 120, 130, 240, 250} };

	print_image(image, SIZE, SIZE);
	brighten_image(image, SIZE, SIZE);
	print_image(image, SIZE, SIZE);
	return 0;
}

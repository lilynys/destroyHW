#include "Sandglass.h"
#include "draw.h"

void Sandglass::draw() {
	int size = this->size + 50;
	int j_start = this->y - size / 2;
	int j_end = this->y + size / 2;
	for (int j = j_start; j <= j_end; j++) {
		int i_start = this->x - size + (j / 2);
		int i_end = this->x + size - (j / 2);
		for (int i = i_start; i <= i_end; i++) {
			if (j == j_start || j == j_end || i == i_start || i == i_end)
				drawPixel(i, j, 1.0f, 0.0f, 0.0f);
		}
	}
	for (int j = j_start; j <= j_end; j++) {
		int i_start = this->x + size - (j / 2);
		int i_end = this->x - size + (j / 2);
		for (int i = i_start; i <= i_end; i++) {
			if (j == j_start || j == j_end || i == i_start || i == i_end)
				drawPixel(i, j, 1.0f, 0.0f, 0.0f);
		}
	}
}
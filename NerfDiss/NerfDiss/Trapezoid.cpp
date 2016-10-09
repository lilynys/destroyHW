#include "Trapezoid.h"
#include "draw.h"

void Trapezoid::draw() {
	int s = this->size-30;
	int j_start = this->y - s;
	int j_end = this->y + s;
	for (int j = j_start; j <= j_end; j++) {
		int i_start = this->x +s+10 -j/2;
		int i_end = this->x -s-10 +j/2;
		for (int i = i_start; i <= i_end; i++) {
			if (j == j_start || j == j_end || i == i_start || i == i_end)
				drawPixel(i, j, 1.0f, 0.0f, 0.0f);
		}
	}
}
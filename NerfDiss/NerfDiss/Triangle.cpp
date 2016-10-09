#include "Triangle.h"
#include "draw.h"

void Triangle::draw() {
	/*
	int s = this->size+30;
	int j_start = this->y - s+50;
	int j_end = this->y + s+50;
	
	for (int j = j_start; j <= j_end; j++) {
		int i_start = this->x - s + (j / 2);
		int i_end = this->x + s - (j / 2);
		for (int i = i_start; i <= i_end; i++) {
			if (j == j_start || j == j_end || i == i_start || i == i_end) {
				drawPixel(i, j, red, green, blue);
				printf("%d %d", i, j);
			}

		}
	}
	*/
	drawLine(this->x - size / 2, this->y - size / 2, this->x, this->y + size / 2, red, blue, green);
	drawLine(this->x, this->y + size / 2, this->x + size / 2, this->y - size / 2, red, blue, green);
	drawLine(this->x - size/2, this->y - size / 2, this->x + size / 2, this->y - size / 2, red, blue, green);
}
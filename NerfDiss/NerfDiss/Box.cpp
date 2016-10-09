#include "Box.h"
#include "draw.h"

void Box::draw(){
	int size = this->size - 20;
	int j_start = this->y - size;
	int j_end = this->y + size;
	for (int j = j_start; j <= j_end; j++) {
		int i_start = this->x - size;
		int i_end = this->x + size;
		for (int i = i_start; i <= i_end; i++) {
			if (j == j_start || j == j_end || i == i_start || i == i_end)
				drawPixel(i, j, 1.0f, 0.0f, 0.0f);
		}
	}
}
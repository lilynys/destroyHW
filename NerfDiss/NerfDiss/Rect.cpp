#include "Rect.h"
#include "draw.h"

void Rect::draw() {
	for (int i = 0; i < size / 3; i++) {
		drawLine(this->x - i, this->y - size / 2, this->x - i, this->y + size / 2, red, blue, green);
		drawLine(this->x + i, this->y - size / 2, this->x + i, this->y + size / 2, red, blue, green);
	}
}
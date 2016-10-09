#include "Triangle.h"
#include "draw.h"

void Triangle::draw() {
	drawLine(this->x - size / 2, this->y - size / 2, this->x, this->y + size / 2, red, blue, green);
	drawLine(this->x, this->y + size / 2, this->x + size / 2, this->y - size / 2, red, blue, green);
	drawLine(this->x - size/2, this->y - size / 2, this->x + size / 2, this->y - size / 2, red, blue, green);
}
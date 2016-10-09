#include "Cross.h"
#include "draw.h"

void Cross::draw() {
	drawLine(this->x, this->y, this->x+size, this->y+size, red, blue, green);
	drawLine(this->x, this->y+size, this->x+size, this->y, red, blue, green);
}
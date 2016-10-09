#include "Star.h"
#include "draw.h"

void Star::draw() {
	drawLine(this->x - size / 2, this->y - size / 2, this->x, this->y+size, red, blue, green);
	drawLine(this->x, this->y+size, this->x + size / 2, this->y - size / 2, red, blue, green);
	drawLine(this->x - size / 2, this->y - size / 2, this->x + size / 2, this->y - size / 2, red, blue, green);

	drawLine(this->x - size / 2, this->y + size / 2, this->x, this->y - size, red, blue, green);
	drawLine(this->x, this->y - size, this->x + size / 2, this->y + size / 2, red, blue, green);
	
	drawLine(this->x - size / 2, this->y + size / 2, this->x + size / 2, this->y + size / 2, red, blue, green);
}
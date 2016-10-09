#include "Star.h"
#include "draw.h"

void Star::draw() {
	drawLine(this->x, this->y, this->x, this->y + size, red, blue, green);
	drawLine(this->x, this->y, this->x + size, this->y, red, blue, green);
	drawLine(this->x, this->y, this->x + size, this->y + size, red, blue, green);
	drawLine(this->x, this->y + size, this->x + size, this->y, red, blue, green);

}
#include "Snow.h"
#include "draw.h"

void Snow::draw() {
	drawLine(this->x, this->y-size/2, this->x, this->y+size/2, red, blue, green);
	drawLine(this->x-size/2, this->y, this->x+size/2, this->y, red, blue, green);
	drawLine(this->x-size/2, this->y-size/2, this->x+size/2, this->y+size/2, red, blue, green);
	drawLine(this->x-size/2, this->y+size/2, this->x+size/2, this->y-size/2, red, blue, green);

}
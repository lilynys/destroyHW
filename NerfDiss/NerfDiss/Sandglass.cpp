#include "Sandglass.h"
#include "draw.h"

void Sandglass::draw() {
	drawLine(this->x - size / 2, this->y - size / 2, this->x, this->y + size / 2, red, blue, green);
	drawLine(this->x, this->y + size / 2, this->x + size / 2, this->y - size / 2, red, blue, green);
	drawLine(this->x - size / 2, this->y - size / 2, this->x + size / 2, this->y - size / 2, red, blue, green);

	drawLine(this->x - size / 2, this->y + size / 2, this->x, this->y - size / 2, red, blue, green);
	drawLine(this->x, this->y - size / 2, this->x + size / 2, this->y + size / 2, red, blue, green);

	drawLine(this->x - size / 2, this->y + size / 2, this->x + size / 2, this->y + size / 2, red, blue, green);
}
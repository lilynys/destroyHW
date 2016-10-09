#include "Plus.h"
#include "draw.h"

void Plus::draw() {
	for (int i = 0; i < size/7; i++) {
		drawLine(this->x-i, this->y - size / 2, this->x-i, this->y + size / 2, red, blue, green);
		drawLine(this->x - size / 2, this->y-i, this->x + size / 2, this->y-i, red, blue, green);
		drawLine(this->x + i, this->y - size / 2, this->x + i, this->y + size / 2, red, blue, green);
		drawLine(this->x - size / 2, this->y + i, this->x + size / 2, this->y + i, red, blue, green);
	}
	

}
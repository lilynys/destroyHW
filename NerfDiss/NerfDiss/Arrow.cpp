#include "Arrow.h"
#include "draw.h"

void Arrow::draw() {
	int x0 = x -30;
	int y0 = y - 30;
	drawLine(x0, y0, x0, y0 + size, red, blue, green);
	drawLine(x0, y0, x0 + size, y0, red, blue, green);
	drawLine(x0, y0, x0 + size, y0 + size, red, blue, green);
	drawLine(x0, y0 + size, x0 + size, y0, red, blue, green);

}
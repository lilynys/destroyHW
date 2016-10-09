#include "Circle.h"
#include "draw.h"

void Circle:: draw(){
	for (int i = 0; i<20; i++)
	{
		double rad = size + i*0.01-20;
		for (double i = 0.0; i < 360.0; i += 0.1)
		{
			double angle = i *  M_PI / 180;

			int x = (int)(this->x + rad * cos(angle));
			int y = (int)(this->y + rad * sin(angle));
			drawPixel(x + 0, y, red, green, blue);
			drawPixel(x + 1, y, red, green, blue);
			//drawPixel(x - 1, y, red, green, blue);
			drawPixel(x, y + 1, red, green, blue);
			//drawPixel(x, y - 1, red, green, blue);
		}
	}
}

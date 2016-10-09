#include "Circle.h"
#include "draw.h"

void Circle:: draw(){
	for (int i = 0; i<20; i++)
	{
		size = size + i*0.01;
		for (double i = 0.0; i < 360.0; i += 0.1)
		{
			double angle = i *  M_PI / 180;

			int x = (int)(this->x + this->size * cos(angle));
			int y = (int)(this->y + this->size * sin(angle));
			drawPixel(x, y, red, green, blue);
		}
	}
}

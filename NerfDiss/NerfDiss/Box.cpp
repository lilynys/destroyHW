#include "Box.h"
#include "draw.h"

void Box::draw(){
int x1, x2, x3, x4;
int y1, y2, y3, y4;
this->size = size;
int innerSize = this->size / 3;
int red = this->red;
int green = this->green;
int blue = this->blue;
x1 = this->x + innerSize;
x2 = this->x + innerSize;
x3 = this->x + this->size - innerSize;
x4 = this->x + this->size - innerSize;

y1 = this->y + innerSize;
y2 = this->y + this->size - innerSize;
y3 = this->y + innerSize;
y4 = this->y + this->size - innerSize;

drawLine(x1, y1, x2, y2, red,green,blue);
drawLine(x2, y2, x4, y4, red, green, blue);
drawLine(x1, y1, x3, y3, red, green, blue);
drawLine(x3, y3, x4, y4, red, green, blue);
}
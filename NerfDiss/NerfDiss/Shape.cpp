#include "Shape.h"
#include <vector>
#include "Box.h"
#include "Circle.h"


Shape* Shape::getShape(const std::string& name)
{
	if (name == "Circle")
		return new Circle;
	if (name == "Box")
		return new Box;

	return nullptr;
}
Shape::Shape() {
	this->x = 20;
	this->y = 40;
	this->red = 1.0f;
	this->blue = 0.0f;
	this->green = 0.0f;
	this->size = 30;
	this->inside = false;
}
Shape::Shape(int x0, int y0, float red, float blue, float green, bool inside, int size) {

	this->x = x0;
	this->y = y0;
	this->red = red;
	this->blue = blue;
	this->green = green;
	this->size = size;

	this->inside = inside;

}



void Shape:: setPosition(const int& xpos, const int& ypos) {
	this->x = xpos;
	this->y = ypos;
}
void Shape::setSize(const int& size) {
	this->size = size;
}
void Shape::draw()
{
}
bool Shape::isInsideCircle(const double x, const double y, const double x_c, const double y_c, const double r)
{
	const double f = (x - x_c)*(x - x_c) + (y - y_c)*(y - y_c) - r*r;
	if (f > 0.0) return false;
	else {
		return true;
	}
}
void Shape::setLineColor(const float& red, const float& green, const float& blue) {
	this->red = red;
	this->blue = blue;
	this->green = green;
}
void Shape:: drawCircle(const int& xpos, const int& ypos) {
	Shape* s = new Circle();

	s->size = this->size + 5;
	
	s->x = this->x;
	s->y = this->y;
	if (isInsideCircle(xpos, 800 - ypos, s->x, s->y, s->size)) {
		s->green = 0.0f;
		s->red = 1.0f;
		s->blue = 0.0f;
	}
	else {
		s->green = 0.0f;
		s->red = 0.0f;
		s->blue = 1.0f;
	}
	s->draw();
}
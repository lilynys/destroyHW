#include "Shape.h"
#include <vector>
#include "Box.h"
#include "Circle.h"

Shape* getShape(const std::string& name) {
	if (name == "Box")
		return new Box;
	else if (name == "Circle")
		return new Circle;
	else
		return nullptr;
	//TODO : error handling
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
Shape * Shape::getShape(const std::string & name)
{
	if (name == "Circle")
		return new Circle;
	if (name == "Box")
		return new Box;

	return nullptr;
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
	return false;
}
void Shape::setLineColor(const float& red, const float& green, const float& blue) {
	this->red = red;
	this->blue = blue;
	this->green = green;
}
void Shape:: drawCircle() {
	Shape* s = new Circle();

	s->size = this->size + 5;
	
	s->x = this->x;
	s->y = this->y;
	s->green = 0.0f;
	s->red = 1.0f;
	s->blue = 0.0f;
	s->draw();
}
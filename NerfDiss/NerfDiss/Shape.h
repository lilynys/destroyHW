#pragma once
#include<string>

class Shape {
public:
	int x,
		y,
		size;
	float
		red,
		blue,
		green;

	bool inside;

public:
	Shape();
	Shape(int x0, int y0, float red, float blue, float green, bool inside,int size);
	Shape* getShape(const std::string& name);
	void setPosition(const int& xpos, const int& ypos);
	void setLineColor(const float& red, const float& green, const float& blue);
	void setSize(const int& size);
	virtual void draw();
	bool isInsideCircle(const double x, const double y, const double x_c, const double y_c, const double r);
	void Shape::drawCircle(const int& xpos, const int& ypos);
};
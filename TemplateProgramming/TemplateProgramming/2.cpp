#include<iostream>

template<class myname>
class Vector2D{
public:
	myname x_,y_;
	Vector2D(const myname& x_input, const myname& y_input)
		:x_(x_input), y_(y_input)
	{}
	void print() {
		std::cout << x_ << " " << y_ << std::endl;
	}
};
int main() {
	Vector2D<int> int_vector(1, 1);
	int_vector.print();
	Vector2D<float> float_vector(1.3f, 2.1f);
	float_vector.print();
	Vector2D<double> double_vector(1.2, 1.5);
	double_vector.print();
}
#include<iostream>
#include<string>

template <class T_INPUT_TYPE >
void print(const T_INPUT_TYPE& v) {
	std::cout << v << std::endl;
}
int main() {
	print(1);
	print(2.345f);
	print("Hello World");

	return 0;
}
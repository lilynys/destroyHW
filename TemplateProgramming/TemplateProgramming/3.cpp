#include <GLFW/glfw3.h>
#include <cstring>
#include <stdlib.h>		  // srand, rand
#include <thread>         // std::this_thread::sleep_for
#include <chrono>         // std::chrono::seconds
#define _USE_MATH_DEFINES
#include <math.h>
#include <vector>

//glfw
const int width = 800;
const int height = 800;

float* pixels = new float[width*height * 3];
GLFWwindow* window;

using namespace std;

void drawPixel(const int& i, const int& j, const float& red, const float&green, const float& blue)
{
	pixels[(i + width* j) * 3 + 0] = red;
	pixels[(i + width* j) * 3 + 1] = green;
	pixels[(i + width* j) * 3 + 2] = blue;

}
void drawLine(const int& i0, const int& j0, const int& i1, const int& j1, const float& red, const float& green, const float& blue)
{
	if (i1 - i0 == 0) {
		for (int i = j0; i <= j1; i++) {
			drawPixel(i0 + 0, i, red, green, blue);
			drawPixel(i0 + 1, i, red, green, blue);
			drawPixel(i0 - 1, i, red, green, blue);
			drawPixel(i0, i + 1, red, green, blue);
			drawPixel(i0, i - 1, red, green, blue);
		}
		return;
	}

	for (int i = i0; i <= i1; i++) {
		// scratched from https://courses.engr.illinois.edu/ece390/archive/archive-f2000/mp/mp4/anti.html
		const int j = (j1 - j0) * (i - i0) / (i1 - i0) + j0;
		drawPixel(i + 0, j, red, green, blue);
		drawPixel(i + 1, j, red, green, blue);
		drawPixel(i - 1, j, red, green, blue);
		drawPixel(i, j + 1, red, green, blue);
		drawPixel(i, j - 1, red, green, blue);
	}

}

class GeometricObjectInterface {
public:
	//implement here
	virtual void draw() = 0;
};
template<class T_OPERATION>
class GeometricObject :public GeometricObjectInterface{
public:
	void draw()
	{
		T_OPERATION op;
		op.draw();
	}
};
class Box {
public:
	//some variables
	int x = 100;
	int y = 300;
	int size = 80;
	float red = 1.0f;
	float green = 0.0f;
	float blue = 1.0f;

	void draw() {
		int j_start = y - size;
		int j_end = y + size;
		for (int j = j_start; j <= j_end; j++) {
			int i_start = x - size;
			int i_end = x + size;
			for (int i = i_start; i <= i_end; i++) {
				if (j == j_start || j == j_end || i == i_start || i == i_end) {
					drawPixel(i, j, red, green, blue);
					drawPixel(i - 1, j, red, green, blue);
					drawPixel(i + 1, j, red, green, blue);
					drawPixel(i, j - 1, red, green, blue);
					drawPixel(i, j + 1, red, green, blue);
				}
			}
		}
	}
};
class Circle {
public:
	//some variables
	void draw() {
		int x = 300;
		int y = 100;
		int size = 80;
		float red = 0.0f;
		float green = 0.0f;
		float blue = 1.0f;
		//draw circle here
		for (int i = 0; i<20; i++)
		{
			double rad = size + i*0.01 - 20;
			for (double i = 0.0; i < 360.0; i += 0.1)
			{
				double angle = i *  M_PI / 180;

				int x_ = (int)(x + rad * cos(angle));
				int y_ = (int)(y + rad * sin(angle));
				drawPixel(x_ + 0, y_, red, green, blue);
				drawPixel(x_ + 1, y_, red, green, blue);
				drawPixel(x_, y_ + 1, red, green, blue);
			}
		}
	}
};
std::vector<GeometricObjectInterface*> obj_list;
void drawOnPixelBuffer(double xpos, double ypos)
{
	//std::memset(pixels, 1.0f, sizeof(float)*width*height * 3); // doesn't work
	//std::fill_n(pixels, width*height * 3, 1.0f);	// white background

	// »Úªˆ πË∞Ê
	for (int i = 0; i<width*height; i++) {
		pixels[i * 3 + 0] = 1.0f; // red 
		pixels[i * 3 + 1] = 1.0f; // green
		pixels[i * 3 + 2] = 1.0f; // blue
	}
	//draw here
	obj_list.push_back(new GeometricObject<Circle>);
	obj_list.push_back(new GeometricObject<Box>);
	//[TODO]
	const int i = rand() % width, j = rand() % height;
	drawPixel(i, j, 0.0f, 0.0f, 0.0f);
	for (auto itr : obj_list)
		itr->draw();
	obj_list.clear();
}
int main(void)
{
	GLFWwindow* window;

	/* Initialize the library */
	if (!glfwInit())
		return -1;

	/* Create a windowed mode window and its OpenGL context */
	window = glfwCreateWindow(width, height, "Hello World", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		return -1;
	}

	/* Make the window's context current */
	glfwMakeContextCurrent(window);
	glClearColor(1, 1, 1, 1); // while background
	bool inside = false;
	/* Loop until the user closes the window */
	while (!glfwWindowShouldClose(window))
	{
		/* Render here */
		glClear(GL_COLOR_BUFFER_BIT);

		/* get Cursor pos */
		double xpos, ypos;
		glfwGetCursorPos(window, &xpos, &ypos);
		


		/* ALL Drawing Function is here */
		drawOnPixelBuffer(xpos, ypos);
		
		/* Drawing Buffer on window */
		glDrawPixels(width, height, GL_RGB, GL_FLOAT, pixels);

		/* Swap front and back buffers */
		glfwSwapBuffers(window);

		/* Poll for and process events */
		glfwPollEvents();

		//std::this_thread::sleep_for(std::chrono::milliseconds(10));
	}

	glfwTerminate();

	delete[] pixels; // or you may reuse pixels array 

	return 0;
}
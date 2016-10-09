#include "main.h"
#include "Shape.h"
#include "Circle.h"
#include "draw.h"
#include "Triangle.h"
#include <vector>
using namespace std;
vector<Shape*> shape_list;
void drawPixel(const int& i, const int& j, const float& red, const float&green, const float& blue)
{
	pixels[(i + width* j) * 3 + 0] = red;
	pixels[(i + width* j) * 3 + 1] = green;
	pixels[(i + width* j) * 3 + 2] = blue;
}


/*
void getMousePoint(GLFWwindow* window) {
double xpose, ypose;
glfwGetCursorPos(window, &xpos, &ypos);
}
*/
// scratched from https://courses.engr.illinois.edu/ece390/archive/archive-f2000/mp/mp4/anti.html
// see 'Rasterization' part.

void drawLine(const int& i0, const int& j0, const int& i1, const int& j1, const float& red, const float& green, const float& blue)
{
	if (i1 - i0 == 0) {
		for (int i = j0; i <= j1; i++) {
			drawPixel(i0 + 0, i,red,green,blue);
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
void drawThicknerLine(const int& thickness, const int& i0, const int& j0, const int& i1, const int& j1, const float& red, const float& green, const float& blue) {
	/*
	for (int i = i0; i <= i1; i++)
	{
	const int j = (j1 - j0)*(i - i0) / (i1 - i0) + j0;
	for (int k = 0; k < thickness; k++) {
	drawPixel(i + k, j, red, green, blue);
	}
	}
	*/
	for (int i = 0; i < thickness; i++)
		drawLine(i0 + i, j0, i1 + i, j1, red, green, blue);
}
void drawSquare(int thickness, const int& i0, const int& j0, const int& i1, const int& j1, const float& red, const float& green, const float& blue) {
	int i_center = (i0 + i1) / 2;
	int j_center = (j0 + j1) / 2;

	for (int j = j_center - thickness; j < j_center + thickness; j++) {
		for (int i = i_center - thickness; i < i_center + thickness; i++) {
			drawPixel(i, j, red, green, blue);
		}
	}
}
void drawPolygon() {
	/*
	//ø¿∞¢«¸
	int i_center = 120;
	int j_center = 130;
	int size = 10;
	int j_start = j_center - size;
	int j_end = j_center + size;
	for (int j = j_start; j <= j_end + size; j++) {
	int i_start = i_center - size + (j / 5);
	int i_end = i_center + size - (j / 5);
	for (int i = i_start; i <= i_end; i++) {
	//if(j == j_start || j == j_end || i == i_start || i == i_end)
	drawPixel(i, j, 1.0f, 0.0f, 0.0f);
	}
	}
	*/
	drawLine(500, 200, 550, 200, 0.0f, 0.0f, 0.0f);
	drawLine(480, 250, 525, 290, 0.0f, 0.0f, 0.0f);
	drawLine(525, 290, 570, 250, 0.0f, 0.0f, 0.0f);

	drawLine(480, 250, 500, 200, 0.0f, 0.0f, 0.0f);
	drawLine(480, 251, 500, 201, 0.0f, 0.0f, 0.0f);

	drawLine(550, 200, 570, 250, 0.0f, 0.0f, 0.0f);
	drawLine(550, 201, 570, 251, 0.0f, 0.0f, 0.0f);
}



/*
void drawTriangle( {
int i_center = 100;
int j_center = 100;
int size = 70;
int j_start = j_center - size;
int j_end = j_center + size;
for (int j = j_start; j <= j_end; j++) {
int i_start = i_center - size + (j / 2);
int i_end = i_center + size - (j / 2);
for (int i = i_start; i <= i_end; i++) {
if (j == j_start || j == j_end || i == i_start || i == i_end)
drawPixel(i, j, 1.0f, 0.0f, 0.0f);
}
}
}
*/
void drawEmptySquare(int size, const int& i0, const int& j0, const int& i1, const int& j1, const float& red, const float& green, const float& blue) {
	int i_center = (i0 + i1) / 2;
	int j_center = (j0 + j1) / 2;

	for (int j = j_center - size; j <= j_center + size; j++) {
		//for (int i = i_center - thickness; i < i_center + thickness; i++) {
		for (int i = i_center - size; i <= i_center + size; i = i + size * 2)
		{
			drawPixel(i + 0, j, red, green, blue);
			drawPixel(i + 1, j, red, green, blue);
			drawPixel(i - 1, j, red, green, blue);
			drawPixel(i, j + 1, red, green, blue);
			drawPixel(i, j - 1, red, green, blue);
		}

	}
	//for (int j = j_center - thickness; j < j_center + thickness; j++) {
	for (int i = i_center - size; i <= i_center + size; i++) {
		for (int j = j_center - size; j <= j_center + size; j = j + size * 2) {
			drawPixel(i + 0, j, red, green, blue);
			drawPixel(i + 1, j, red, green, blue);
			drawPixel(i - 1, j, red, green, blue);
			drawPixel(i, j + 1, red, green, blue);
			drawPixel(i, j - 1, red, green, blue);
		}
	}
}
void heightLine(const int& i0, const int& j0, const int& i1, const int& j1, const float& red, const float& green, const float& blue) {
	//for (int i = i0; i <= i1; i++)
	//
	for (int i = 0; i<50; i++)
	{

		drawPixel(i0, j0 - i, red, green, blue);
		drawPixel(i0 - 1, j0 - i, red, green, blue);
		drawPixel(i0 + 1, j0 - i, red, green, blue);
	}
}
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

	const int i = rand() % width, j = rand() % height;
	drawPixel(i, j, 0.0f, 0.0f, 0.0f);
	
	Shape sh;
	
	// drawing a line
	shape_list.push_back(sh.getShape("Box"));
	shape_list.push_back(sh.getShape("Circle"));
	shape_list.push_back(sh.getShape("Triangle"));
		int tx = 110;
		int ty = 130;
		int size = 40;
		for (auto itr : shape_list) {
			itr->setPosition(tx, ty);
			tx += 100;
			ty += 10;
			if (tx > 540) {
				tx = 30;
				ty += 50;
			}

			itr->setSize(size);
			size += 5;
			itr->draw();
			itr->drawCircle(xpos,ypos);
		}
		shape_list.clear();

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
		//printf("%04.1lf\t%04.1lf\n", xpos, ypos);

		/* ALL Drawing Function is here */
		drawOnPixelBuffer(xpos, ypos);

		/* Drawing Buffer on window */
		glDrawPixels(width, height, GL_RGB, GL_FLOAT, pixels);

		/* Swap front and back buffers */
		glfwSwapBuffers(window);

		/* Poll for and process events */
		glfwPollEvents();

		std::this_thread::sleep_for(std::chrono::milliseconds(100));
	}

	glfwTerminate();

	delete[] pixels; // or you may reuse pixels array 

	return 0;
}
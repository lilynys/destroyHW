#include "main.h"

using namespace std;
vector<Shape*> shape_list;
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
	shape_list.push_back(sh.getShape("Star"));
	shape_list.push_back(sh.getShape("Snow"));
	shape_list.push_back(sh.getShape("Cross"));
	shape_list.push_back(sh.getShape("Sandglass"));
	shape_list.push_back(sh.getShape("Arrow"));
	shape_list.push_back(sh.getShape("Plus"));
	shape_list.push_back(sh.getShape("Rect"));
		int tx = 100;
		int ty = 130;
		int size = 50;
		for (int i = 0; i < 2; i++) {
			for (auto itr : shape_list) {
				itr->setPosition(tx, ty);
				tx += 150;
				if (tx > 700) {
					tx = 100;
					ty += 130;
				}

				itr->setSize(size);

				itr->draw();
				itr->drawCircle(xpos, ypos);
			}
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

		//std::this_thread::sleep_for(std::chrono::milliseconds(10));
	}

	glfwTerminate();

	delete[] pixels; // or you may reuse pixels array 

	return 0;
}
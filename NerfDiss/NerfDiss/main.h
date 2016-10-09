#include <GLFW/glfw3.h>
#include <cstring>
#include <stdlib.h>		  // srand, rand
#include <thread>         // std::this_thread::sleep_for
#include <chrono>         // std::chrono::seconds
#include "Shape.h"
#include "Circle.h"
#include "draw.h"
#include "Triangle.h"
#include "Snow.h"
#include <vector>

//glfw
const int width = 800;
const int height = 800;

float* pixels = new float[width*height * 3];
GLFWwindow* window;



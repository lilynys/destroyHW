#include <GLFW/glfw3.h>
#include <cstring>
#include <stdlib.h>		  // srand, rand
#include <thread>         // std::this_thread::sleep_for
#include <chrono>         // std::chrono::seconds


//glfw
const int width = 800;
const int height = 800;

float* pixels = new float[width*height * 3];
GLFWwindow* window;



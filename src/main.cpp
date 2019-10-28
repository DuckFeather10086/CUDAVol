/*
  Copyright (c) 2019 Mark van de Ruit

  Permission is hereby granted, free of charge, to any person obtaining a copy
  of this software and associated documentation files (the "Software"), to deal
  in the Software without restriction, including without limitation the rights
  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
  copies of the Software, and to permit persons to whom the Software is
  furnished to do so, subject to the following conditions:

  The above copyright notice and this permission notice shall be included in all
  copies or substantial portions of the Software.

  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
  SOFTWARE.

  #############################################################################

  main.cpp

  Main source file, application starting point.

  October 2019
*/

#include "GL/glew.h"
#include "GLFW/glfw3.h"
#include "glm/glm.hpp"
#include <iostream>

int main(int argc, char **argv) {
  // Initialize GLFW
  if (auto c = glfwInit(); !c) {
    std::cerr << "GLFW initialization returned code " << c << std::endl;
    return EXIT_FAILURE;
  }

  // Create rendering context and window
  GLFWwindow *window = glfwCreateWindow(256, 256, "CUDAVol", nullptr, nullptr);
  if (!window) {
    std::cerr << "Window initialization failed" << std::endl;
    return EXIT_FAILURE;
  }
  glfwMakeContextCurrent(window);

  // Check GL
  if (auto c = glGetError(); c != GL_NO_ERROR) {
    std::cerr << "glGetError() returned code " << c << std::endl;
    return EXIT_FAILURE;
  }

  // Initialize GLEW
  if (auto c = glewInit(); c != GLEW_OK) {
    std::cerr << "GLEW initialization returned code " << c << std::endl;
    return EXIT_FAILURE;
  }

  std::cout << "Hello OpenGL" << std::endl;
  while (!glfwWindowShouldClose(window)) {
    // ...
    glfwPollEvents();
  }
  std::cout << "Goodbye OpenGL" << std::endl;

  return EXIT_SUCCESS;
}
// Include standard headers
#include <stdio.h>
#include <stdlib.h>

// Include GLEW
#include <GL/glew.h>

// Include GLFW
#include <GLFW/glfw3.h>
GLFWwindow* window;

// Include GLM
#include <glm/glm.hpp>
using namespace glm;

#include <common/shader.hpp>

int main(void)
{
	// Initialise GLFW
	if (!glfwInit())
	{
		fprintf(stderr, "Failed to initialize GLFW\n");
		getchar();
		return -1;
	}

	glfwWindowHint(GLFW_SAMPLES, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // To make MacOS happy; should not be needed
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	// Open a window and create its OpenGL context
	window = glfwCreateWindow(800, 600, "Tugas 2", NULL, NULL);
	if (window == NULL) {
		fprintf(stderr, "Failed to open GLFW window. If you have an Intel GPU, they are not 3.3 compatible. Try the 2.1 version of the tutorials.\n");
		getchar();
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);

	// Initialize GLEW
	glewExperimental = true; // Needed for core profile
	if (glewInit() != GLEW_OK) {
		fprintf(stderr, "Failed to initialize GLEW\n");
		getchar();
		glfwTerminate();
		return -1;
	}

	// Ensure we can capture the escape key being pressed below
	glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);

	// Dark blue background
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

	GLuint VertexArrayID;
	glGenVertexArrays(1, &VertexArrayID);
	glBindVertexArray(VertexArrayID);

	// Create and compile our GLSL program from the shaders
	GLuint programID = LoadShaders("TransformVertexShader.vertexshader", "ColorFragmentShader.fragmentshader");


	static const GLfloat g_vertex_buffer_data[] = {
		-0.7f, -0.05f, 0.0f, //1//left wing
		-0.5f,   0.0f, 0.0f,
		-0.5f,  -0.1f, 0.0f,
		-0.5f, 	 0.0f, 0.0f, //2
		-0.5f,  -0.1f, 0.0f,
		-0.4f,   0.0f, 0.0f,
		-0.4f,   0.0f, 0.0f, //3
	   -0.45f, -0.05f, 0.0f,
	    -0.4f, -0.15f, 0.0f,
		-0.4f, 0.0f, 0.0f, //4
		-0.4f, -0.15f, 0.0f,
		-0.3f, 0.0f, 0.0f,
		-0.3f, 0.0f, 0.0f, //5
		-0.35f, -0.075f, 0.0f,
		-0.3f, -0.2f, 0.0f,
		-0.3f, 0.0f, 0.0f, //6
		-0.3f, -0.1f, 0.0f,
		-0.2f, 0.0f, 0.0f,
		-0.2f, 0.0f, 0.0f, //7
		-0.25f, -0.05f, 0.0f,
		-0.2f, -0.15f, 0.0f,
		-0.2f, 0.0f, 0.0f, //1//middle body
		-0.1f, -0.2f, 0.0f,
		-0.15f, -0.2f, 0.0f,
		-0.1f, -0.2f, 0.0f, //2
		-0.05f, -0.2f, 0.0f,
		0.0f, 0.0f, 0.0f,
		-0.2f, 0.0f, 0.0f, //3
		-0.1f, -0.2f, 0.0f,
		0.0f, 0.0f, 0.0f,
		-0.2f, 0.0f, 0.0f, //1//upper body
		-0.1f, 0.0f, 0.0f,
		-0.1f, 0.3f, 0.0f,
		0.0f, 0.0f, 0.0f, //2
		-0.1f, 0.0f, 0.0f,
		-0.1f, 0.3f, 0.0f,
		-0.17f, 0.2f, 0.0f,//1//head
		-0.1f, 0.3f, 0.0f,
		-0.1f, 0.5f, 0.0f,
		-0.03f, 0.2f, 0.0f, //2
		-0.1f, 0.3f, 0.0f,
		-0.1f, 0.5f, 0.0f,
		-0.05f, -0.2f, 0.0f, //1//lower body
		-0.15f, -0.2f, 0.0f,
		-0.1f, -1.0f, 0.0f,
		0.0f, 0.0f, 0.0f, //1//right wing
		0.0f, -0.15f, 0.0f,
		0.05f, -0.05f, 0.0f,
		0.0f, 0.0f, 0.0f, //2
		0.1f, 0.0f, 0.0f,
		0.1f, -0.1f, 0.0f,
		0.1f, 0.0f, 0.0f, //3
		0.1f, -0.2f, 0.0f,
		0.15f, -0.075f, 0.0f,
		0.2f, 0.0f, 0.0f, //4
		0.2f, -0.15f, 0.0f,
		0.1f, 0.0f, 0.0f,
		0.2f, 0.0f, 0.0f, //5
		0.25f, -0.05f, 0.0f,
		0.2f, -0.15f, 0.0f,
		0.3f, 0.0f, 0.0f, //6
		0.3f, -0.1f, 0.0f,
		0.2f, 0.0f, 0.0f,
		0.5f, -0.05f, 0.0f, //7
		0.3f, 0.0f, 0.0f,
		0.3f, -0.1f, 0.0f,
		0.2f, 0.3f, 0.0f, // pentagon
		0.4f, 0.9f, 0.0f,
		0.6f, 0.3f, 0.0f,
		0.2f, 0.3f, 0.0f,
		0.4f, 0.9f, 0.0f,
		0.1f, 0.65f, 0.0f,
		0.7f, 0.65f, 0.0f,
		0.4f, 0.9f, 0.0f,
		0.6f, 0.3f, 0.0f,
	};

	static const GLfloat g_color_buffer_data[] = {
		0.583f,  0.771f,  0.014f, //1
		0.609f,  0.115f,  0.436f,
		0.327f,  0.483f,  0.844f,
		0.822f,  0.569f,  0.201f, //2
		0.435f,  0.602f,  0.223f,
		0.310f,  0.747f,  0.185f,
		0.822f,  0.569f,  0.201f, //3
		0.435f,  0.602f,  0.223f,
		0.310f,  0.747f,  0.185f,
		0.822f,  0.569f,  0.201f, //4
		0.435f,  0.602f,  0.223f,
		0.310f,  0.747f,  0.185f,
		0.435f,  0.602f,  0.223f, //5
		0.310f,  0.747f,  0.185f,
		0.822f,  0.569f,  0.201f,
		0.609f,  0.115f,  0.436f, //6
		0.327f,  0.483f,  0.844f,
		0.822f,  0.569f,  0.201f,
		0.609f,  0.115f,  0.436f, //7
		0.327f,  0.483f,  0.844f,
		0.822f,  0.569f,  0.201f,
		0.310f,  0.747f,  0.185f, //1
		0.822f,  0.569f,  0.201f, 
		0.435f,  0.602f,  0.223f,
		0.310f,  0.747f,  0.185f, //2
		0.822f,  0.569f,  0.201f, 
		0.435f,  0.602f,  0.223f,
		0.310f,  0.747f,  0.185f, //3
		0.435f,  0.602f,  0.223f, 
		0.310f,  0.747f,  0.185f,
		0.310f,  0.747f,  0.185f, //1
		0.822f,  0.569f,  0.201f,
		0.435f,  0.602f,  0.223f,
		0.310f,  0.747f,  0.185f, //2
		0.435f,  0.602f,  0.223f,
		0.310f,  0.747f,  0.185f,
		0.310f,  0.747f,  0.185f, //1
		0.435f,  0.602f,  0.223f,
		0.310f,  0.747f,  0.185f,
		0.310f,  0.747f,  0.185f, //2
		0.435f,  0.602f,  0.223f,
		0.310f,  0.747f,  0.185f,
		0.310f,  0.747f,  0.185f, //1
		0.435f,  0.602f,  0.223f,
		0.310f,  0.747f,  0.185f,
		0.609f,  0.115f,  0.436f, //1
		0.327f,  0.483f,  0.844f,
		0.822f,  0.569f,  0.201f,
		0.609f,  0.115f,  0.436f, //2
		0.327f,  0.483f,  0.844f,
		0.822f,  0.569f,  0.201f,
		0.435f,  0.602f,  0.223f, //3
		0.310f,  0.747f,  0.185f,
		0.822f,  0.569f,  0.201f,
		0.822f,  0.569f,  0.201f, //4
		0.435f,  0.602f,  0.223f,
		0.310f,  0.747f,  0.185f,
		0.822f,  0.569f,  0.201f, //5
		0.435f,  0.602f,  0.223f,
		0.310f,  0.747f,  0.185f,
		0.822f,  0.569f,  0.201f, //6
		0.435f,  0.602f,  0.223f,
		0.310f,  0.747f,  0.185f,
		0.583f,  0.771f,  0.014f, //7
		0.609f,  0.115f,  0.436f,
		0.327f,  0.483f,  0.844f,
		0.5f, 0.0f, 0.0f, // pentagon
		0.5f, 0.0f, 0.0f,
		0.5f, 0.0f, 0.0f,
		0.0f, 0.1f, 0.0f,
		0.0f, 0.4f, 0.0f,
		0.0f, 0.3f, 0.0f,
		0.0f, 0.0f, 0.6f,
		0.0f, 0.0f, 0.7f,
		0.0f, 0.0f, 0.8f,
	};

	GLuint vertexbuffer;
	glGenBuffers(1, &vertexbuffer);
	glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(g_vertex_buffer_data), g_vertex_buffer_data, GL_STATIC_DRAW);

	GLuint colorbuffer;
	glGenBuffers(1, &colorbuffer);
	glBindBuffer(GL_ARRAY_BUFFER, colorbuffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(g_color_buffer_data), g_color_buffer_data, GL_STATIC_DRAW);

	do {

		// Clear the screen
		glClear(GL_COLOR_BUFFER_BIT);

		// Use our shader
		glUseProgram(programID);

		// 1rst attribute buffer : vertices
		glEnableVertexAttribArray(0);
		glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
		glVertexAttribPointer(
			0,                  // attribute 0. No particular reason for 0, but must match the layout in the shader.
			3,                  // size
			GL_FLOAT,           // type
			GL_FALSE,           // normalized?
			0,                  // stride
			(void*)0            // array buffer offset
		);

		// 2nd attribute buffer : colors
		glEnableVertexAttribArray(1);
		glBindBuffer(GL_ARRAY_BUFFER, colorbuffer);
		glVertexAttribPointer(
			1,                                // attribute. No particular reason for 1, but must match the layout in the shader.
			3,                                // size
			GL_FLOAT,                         // type
			GL_FALSE,                         // normalized?
			0,                                // stride
			(void*)0                          // array buffer offset
		);

		// Draw the triangle !
		glDrawArrays(GL_TRIANGLES, 0, 25*3); // 3 indices starting at 0 -> 1 triangle

		glDisableVertexAttribArray(0);

		// Swap buffers
		glfwSwapBuffers(window);
		glfwPollEvents();

	} // Check if the ESC key was pressed or the window was closed
	while (glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS &&
		glfwWindowShouldClose(window) == 0);

	// Cleanup VBO
	glDeleteBuffers(1, &vertexbuffer);
	glDeleteVertexArrays(1, &VertexArrayID);
	glDeleteProgram(programID);

	// Close OpenGL window and terminate GLFW
	glfwTerminate();

	return 0;
}


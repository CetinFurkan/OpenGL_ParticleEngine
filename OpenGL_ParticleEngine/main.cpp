#include <GLFW/glfw3.h>
#include "ParticleSystem.h"


int main(void)
{
	GLFWwindow* window;
	ParticleSystem* particleTest = new ParticleSystem();

	particleTest->init();

	/* Initialize the library */
	if (!glfwInit())
		return -1;

	/* Create a windowed mode window and its OpenGL context */
	window = glfwCreateWindow(1024, 768, "Hello World", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		return -1;
	}

	/* Make the window's context current */
	glfwMakeContextCurrent(window);

	glEnable(GL_POINT_SMOOTH);


	/* Loop until the user closes the window */
	while (!glfwWindowShouldClose(window))
	{
		glClearColor(.0, .0, .0, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glViewport(0, 0, 1024, 768);
		glMatrixMode(GL_PROJECTION);
		//gluPerspective( 65.0, (double)1024/(double)768, 1.0, 60.0 );
		glLoadIdentity();
		glOrtho(0, 1024, 768, 0, 100, -100);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();

		particleTest->update();
		glColor4f(1, 1, 1, 1);

		for (int i = 0; i < particleTest->getSize(); i++) {

			glPointSize(particleTest->pp[i].size);
			glBegin(GL_POINTS);
			glVertex3f(particleTest->pp[i].x, particleTest->pp[i].y, 0);
			glEnd();
			
		}
		//glFlush();

		/* Swap front and back buffers */
		glfwSwapBuffers(window);

		/* Poll for and process events */
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;
}
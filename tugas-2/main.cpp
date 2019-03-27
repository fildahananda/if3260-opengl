/*
 * GL01Hello.cpp: Test OpenGL C/C++ Setup
 */
//#include <windows.h>  // For MS Windows
//#include <glut.h>  // GLUT, includes glu.h and gl.h



//For Macbook: - comment if in another OS
#include <OpenGL/gl.h>
#include <OpenGl/glu.h>
#include <GLUT/glut.h>

/* Handler for window-repaint event. Call back when the window first appears and
 whenever the window needs to be re-painted. */
void display() {
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Set background color to black and opaque
	glClear(GL_COLOR_BUFFER_BIT);         // Clear the color buffer
	
	// start of left wing
	
	glBegin(GL_TRIANGLES);
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex2f(-0.7f, -0.05f);
	glVertex2f(-0.5f, 0.0f);
	glVertex2f(-0.5f, -0.1f);
	
	glBegin(GL_TRIANGLES);
	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex2f(-0.5f, 0.0f);
	glVertex2f(-0.5f, -0.1f);
	glVertex2f(-0.4f, 0.0f);
	
	glBegin(GL_TRIANGLES);
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex2f(-0.4f, 0.0f);
	glVertex2f(-0.45f, -0.05f);
	glVertex2f(-0.4f, -0.15f);
	
	glBegin(GL_TRIANGLES);
	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex2f(-0.4f, 0.0f);
	glVertex2f(-0.4f, -0.15f);
	glVertex2f(-0.3f, 0.0f);
	
	glBegin(GL_TRIANGLES);
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex2f(-0.3f, 0.0f);
	glVertex2f(-0.35f, -0.075f);
	glVertex2f(-0.3f, -0.2f);
	
	glBegin(GL_TRIANGLES);
	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex2f(-0.3f, 0.0f);
	glVertex2f(-0.3f, -0.1f);
	glVertex2f(-0.2f, 0.0f);
	
	glBegin(GL_TRIANGLES);
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex2f(-0.2f, 0.0f);
	glVertex2f(-0.25f, -0.05f);
	glVertex2f(-0.2f, -0.15f);
	
	// end of left wing
	
	/**/
	
	// start of middle body
	
	glBegin(GL_TRIANGLES);
	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex2f(-0.2f, 0.0f);
	glVertex2f(-0.1f, -0.2f);
	glVertex2f(-0.15f, -0.2f);
	
	glBegin(GL_TRIANGLES);
	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex2f(-0.1f, -0.2f);
	glVertex2f(-0.05f, -0.2f);
	glVertex2f(0.0f, 0.0f);
	
	glBegin(GL_TRIANGLES);
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex2f(-0.2f, 0.0f);
	glVertex2f(-0.1f, -0.2f);
	glVertex2f(0.0f, 0.0f);
	
	// end of middle body
	
	/**/
	
	// start of upper body
	
	glBegin(GL_TRIANGLES);
	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex2f(-0.2f, 0.0f);
	glVertex2f(-0.1f, 0.0f);
	glVertex2f(-0.125f, 0.5f);
	
	glBegin(GL_TRIANGLES);
	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex2f(-0.1f, 0.0f);
	glVertex2f(-0.075f, 0.5f);
	glVertex2f(-0.125f, 0.5f);
	
	glBegin(GL_TRIANGLES);
	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex2f(0.0f, 0.0f);
	glVertex2f(-0.1f, 0.0f);
	glVertex2f(-0.075f, 0.5f);
	
	// end of upper body
	
	/**/
	
	// start of head
	
	glBegin(GL_TRIANGLES);
	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex2f(-0.075f, 0.5f);
	glVertex2f(-0.125f, 0.5f);
	glVertex2f(-0.1f, 0.6f);

	glBegin(GL_TRIANGLES);
	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex2f(-0.125f, 0.5f);
	glVertex2f(-0.2f, 0.55f);
	glVertex2f(-0.1f, 0.6f);
	
	glBegin(GL_TRIANGLES);
	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex2f(-0.1f, 0.6f);
	glVertex2f(-0.2f, 0.55f);
	glVertex2f(-0.2f, 0.65f);

	glBegin(GL_TRIANGLES);
	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex2f(-0.1f, 0.6f);
	glVertex2f(-0.2f, 0.65f);
	glVertex2f(-0.125f, 0.7f);
	
	glBegin(GL_TRIANGLES);
	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex2f(-0.1f, 0.6f);
	glVertex2f(-0.125f, 0.7f);
	glVertex2f(-0.075f, 0.7f);

	glBegin(GL_TRIANGLES);
	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex2f(-0.1f, 0.6f);
	glVertex2f(0.0f, 0.65f);
	glVertex2f(-0.075f, 0.7f);
	
	glBegin(GL_TRIANGLES);
	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex2f(-0.1f, 0.6f);
	glVertex2f(0.0f, 0.55f);
	glVertex2f(0.0f, 0.65f);
	
	glBegin(GL_TRIANGLES);
	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex2f(-0.1f, 0.6f);
	glVertex2f(-0.075f, 0.5f);
	glVertex2f(-0.0f, 0.55f);
	
	// end of head
	
	/**/
	
	// start of lower body
	
	glBegin(GL_TRIANGLES);
	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex2f(-0.05f, -0.2f);
	glVertex2f(-0.15f, -0.2f);
	glVertex2f(-0.1f, -0.8f);
	
	// end of lower body
	
	/**/
	
	// start of right wing
	
	glBegin(GL_TRIANGLES);
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex2f(0.0f, 0.0f);
	glVertex2f(0.0f, -0.15f);
	glVertex2f(0.05f, -0.05f);
	
	glBegin(GL_TRIANGLES);
	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex2f(0.0f, 0.0f);
	glVertex2f(0.1f, 0.0f);
	glVertex2f(0.1f, -0.1f);
	
	glBegin(GL_TRIANGLES);
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex2f(0.1f, 0.0f);
	glVertex2f(0.1f, -0.2f);
	glVertex2f(0.15f, -0.075f);
	
	glBegin(GL_TRIANGLES);
	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex2f(0.2f, 0.0f);
	glVertex2f(0.2f, -0.15f);
	glVertex2f(0.1f, 0.0f);
	
	glBegin(GL_TRIANGLES);
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex2f(0.2f, 0.0f);
	glVertex2f(0.25f, -0.05f);
	glVertex2f(0.2f, -0.15f);
	
	glBegin(GL_TRIANGLES);
	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex2f(0.3f, 0.0f);
	glVertex2f(0.3f, -0.1f);
	glVertex2f(0.2f, 0.0f);
	
	glBegin(GL_TRIANGLES);
  glColor3f(0.0f, 0.0f, 1.0f);
	glVertex2f(0.5f, -0.05f);
	glVertex2f(0.3f, 0.0f);
	glVertex2f(0.3f, -0.1f);
	
	// end of right wing
	
	
	//      glColor3f(0.0f, 0.0f, 1.0f); // Red
	//      glVertex2f(-0.2f, -0.5f);    // x, y // harus dalam urutan vertex yg benar
	//      glVertex2f( 0.4f, -0.5f);
	//      glVertex2f(0.6f, 0.0f);
	//      glVertex2f( 0.1f,  0.45f);
	//      glVertex2f(-0.4f,  0.0f);
	
	glEnd();
	
	// Draw the triangle !
	glDrawArrays(GL_TRIANGLES, 0, 3); // Starting from vertex 0; 3 vertices total -> 1 triangle
	//glDisableVertexAttribArray(0);
	
	glFlush();  // Render now
}

/* Main function: GLUT runs as a console application starting at main()  */
int main(int argc, char** argv) {
	glutInit(&argc, argv);                 // Initialize GLUT
	glutCreateWindow("OpenGL Setup Test"); // Create a window with the given title
	glutInitWindowSize(320, 320);   // Set the window's initial width & height
	glutInitWindowPosition(50, 50); // Position the window's initial top-left corner
	glutDisplayFunc(display); // Register display callback handler for window re-paint
	glutMainLoop();           // Enter the infinitely event-processing loop
	return 0;
}

/* compile & run
 g++ -O0 -g3 -Wall -c -fmessage-length=0 -o pentagon.o pentagon.cpp 
 
 g++ -o pentagon.exe pentagon.o -lglu32 -lopengl32 -lfreeglut
 */

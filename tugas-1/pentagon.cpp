/*
 * GL01Hello.cpp: Test OpenGL C/C++ Setup
 */
#include <windows.h>  // For MS Windows
#include <GL/glut.h>  // GLUT, includes glu.h and gl.h
 
/* Handler for window-repaint event. Call back when the window first appears and
   whenever the window needs to be re-painted. */
void display() {
   glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Set background color to black and opaque
   glClear(GL_COLOR_BUFFER_BIT);         // Clear the color buffer
 
   // Draw a Red 1x1 Square centered at origin
   glBegin(GL_POLYGON);              // Each set of 4 vertices form a quad // bisa diubah jadi GL_QUADS, GL_TRIANGLES, dll
      glColor3f(1.0f, 0.0f, 0.0f); // Red
      glVertex2f(-0.2f, -0.3f);    // x, y // harus dalam urutan vertex yg benar
      
      glVertex2f( 0.4f, -0.5f);
      glVertex2f(0.7f, 0.0f);
      glVertex2f( 0.4f,  0.5f);
      glVertex2f(-0.2f,  0.3f);
      
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

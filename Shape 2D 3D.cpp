#include <GL/glut.h>
#include <GL/freeglut.h>
/*
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met:
 *
 * * Redistributions of source code must retain the above copyright
 *   notice, this list of conditions and the following disclaimer.
 * * Redistributions in binary form must reproduce the above
 *   copyright notice, this list of conditions and the following disclaimer
 *   in the documentation and/or other materials provided with the
 *   distribution.
 * * Neither the name of the ImanchaOS nor the names of its
 *   contributors may be used to endorse or promote products derived from
 *   this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 */

using namespace std;

void init(void){
	GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 }; //parameter cahaya specular
	GLfloat mat_shininess[] = { 100.0 }; //parameter shininess
	GLfloat light_position[] = { 1.0, -0.5, 1.0, 1.0 }; //parameter posisi pencahayaan

	glClearColor(0.48, 0.10, 0.36, 0.5);

	glShadeModel(GL_SMOOTH); //mengaktifkan shade model
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);
	glEnable(GL_LIGHTING); //mengaktifkan pencahayaan
	glEnable(GL_LIGHT0); //mengaktifkan sumber cayaha
	glEnable(GL_NORMALIZE);
  glShadeModel(GL_SMOOTH);
	GLfloat lightColor0[] = {0.7f, 0.7f, 0.7f, 1.0f};	//add positioned light
	GLfloat lightPos0[] = {5.5f, 7.5f, 5.5f, 1.0f};
	glLightfv(GL_LIGHT0, GL_DIFFUSE, lightColor0);
	glLightfv(GL_LIGHT0, GL_POSITION, lightPos0);

	glPopMatrix();
	glEnable(GL_DEPTH_TEST);

//	glOrtho(0.0, 1.0, 1.0, 0.0, -1.0, 1.0);	//	(left, right, bottom, top, near/front, far/rear)
}

void reshape(int w, int h){
	glViewport(0, 0, (GLsizei) w, (GLsizei) h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	if (w <= h)
		glOrtho(-1.5, 1.5, -1.5*(GLfloat)h/(GLfloat)w, 1.5*(GLfloat)h/(GLfloat)w, -10.0, 10.0);
	else
		glOrtho(-1.5*(GLfloat)w/(GLfloat)h, 1.5*(GLfloat)w/(GLfloat)h, -1.5, 1.5, -10.0, 10.0);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt (0.0, 0.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
}

void display(void){
	/* clear all pixels */
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glEnable(GL_COLOR_MATERIAL); //mengaktifkan fungsi untuk memberikan warna pada material
	glColorMaterial(GL_FRONT, GL_DIFFUSE); //parameter-parameter fungsi warna material
	
	//	1.1
	glPushMatrix();
		glColor3d(0.8, 0.8, 0.8);
		glTranslated(-1.89, 1.24, 0.0);
		glutWireSphere(0.25, 50, 8);
	glPopMatrix();

	//	1.2
	glPushMatrix();
		glColor3d(0.8, 0.8, 0.8);
		glScaled(0.16, 0.16, 0.0);
		glTranslated(-8.0, 7.6, 0.0);
		glRotated(30, 1.0, 0.3, 0.0);
		glutWireDodecahedron();
	glPopMatrix();

	//	1.3
	glPushMatrix();
		glColor3d(0.8, 0.8, 0.8);
		glScaled(0.36, 0.36, 0.0);
		glTranslated(-1.7, 3.4, 0.0);
		glRotated(70, 0.4, 0.7, 0.5);
		glutWireOctahedron();
	glPopMatrix();

	//	1.4
	glPushMatrix();
		glColor3d(0.8, 0.8, 0.8);
		glTranslated(0.35, 1.22, 5.0);
		glRotated(30, 1.0, 0.5, 0.0);
		glScaled(1.9, 0.6, 1.0);
		glutWireCube(0.5);
	glPopMatrix();	

	// 1.5
	glPushMatrix();
		glColor3d(0.8, 0.8, 0.8);
		glScaled(0.4, 0.4, 0.0);
		glRotated(120, 0.3, 0.4, 0.1);
		glTranslated(2.45, 3.1, 2.0);
		glutWireTetrahedron();
	glPopMatrix();

	//	1.6
	glPushMatrix();
		glColor3d(0.8, 0.8, 0.8);
		glRotated(115.0, -0.5, 0.4, 0.0);
		glTranslated(-2.0, -3.68, 0.34);
		glutWireCone(0.3, 0.5, 40, 30);
	glPopMatrix();	
	
	//	2.1
	glPushMatrix();
		glColor3d(0.8, 0.8, 0.8);
		glTranslated(-1.85, 0.66, 0.0);
		glScaled(0.8, 0.9, 1.0);
		glutSolidTorus(0.1, 0.25, 50, 50);
	glPopMatrix();

	//	2.2
	glPushMatrix();
		glColor3d(0.8, 0.8, 0.8);
		glTranslated(-0.95, 0.65, 0.5);
		glutSolidTeapot(0.37);
	glPopMatrix();

	//	2.3
	glPushMatrix();
		glColor3d(0.8, 0.8, 0.8);
		glScaled(0.33, 0.33, 0.0);
		glRotated(50, 0.4, 0.6, 0.0);
		glTranslated(-0.55, 2.3, 0.0);
		glutSolidRhombicDodecahedron();
	glPopMatrix();

	//	2.4
	glPushMatrix();
		glColor3d(0.8, 0.8, 0.8);
		glTranslated(0.95, 0.65, 0.5);
		glRotated(180, 0.0, 1.0, 0.0);
		glutWireTeapot(0.37);
	glPopMatrix();

	//	2.5
	glPushMatrix();
		glColor3d(0.8, 0.8, 0.8);
		glScaled(0.3, 0.3, 0.0);
		glRotated(100, 0.9, 1.0, 0.0);
		glTranslated(2.8, 5.1, 3.0);
		glutWireIcosahedron();
	glPopMatrix();

	//	3.1
	glPushMatrix();
		glColor3d(0.8, 0.8, 0.8);
		glRotated(90, -1.0, 0.0, 0.0);
		glTranslated(-1.85, 0.0, -0.22);
		glutSolidCone(0.3, 0.55, 15, 1);
	glPopMatrix();

	//	3.2
	glPushMatrix();
		glColor3d(0.8, 0.8, 0.8);
		glTranslated(-1.25, 0.1, 0.0);
		glRotated(65, 0.0, 1.0, -0.7);
		glutSolidCylinder(0.25, 0.8, 50, 40);
	glPopMatrix();
	
	//	3.3
	glPushMatrix();
		glColor3d(0.8, 0.8, 0.8);
		glScaled(0.35, 0.35, 0.0);		
		glutSolidSphere(1.0, 50, 50);
	glPopMatrix();
	
	//	3.4
	glPushMatrix();
		glColor3d(0.8, 0.8, 0.8);
		glScaled(0.55, 0.45, 0.0);
		glTranslated(1.66, 0.0, 0.0);
		glRotated(-40, 0.0, 1.0, 0.7);
		glutSolidCube(1.0);
	glPopMatrix();

	//	3.5
	glPushMatrix();
		glColor3d(0.8, 0.8, 0.8);
		glScaled(0.32, 0.32, 0.32);
		glTranslated(5.7, 0.0, 0.0);
		glutSolidOctahedron();
	glPopMatrix();

	//	4.1
	glPushMatrix();
		glColor3d(0.8, 0.8, 0.8);
		glTranslated(-1.9, -0.6, 0.0);
		glRotated(15, 0.2, 0.3, -0.7);
		glutSolidCone(0.35, 0.7, 3, 1);
	glPopMatrix();

	//	4.2
	glPushMatrix();
		glColor3d(0.8, 0.8, 0.8);
		glTranslated(-1.5, -0.8, 0.0);
		glBegin(GL_POLYGON);
			glVertex2d(0.0, 0.0);
			glVertex2d(1.0, 0.0);
			glVertex2d(0.5, 0.5);
		glEnd();
	glPopMatrix();

	//	4.3
	glPushMatrix();
		glColor3d(0.8, 0.8, 0.8);
		glTranslated(-0.25, -0.86, 0.0);
		glScaled(0.5, 0.5, 0.0);
		glBegin(GL_POLYGON);
			glVertex2d(0.0, 0.0);
			glVertex2d(1.0, 0.0);
			glVertex2d(1.0, 1.0);
			glVertex2d(0.0, 1.0);
		glEnd();
	glPopMatrix();

	//	4.4
	glPushMatrix();
		glColor3d(0.8, 0.8, 0.8);
		glTranslated(1.79, -0.68, 5.0);
		glScaled(0.4, 0.2, 0.1);		
		glutSolidSphere(1.0, 100, 3);
		glPushMatrix();
			glScaled(0.3, 1.0, 0.5);			
			glutSolidSphere(2.0, 100, 3);
		glPopMatrix();
	glPopMatrix();	

	//	4.5
	glPushMatrix();
		glColor3d(0.8, 0.8, 0.8);
		glTranslated(1.0, -0.65, 0.0);		
		glutSolidCone(0.3, 0.55, 8, 1);
	glPopMatrix();
		
	//	5.1
	glPushMatrix();
		glColor3d(0.8, 0.8, 0.8);
		glTranslated(-1.81, -1.185, 0.0);
		glRotated(45.0, -0.5, 0.5, 0.2);
		glutWireTorus(0.1, 0.25, 15, 25);
	glPopMatrix();

	//	5.2
	glPushMatrix();
		glColor3d(0.8, 0.8, 0.8);
		glRotated(45, 0.0, 0.5, 1.0);		
		glScaled(0.35, 0.35, 0.35);
		glTranslated(-6.1, 0.0, 4.8);
		glutSolidIcosahedron();
	glPopMatrix();

	//	5.3
	glPushMatrix();
		glColor3d(0.8, 0.8, 0.8);
		glTranslated(0.0, -1.185, 0.0);
		glScaled(0.19, 0.19, 0.0);
		glutSolidDodecahedron();
	glPopMatrix();

	//	5.4
	glPushMatrix();
		glColor3d(0.8, 0.8, 0.8);
		glTranslated(0.4, -1.49, 0.0);
		glScaled(0.5, 0.5, 0.0);
		glBegin(GL_POLYGON);
			glVertex2d(0.5, 0.5);
			glVertex2d(0.0, 0.0);
			glVertex2d(1.5, 0.0);
			glVertex2d(2.0, 0.5);
			glVertex2d(1.5, 1.0);
			glVertex2d(0.0, 1.0);
		glEnd();
	glPopMatrix();

	//	5.5
	glPushMatrix();
		glColor3d(0.8, 0.8, 0.8);
		glTranslated(1.78, -1.12, 0.0);
		glRotated(120.0, 1.0, 0.0, 0.3);
		glutWireCylinder(0.3, 0.25, 10, 20);
	glPopMatrix();

	glDisable(GL_COLOR_MATERIAL); //menonaktifkan fungsi untuk memberikan warna pada material
	glFlush ();
	glutPostRedisplay();
}



/*
 * Declare initial window size, position, and display mode
 * (single buffer and RGBA). Open window with “hello”
 * in its title bar. Call initialization routines.
 * Register callback function to display graphics.
 * Enter main loop and process events.
 **/

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowPosition(0,0);
	glutInitWindowSize(1024,768);
	glutCreateWindow("Shape 2D and 3D GLUT");
	init();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutMainLoop();
	return 0;
}

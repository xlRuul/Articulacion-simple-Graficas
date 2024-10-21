#include <GL/glut.h>

float angleBrazo = 0.0f;
float angleAntebrazo = 0.0f;

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    // Dibujamos el brazo
    glColor3f(0.5f, 0.5f, 0.5f);
    glPushMatrix();
    glTranslatef(-0.5f, -0.5f, 0.0f);
    glRotatef(angleBrazo, 0.0f, 0.0f, 1.0f);
    glTranslatef(0.5f, 0.0f, 0.0f);
    glScalef(1.0f, 0.2f, 0.2f);
    glutSolidCube(1.0f);
    glPopMatrix();

    // Dibujamos el antebrazo
    glColor3f(0.3f, 0.3f, 0.3f);
    glPushMatrix();
    glTranslatef(-0.5f, -0.5f, 0.0f);
    glRotatef(angleAntebrazo, 0.0f, 0.0f, 1.0f);
    glTranslatef(0.0f, 0.5f, 0.0f);
    glScalef(0.2f, 1.0f, 0.2f);
    glutSolidCube(1.0f);
    glPopMatrix();

    glutSwapBuffers();
}

void reshape(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1.5, 1.5, -1.5, 1.5, -1, 1);
}

void keyboard(unsigned char key, int x, int y) {
    switch (key) {
    case 'a':
        angleBrazo -= 5.0f;
        if (angleBrazo < -90.0f) angleBrazo = -90.0f;
        break;
    case 'w':
        angleAntebrazo += 5.0f;
        if (angleAntebrazo > 90.0f) angleAntebrazo = 90.0f;
        break;
    case 's':
        angleAntebrazo -= 5.0f;
        if (angleAntebrazo < -90.0f) angleAntebrazo = -90.0f;
        break;
    case 'd':
        angleBrazo += 5.0f;
        if (angleBrazo > 90.0f) angleBrazo = 90.0f;
        break;
    default:
        break;
    }
    glutPostRedisplay();
}



int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(640, 480);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Objeto articulado");
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glutMainLoop();
    return 0;
}
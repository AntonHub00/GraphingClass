#include <GL/glut.h>

void display(void)
{
 // Borra los valores preajustados
 glClear(GL_COLOR_BUFFER_BIT);

 // Delimita los vértices de una primitiva o un grupo de como primitivas
 // , GL_POLYGON es el modo que se a seleccionado.
 glBegin(GL_POLYGON);
 // Indica los puntos que se trazan en un plano cartesiano para
 // formar la figura. En el identificador "glVertex2f" el numero
 // "2" indica el número de argumentos y "f" el tipo de dato que
 // se pasa como argumento. En el caso de la f es float.
 glVertex2f(-0.5, -0.5);
 glVertex2f(-0.5, 0.5);
 glVertex2f(0.5, 0.5);
 glVertex2f(0.5, -0.5);
 // Termina de dibujar.
 glEnd();

 // Fuerza de la ejecución de comandos en OpenGl
 glFlush();
}

int main(int argc, char** argv)
{
 // Se inicia el modo Glut, los argumentos son para enviar ordenes
 // externas al programa.
 glutInit(&argc,argv);
 // Inicializa el modo de visualización del programa, si está en modo
 // GLUT_SINGLE significa que tendrá un solo bufer. Lo que guardará la
 // imagen para luego mostrarla. Y el modo GLUT_RGB se asigna el modo
 // color. RGB resume "Red, Green, Blue".
 glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
 // El tamaño de la ventana 500 Píxeles de ancho y alto.
 glutInitWindowSize(500,500);
 // Indica la posición de la ventana.
 glutInitWindowPosition(0,0);
 // Define la ventana y le añade el título "simple".
 glutCreateWindow("simple");
 // Enviar una función para que se ejecute de forma independiente. Se
 // dice que es conectar la señal "display".
 glutDisplayFunc(display);

 // Empieza todo lo dicho anteriormente. Se mantiene ejecutando la
 // ventana y esperando cualquier evento dicho anteriormente, u otros
 // predefinido por glut. Por ejemplo, se espera que alguien presione
 // la x de la ventana para salir del programa.
 glutMainLoop();
}

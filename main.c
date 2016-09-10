#include "gtk/gtk.h"
#include <GL/gl.h>

static gboolean render(GtkGLArea *area, GdkGLContext *context) {
    glClearColor(1, 0, 0, 0);
    glClear(GL_COLOR_BUFFER_BIT);
    glViewport(0, 0, 300, 300);
    glOrtho(0, 1, 0, 1, -1, 1);
    glBegin(GL_TRIANGLES);
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex2d(0.0, 0.0);
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex2d(0.5, 1.0);
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex2d(1.0, 0.0);
    glEnd();
    return TRUE;
}

int main(int argc, char *argv[]) {
    gtk_init_check(&argc, &argv);
    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    GtkWidget *glarea = gtk_gl_area_new();
    gtk_container_add(GTK_CONTAINER(window), glarea);
    g_signal_connect(glarea, "render", G_CALLBACK(render), NULL);
    gtk_widget_set_size_request(glarea, 500, 500);
    gtk_widget_show_all(window);
    gtk_main();

    return 0;
}
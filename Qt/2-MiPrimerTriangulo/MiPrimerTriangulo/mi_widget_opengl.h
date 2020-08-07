#ifndef MI_WIDGET_OPENGL_H
#define MI_WIDGET_OPENGL_H

#include <QOpenGLWidget>
#include <QOpenGLVertexArrayObject>
#include <QOpenGLBuffer>
#include <QOpenGLShaderProgram>

class MiWidgetOpenGL: public QOpenGLWidget {

public:
    MiWidgetOpenGL();
    ~MiWidgetOpenGL();
    // QOpenGLWidget interface
protected:
    void initializeGL();
    void resizeGL(int w, int h);
    void paintGL();
private:
    QOpenGLVertexArrayObject vao;
    QOpenGLBuffer vbo{QOpenGLBuffer::VertexBuffer};
    QOpenGLShaderProgram *sp;
};

#endif // MI_WIDGET_OPENGL_H

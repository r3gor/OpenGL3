#ifndef WIDGETTRIANGLE_H
#define WIDGETTRIANGLE_H
#include <QMainWindow>
#include <QOpenGLWindow>
#include <qopenglwidget.h>
#include <QSurfaceFormat>
#include <QOpenGLFunctions>
#include <QGLFunctions>
#include <QtOpenGL>

class WidgetOpenGL : public QOpenGLWidget
{
    Q_OBJECT

public:
    WidgetOpenGL();
    ~WidgetOpenGL();
    bool f1, f2;
    void paint();
protected:
    virtual void initializeGL() override;
    virtual void resizeGL(int w, int h) override;
    virtual void paintGL() override;
private:
    QOpenGLVertexArrayObject vao1, vao2;
    QOpenGLBuffer vbo, _vbo;
    QOpenGLShaderProgram *m_program;
};
#endif // WIDGETTRIANGLE_H

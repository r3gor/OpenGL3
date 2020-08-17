#include "widget_opengl.h"
#include <iostream>

WidgetOpenGL::WidgetOpenGL()//: QWidget{parent}
{
    f1 = false;
    f2 = false;
}

WidgetOpenGL::~WidgetOpenGL()
{
}

void WidgetOpenGL::paint()
{
    glClearColor(1.0f, 0.0f, 0.0f, 0.0f);
    glClear( GL_COLOR_BUFFER_BIT);
    m_program->bind();
    if (f1){
        vao1.bind();
        glDrawArrays(GL_TRIANGLES, 0, 3);
    }
    if (f1){
        vao2.bind();
        glDrawArrays(GL_TRIANGLES, 0, 6);
    }
    std::cout<<"DRAW!!"<<std::endl;
}

void WidgetOpenGL::initializeGL()
{
    m_program = new QOpenGLShaderProgram();
    m_program->addShaderFromSourceCode(QOpenGLShader::Vertex,
                                       "#version 450\n" //GLSL version 1.4
                                       "in vec3 position;\n" //attribute named position with 3 elements per vertex in
                                       "in vec3 color;\n"
                                       "out vec4 fragColor;\n"
                                       "void main() {\n"
                                       "    fragColor = vec4(0,0.55,0.75, 1.0);\n"
                                       "    gl_Position = vec4(position, 1.0);\n"
                                       "}\n"
                                       );
    m_program->addShaderFromSourceCode(QOpenGLShader::Fragment,
                                       "#version 450\n" //GLSL version 1.4
                                       "in vec4 fragColor;\n"
                                       "out vec4 finalcolor;\n"
                                       "void main() {\n"
                                       "    finalcolor = fragColor;\n"
                                       "}\n"
                                       );
    m_program->link();
    m_program->bind(); // bind Shader (Do not release until VAO is created)

    float vertices_f1 [] = {
        -0.5f, -0.5f, 0.0f,
         0.5f, -0.5f, 0.0f,
         0.0f,  0.5f, 0.0f
    };

    float vertices_f2 [] = {
        -0.5f, -0.5f, 0.0f,
        -0.5f,  0.5f, 0.0f,
         0.5f,  0.5f, 0.0f,
         0.5f,  0.5f, 0.0f,
        -0.5f, -0.5f, 0.0f,
         0.5f, -0.5f, 0.0f,
    };

    vao1.create();
    vao1.bind();
    //QOpenGLBuffer m_vbo(QOpenGLBuffer::VertexBuffer);
    vbo.create();
    vbo.setUsagePattern(QOpenGLBuffer::StaticDraw);
    vbo.bind();
    vbo.allocate(vertices_f1, sizeof (vertices_f1));
    m_program->enableAttributeArray("position");
    m_program->setAttributeBuffer("position", GL_FLOAT, 0, 3);
    vao1.release();


    vao2.create();
    vao2.bind();
    _vbo.create();
    _vbo.setUsagePattern(QOpenGLBuffer::StaticDraw);
    _vbo.bind();
    _vbo.allocate(vertices_f2, sizeof (vertices_f2));
    m_program->enableAttributeArray("position");
    m_program->setAttributeBuffer("position", GL_FLOAT, 0, 3);
    vao2.release();

    //m_vbo.release();
    m_program->release();
}

void WidgetOpenGL::resizeGL(int w, int h)
{

}

void WidgetOpenGL::paintGL()
{
    glClearColor(1.0f, 0.0f, 0.0f, 0.0f);
    glClear( GL_COLOR_BUFFER_BIT);
    m_program->bind();
    if (f1){
        vao1.bind();
        glDrawArrays(GL_TRIANGLES, 0, 3);
    }
    if (f2){
        vao2.bind();
        glDrawArrays(GL_TRIANGLES, 0, 6);
    }
    std::cout<<"DRAW!!"<<std::endl;
}

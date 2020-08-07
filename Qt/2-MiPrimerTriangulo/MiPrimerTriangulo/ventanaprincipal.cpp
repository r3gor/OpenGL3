#include "ventanaprincipal.h"
#include "ui_ventanaprincipal.h"
#include "mi_widget_opengl.h"

VentanaPrincipal::VentanaPrincipal(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::VentanaPrincipal)
{
    ui->setupUi(this);
    MiWidgetOpenGL *wogl = new MiWidgetOpenGL();
    ui->lienzoOpenGL->addWidget(wogl);
}

VentanaPrincipal::~VentanaPrincipal()
{
    delete ui;
}


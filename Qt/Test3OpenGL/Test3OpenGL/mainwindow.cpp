#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "widget_opengl.h"

#include <QHBoxLayout>

#include <iostream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    wogl = new WidgetOpenGL();
    ui->horizontalLayout->addWidget(wogl);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    std::cout<<"boton1 presionado!"<<std::endl;
    if (wogl->f2)
        wogl->f2 = false;
    wogl->f1 = true;
    wogl->update();
}

void MainWindow::on_pushButton_2_clicked()
{
    std::cout<<"boton2 presionado!"<<std::endl;
    if (wogl->f1)
        wogl->f1 = false;
    wogl->f2 = true;
    wogl->update();
}

void MainWindow::on_pushButton_3_clicked()
{
    std::cout<<"boton3 presionado!"<<std::endl;
    wogl->f1 = false;
    wogl->f2 = false;
    wogl->update();
}

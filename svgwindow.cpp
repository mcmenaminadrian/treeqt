#include <iostream>
#include <string>
#include <sstream>
#include <QtGui>
#include <QtSvg>
#include "node.hpp"
#include "svgwindow.hpp"
#include "MemSvgWidget.hpp"

using namespace std;

SvgWindow::SvgWindow()
{
	svgwid = new MemSvgWidget(this);
        QScrollArea* qscrA = new QScrollArea();
        qscrA->setWidget(svgwid);
        qscrA->setWidgetResizable(true);
	setWindowIcon(QIcon(":/balls.jpg"));
       QDockWidget* scaler = new QDockWidget("&Scale");
        svgwid->scalespin = new QSpinBox(this);
        svgwid->scalespin->setRange(1, 10);
        svgwid->scalespin->setValue(1);
        scaler->setWidget(svgwid->scalespin);

        setCentralWidget(qscrA);
        addDockWidget(Qt::TopDockWidgetArea,scaler);

}

void SvgWindow::startup(const Tree& t)
{
	svgwid->t = new Tree(t);
};


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
        svgwid->par = this;
	setWindowIcon(QIcon(":/balls.jpg"));
        QDockWidget* scaler =
                new QDockWidget(tr("&Scale"));
        QDockWidget* xpoint =
                new QDockWidget(tr("&X point"));
        QDockWidget* ypoint =
                new QDockWidget(tr("&Y point"));
        svgwid->scaleslide = new QSlider(this);
        svgwid->scaleslide->setRange(100, 1000);
        svgwid->scaleslide->setValue(100);
        svgwid->xslide = new QSlider(this);
        svgwid->xslide->setRange(0, 99);
        svgwid->yslide = new QSlider(this);
        svgwid->yslide->setRange(0, 99);
        scaler->setWidget(svgwid->scaleslide);
        xpoint->setWidget(svgwid->xslide);
        ypoint->setWidget(svgwid->yslide);
        addDockWidget(Qt::LeftDockWidgetArea,scaler);
        addDockWidget(Qt::BottomDockWidgetArea, xpoint);
        addDockWidget(Qt::RightDockWidgetArea, ypoint);
        QObject::connect(svgwid->scaleslide, SIGNAL(valueChanged(int)),
                         svgwid, SLOT(repaint()));
        QObject::connect(svgwid->xslide, SIGNAL(valueChanged(int)),
                         svgwid, SLOT(repaint()));
        QObject::connect(svgwid->yslide, SIGNAL(valueChanged(int)),
                         svgwid, SLOT(repaint()));
        scrA = new QScrollArea();
        scrA->setWidget(svgwid);
        scrA->horizontalScrollBar()->setRange(0, 99);
        scrA->verticalScrollBar()->setRange(0, 99);
        scrA->setWidgetResizable(true);
        setCentralWidget(scrA);
}

void SvgWindow::startup(const Tree& t)
{
	svgwid->t = new Tree(t);
};



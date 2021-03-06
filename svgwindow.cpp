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
        timer = NULL;
	svgwid = new MemSvgWidget(this);
	svgwid->par = this;
        repeat = false;
        reptime = -1;
	setWindowIcon(QIcon(":/balls.jpg"));
	QDockWidget* scaler =
		new QDockWidget(tr("&Scale"));
	QDockWidget* xpoint =
		new QDockWidget(tr("&X point"));
	QDockWidget* ypoint =
		new QDockWidget(tr("&Y point"));
        svgwid->scaleslide = new QSlider(this);
        svgwid->scaleslide->setRange(100, 2000);
        svgwid->scaleslide->setValue(100);
        svgwid->xslide = new QSlider(this);
        svgwid->xslide->setRange(0, 999);
        svgwid->yslide = new QSlider(this);
        svgwid->yslide->setRange(0, 999);
        scaler->setWidget(svgwid->scaleslide);
        xpoint->setWidget(svgwid->xslide);
        ypoint->setWidget(svgwid->yslide);
        svgwid->yslide->setInvertedAppearance(true);
        svgwid->yslide->setInvertedControls(true);
        svgwid->xslide->setOrientation(Qt::Horizontal);
        addDockWidget(Qt::LeftDockWidgetArea,scaler);
        addDockWidget(Qt::BottomDockWidgetArea, xpoint);
        addDockWidget(Qt::RightDockWidgetArea, ypoint);
        QObject::connect(svgwid->scaleslide, SIGNAL(valueChanged(int)),
                         svgwid, SLOT(repaint()));
        QObject::connect(svgwid->xslide, SIGNAL(valueChanged(int)),
                         svgwid, SLOT(repaint()));
        QObject::connect(svgwid->yslide, SIGNAL(valueChanged(int)),
                         svgwid, SLOT(repaint()));
	setCentralWidget(svgwid);

}

void SvgWindow::startup(const Tree& t)
{
	svgwid->t = new Tree(t);
        if (repeat) {
            timer = new QTimer(this);
            connect(timer, SIGNAL(timeout()), svgwid, SLOT(repaint()));
            timer->start(reptime * 1000);
        }
};



#include <iostream>
#include <sstream>
#include <QtGui>
#include <QtSvg>
#include <QPaintEvent>
#include "node.hpp"
#include "MemSvgWidget.hpp"
#include "svgwindow.hpp"


using namespace std;

MemSvgWidget::MemSvgWidget(QWidget* parent): QSvgWidget(parent)
{
	balls = 0;
}

void MemSvgWidget::paintEvent(QPaintEvent* qp)
{
        if (par) {
            if (par->timer) {
                delete t;
                Tree tt;
                cin >> tt;
                t = new Tree(tt);
                par->timer->start(par->reptime * 1000);
            }
        }
	string strbytes;
	ostringstream strlines;
	scaleslide->setVisible(true);
        QPainter painter(this);
        t->output_svg(strlines);
        strbytes = strlines.str();
        QByteArray qbytes = QByteArray(strbytes.c_str());
        delete balls;
	balls = new QSvgRenderer(qbytes, this);
	QSize qsiz = balls->defaultSize();
	balls->setViewBox(QRect(qsiz.width() * xslide->value() / 1000,
		qsiz.height() * yslide->value() / 1000, qsiz.width(),
		qsiz.height()));
        //maintain te aspect ratio
        double xtoysvg = qsiz.width()/(double)qsiz.height();
        double xtoywind = width()/(double)height();
        painter.scale(scaleslide->value()/100.0, (scaleslide->value() * (xtoywind/xtoysvg)/100.0));
	balls->render(&painter);
}

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
        double xtoysvg = qsiz.width()/qsiz.height();
        double xtoywind = width()/height();
        painter.scale(scaleslide->value()/100, (scaleslide->value()/100) * (xtoywind/xtoysvg));
	balls->render(&painter);
}

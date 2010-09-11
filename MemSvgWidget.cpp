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
        cout << "Width: " << qsiz.width() << " Height: " << qsiz.height() << endl;
        QScrollBar* hbar = par->scrA->horizontalScrollBar();
        hbar->show();
        QScrollBar* vbar = par->scrA->verticalScrollBar();
        vbar->show();
        balls->setViewBox(QRect(qsiz.width() * xslide->value() / 100, qsiz.height() * yslide->value() / 100, qsiz.width(), qsiz.height()));
        painter.scale(scaleslide->value()/100, scaleslide->value()/100);
        balls->render(&painter);
}

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
        scalespin->setVisible(true);
        QPainter painter(this);
        t->output_svg(strlines);
        strbytes = strlines.str();
	QByteArray qbytes = QByteArray(strbytes.c_str());
	delete balls;
	balls = new QSvgRenderer(qbytes, this);
        painter.scale(scalespin->value(), scalespin->value());
        balls->render(&painter);
}
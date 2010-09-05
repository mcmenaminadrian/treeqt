#include <QtGui>
#include <QtSvg>
#include <QPaintEvent>
#include "MemSvgWidget.hpp"

using namespace std;

MemSvgWidget::MemSvgWidget(QWidget* parent): QSvgWidget(parent)
{
	setFixedSize(500, 500);
}

void MemSvgWidget::paintEvent(QPaintEvent* qp)
{
//	repaint();
}

#include <iostream>
#include <string>
#include <sstream>
#include <QtGui>
#include <QtSvg>
#include "node.hpp"
#include "svgwindow.hpp"

using namespace std;

SvgWindow::SvgWindow()
{
	QSvgWidget *svgwid = new QSvgWidget();
	QPainter painter(svgwid);

	setCentralWidget(svgwid);
	setWindowIcon(QIcon(":/balls.jpg"));
}

void SvgWindow::startup()
{
	string strbytes;
	ostringstream strlines;
	while (t->output_svg(strlines))
	{
		strbytes += strlines.str();
	}
	QByteArray qbytes = QByteArray(strbytes.c_str());
	QSvgRenderer* balls = new QSvgRenderer(qbytes, this);
};



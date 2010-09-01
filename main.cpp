#include <iostream>
#include <string>
#include <sstream>
#include <QApplication>
#include <QtSvg/QSvgWidget>
#include <QtSvg/QSvgRenderer>
#include <QPainter>
#include <QByteArray>
#include <QPushButton>
#include "tree.hpp"

using namespace std;

int main(int argc, char *argv[])
{
	Tree t;
	cin >> t;

	QApplication app(argc, argv);
	QSvgWidget *svgwindow = new QSvgWidget();
	QPainter painter(svgwindow);
	string strbytes;
	ostringstream strlines;
	while (t.output_svg(strlines))
	{
		strbytes += strlines.str();
	}
	QByteArray qbytes = QByteArray(strbytes.c_str());
	QPushButton *button = new QPushButton("Draw");
	QSvgRenderer* balls = new QSvgRenderer(qbytes, svgwindow);
	QObject::connect(button, SIGNAL(clicked()), balls, SLOT(render(&painter)));
	button->show();
	svgwindow->show();
	
	return app.exec();
}

#include <iostream>
#include <QtGui>
#include <QtSvg>
#include "node.hpp"
#include "svgwindow.hpp"

using namespace std;

int main(int argc, char *argv[])
{
	Tree t;
	cin >> t; 	
	QApplication app(argc, argv);

	SvgWindow* svgwind = new SvgWindow();
	svgwind->t = new Tree(t);
	svgwind->startup(t);
	svgwind->show();
	return app.exec();
}

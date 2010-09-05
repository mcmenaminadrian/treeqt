#ifndef SVGWINDOW_HPP
#define SVGWINDOW_HPP

#include <QMainWindow>

class Tree;

class SvgWindow : public QMainWindow
{
	Q_OBJECT

public:
	Tree* t;
	SvgWindow();
	void startup();	
};

#endif


#ifndef SVGWINDOW_HPP
#define SVGWINDOW_HPP

#include <QMainWindow>
#include <QtSvg>

class Tree;
class MemSvgWidget;

class SvgWindow : public QMainWindow
{
	Q_OBJECT

public:
	Tree* t;
	SvgWindow();
	void startup(const Tree&);
	MemSvgWidget* svgwid;
        QScrollArea* scrA;
};

#endif


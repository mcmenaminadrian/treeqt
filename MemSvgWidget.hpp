#include <QtGui>
#include <QtSvg>
#include "svgwindow.hpp"

class Tree;

class MemSvgWidget : public QSvgWidget
{
	Q_OBJECT
public:
	MemSvgWidget(QWidget*);
	Tree* t;
	QSvgRenderer* balls;
        QSlider* scaleslide;
        QSlider* xslide;
        QSlider* yslide;
        SvgWindow* par;
protected:
	void paintEvent(QPaintEvent*);
};

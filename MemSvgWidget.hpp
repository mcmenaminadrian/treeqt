#include <QtGui>
#include <QtSvg>

class MemSvgWidget : public QSvgWidget
{
	Q_OBJECT
public:
	MemSvgWidget(QWidget*);
protected:
	void paintEvent(QPaintEvent*);
};

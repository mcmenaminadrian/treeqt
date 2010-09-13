#include <iostream>
#include <QtGui>
#include <QtSvg>
#include "node.hpp"
#include "svgwindow.hpp"

using namespace std;

void usage()
{
    cout << "treeqt usage..." << endl;
    cout << "./treeqt -r [s]    repeat every s seconds" << endl;
}

int main(int argc, char *argv[])
{
        Tree t;
        QApplication app(argc, argv);
	SvgWindow* svgwind = new SvgWindow();
        for (int z = 1; z < argc; z++)
        {
            if (strcmp(argv[z], "--r") == 0) {
                svgwind->repeat = true;
                if (z + 2 > argc) {
                        usage();
                        cout << "Must specify an interval" << endl;
                        return 1;
                }
                svgwind->reptime = atoi(argv[z + 1]);
                z++;
            }
        }

        cin >> t;
	svgwind->t = new Tree(t);
	svgwind->startup(t);
	svgwind->show();

	return app.exec();
}

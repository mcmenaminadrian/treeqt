#include <iostream>
#include <QApplication>
#include "tree.hpp"

using namespace std;

int main(int argc, char *argv[])
{
	Tree t;
	cin >> t;
	cout << "have read in t" << endl;
	for (int i = 0; i < t.items.size(); i++)
	{
		Node* n = t.items[i];
		cout << "Value of " << i << " is " << n->getvalue() << " while oterdata is " << n->otherdata << endl;
	}
	cout << "DONE" << endl;
	QApplication app(argc, argv);
	return app.exec();
}

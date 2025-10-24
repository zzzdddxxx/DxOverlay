#include <QApplication>
#include <QWidget>

int main(int argc, char* argv[])
{
	QApplication App(argc, argv);

	QWidget w;
	w.show();

	return App.exec();
}
#include <QApplication>
#include <QWidget>
#include "DXOverlay.h"
#include <QPushButton>

int main(int argc, char* argv[])
{
	QApplication App(argc, argv);

	QWidget w;
	DxOverlay* overlay = new DxOverlay(&w);

	QPushButton* ww = new QPushButton(&w);
	overlay->addWidget(ww, Qt::AlignLeft | Qt::AlignTop, DxMargin(100));
	QPushButton* ww3 = new QPushButton(&w);
	ww3->setMinimumSize(300, 300);
	overlay->addWidget(ww3, Qt::AlignCenter);
	QPushButton* ww2 = new QPushButton(&w);
	ww2->setMinimumSize(100, 100);
	overlay->addWidget(ww2, Qt::AlignRight | Qt::AlignBottom);


	w.show();
	

	return App.exec();
}
#include "wrong1.h"

wrong1::wrong1(QWidget *parent)
	: QWidget(parent)
{
	setAttribute(Qt::WA_QuitOnClose, false);
	ui.setupUi(this);
}

wrong1::~wrong1()
{
}

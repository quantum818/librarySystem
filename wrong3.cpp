#include "wrong3.h"

wrong3::wrong3(QWidget *parent)
	: QWidget(parent)
{
	setAttribute(Qt::WA_QuitOnClose, false);
	ui.setupUi(this);
}

wrong3::~wrong3()
{
}

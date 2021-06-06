#include "addgit.h"

addgit::addgit(QWidget *parent)
	: QWidget(parent)
{
	setAttribute(Qt::WA_QuitOnClose, false);
	ui.setupUi(this);
}

addgit::~addgit()
{
}

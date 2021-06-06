#pragma once

#include <QWidget>
#include "ui_addgit.h"

class addgit : public QWidget
{
	Q_OBJECT

public:
	addgit(QWidget *parent = Q_NULLPTR);
	~addgit();

private:
	Ui::addgit ui;
};

#pragma once

#include <QWidget>
#include "ui_getinfo.h"

class getinfo : public QWidget
{
	Q_OBJECT

public:
	getinfo(QWidget *parent = Q_NULLPTR);
	~getinfo();

public:
	Ui::getinfo ui;
};

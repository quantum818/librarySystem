#pragma once

#include <QWidget>
#include "ui_deletinfo.h"

class deletinfo : public QWidget
{
	Q_OBJECT

public:
	deletinfo(QWidget *parent = Q_NULLPTR);
	~deletinfo();

public:
	Ui::deletinfo ui;
};

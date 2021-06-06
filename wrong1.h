#pragma once

#include <QWidget>
#include "ui_wrong1.h"

class wrong1 : public QWidget
{
	Q_OBJECT

public:
	wrong1(QWidget *parent = Q_NULLPTR);
	~wrong1();

public:
	Ui::wrong1 ui;
};

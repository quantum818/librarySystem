#pragma once

#include <QWidget>
#include "ui_wrong3.h"

class wrong3 : public QWidget
{
	Q_OBJECT

public:
	wrong3(QWidget *parent = Q_NULLPTR);
	~wrong3();

private:
	Ui::wrong3 ui;
};

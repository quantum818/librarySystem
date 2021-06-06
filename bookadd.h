#pragma once

#include <QWidget>
#include "ui_bookadd.h"
#include "ui_wrong1.h"

class bookadd : public QWidget
{
	Q_OBJECT

public:
	bookadd(QWidget *parent = Q_NULLPTR);
	~bookadd();

private:
	Ui::bookadd ui;

public slots:
	void on_add_check_clicked();
};

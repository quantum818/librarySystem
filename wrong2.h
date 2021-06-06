#pragma once

#include <QWidget>
#include "ui_wrong2.h"

class wrong2 : public QWidget
{
	Q_OBJECT

public:
	wrong2(QWidget *parent = Q_NULLPTR);
	~wrong2();

private:
	Ui::wrong2 ui;
public slots:
	void on_check_clicked();

};

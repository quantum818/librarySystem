#pragma once

#include <QWidget>
#include "ui_bookremove.h"
#include "wrong3.h"
#include "deletinfo.h"

class bookremove : public QWidget
{
	Q_OBJECT

public:
	bookremove(QWidget *parent = Q_NULLPTR);
	~bookremove();

private:
	Ui::bookremove ui;
	deletinfo* dele;
public slots:
	void on_dele_clicked();
};

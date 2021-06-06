#pragma once

#include <QWidget>
#include "ui_bookseek.h"
#include "getinfo.h"
#include "wrong3.h"
class bookseek : public QWidget
{
	Q_OBJECT

public:
	bookseek(QWidget *parent = Q_NULLPTR);
	~bookseek();

private:
	Ui::bookseek ui;
	getinfo* getin;
public slots:
	void on_checklist_clicked();
};

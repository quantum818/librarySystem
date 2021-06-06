#pragma once

#include <QWidget>
#include <QDialog>
#include <QlistWidget>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QDir>
#include <QListWidgetItem>
#include <QFileInfoList>
#include "ui_gitset.h"

class gitset : public QWidget
{
	Q_OBJECT

public:
	gitset(QWidget *parent = Q_NULLPTR);
	~gitset();
	void  showFileInfoList(QFileInfoList list);
public slots:
	void slotShow(QDir dir);
	void slotDirShow(QListWidgetItem* item);
private:
	Ui::gitset ui;
	QLineEdit* fileLine;
	QListWidget* filelist;
	QVBoxLayout* main;
};

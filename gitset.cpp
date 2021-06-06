#define _CRT_SECURE_NO_WARNINGS
#include "gitset.h"
#include <QStringList>
#include <QIcon>
#include <bits/stdc++.h>
gitset::gitset(QWidget *parent)
	: QWidget(parent)
{
	setWindowTitle(tr("git select"));
	fileLine = new QLineEdit(tr("/"));
	filelist = new QListWidget;
	main = new QVBoxLayout(this);
	main->addWidget(fileLine);
	main->addWidget(filelist);
	connect(fileLine, SIGNAL(returnPressed()), this, SLOT(slotShow(QDir)));
	connect(filelist, SIGNAL(itemDoubleClicked(QListWidgetItem*)), this, SLOT(slotDirShow(QListWidgetItem*)));
	QString root = "/";
	QDir rootDir(root);
	QStringList string;
	string << "*";
	QFileInfoList list = rootDir.entryInfoList(string);
	showFileInfoList(list);
	ui.setupUi(this);
}
void gitset::showFileInfoList(QFileInfoList list) {
	filelist->clear();
	for (unsigned int i = 0; i < list.count(); i++) {
		QFileInfo tmpFileInfo = list.at(i);
		if (tmpFileInfo.isDir()) {
			QIcon icon("dir.png");
			QString filename = tmpFileInfo.fileName();
			QListWidgetItem* temp = new QListWidgetItem(icon, filename);
			filelist->addItem(temp);
		}
		else if (tmpFileInfo.isFile()) {
			QIcon icon("file.png");
			QString filename = tmpFileInfo.fileName();
			QListWidgetItem* temp = new QListWidgetItem(icon, filename);
			filelist->addItem(temp);
		}
	}
}
void gitset::slotDirShow(QListWidgetItem* item) {
	QString str = item->text();
	QDir dir;
	dir.setPath(fileLine->text());
	dir.cd(str);
	fileLine->setText(dir.absolutePath());
	slotShow(dir);
}
void gitset::slotShow(QDir dir) {
	QStringList str;
	str << "*";
	QFileInfoList list = dir.entryInfoList(str, QDir::AllEntries, QDir::DirsFirst);
	showFileInfoList(list);
}
gitset::~gitset()
{
}

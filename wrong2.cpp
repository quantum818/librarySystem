#define _CRT_SECURE_NO_WARNINGS
#include "wrong2.h"
#include<bits/stdc++.h>
#include<time.h>
#include<io.h>
#include<direct.h>
using namespace std;
wrong2::wrong2(QWidget *parent)
	: QWidget(parent)
{
	setAttribute(Qt::WA_QuitOnClose, false);
	setWindowFlags(Qt::WindowStaysOnTopHint);
	ui.setupUi(this);
}

wrong2::~wrong2()
{
}
void wrong2::on_check_clicked() {
	QString name = ui.gitname->text();
	name = QString::fromLocal8Bit(name.toLocal8Bit());
	string ind = name.toStdString();
	char str[10000] = {};
	char str2[10000] = {};
	char str3[10000] = {};
	strcpy(str, ind.c_str());
	strcpy(str2, "address");
	_mkdir(str2);
	_mkdir(str);
	strcpy(str3, "address\\address.txt");
	FILE* fp;
	if ((fp = fopen(str3, "rb")) == NULL) {
		fp = fopen(str3, "w");
		fputs(str, fp);
		fclose(fp);
	}
	close();
}

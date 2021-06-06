#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
#include <fstream>
#include<time.h>
#include<io.h>
#include<direct.h>
#include<Windows.h>
#include "bookremove.h"

using namespace std;
string ttmp;
char tmp[200000] = {};
void rreadaddress();
int removeDir(string ind);
string ggetinfo(string ind);
bookremove::bookremove(QWidget *parent)
	: QWidget(parent)
{
	setAttribute(Qt::WA_QuitOnClose, false);
	ui.setupUi(this);
	dele = new deletinfo;
}

bookremove::~bookremove()
{
}
void bookremove::on_dele_clicked() {
	rreadaddress();
	QString name = ui.del_target->text();
	name = QString::fromLocal8Bit(name.toLocal8Bit());
	string nname = name.toStdString();
	nname = ttmp + "\\" + nname;
	strcpy(tmp, nname.c_str());
	if (_access(tmp, 0) == -1) {
		wrong3* wr3 = new wrong3;
		wr3->show();
	}
	else {
		string bookname;
		bookname = ggetinfo(nname + "\\name.txt");
		QString el = QString::fromLocal8Bit("已删除");
		dele->show();
		dele->ui.info->setText(QString::fromStdString(bookname)+el);
		removeDir(nname);
		
	}
	ui.del_target->setText(NULL);
}
void rreadaddress() {
	ifstream infile;
	infile.open("address\\address.txt");
	infile >> ttmp;
	infile.close();
}
//递归删除书籍文件夹及文件夹下资源
int removeDir(string ind) {
	struct _finddata_t fb;
	string dirpath;
	long long handle;
	int result;
	int nofile;
	nofile = 0;
	handle = 0;
	dirpath = ind + "/*";
	handle = _findfirst(dirpath.c_str(), &fb);
	if (handle != -1) {
		while (0 == _findnext(handle, &fb)) {
			nofile = strcmp(fb.name, "..");
			if (0 != nofile) {
				dirpath.clear();
				dirpath = ind + "\\" + fb.name;
				if (fb.attrib == 16) {
					removeDir(dirpath);
				}
				else { remove(dirpath.c_str()); }
			}
		}
	}
	_findclose(handle);
	rmdir(ind.c_str());
	return 0;
}
string ggetinfo(string ind) {
	ifstream infile;
	infile.open(ind);
	string info;
	infile >> info;
	infile.close();
	return info;

}
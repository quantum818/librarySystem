#define _CRT_SECURE_NO_WARNINGS
#include "bookseek.h"
#include<bits/stdc++.h>
#include <fstream>
#include<time.h>
#include<io.h>
#include<direct.h>
using namespace std;
string tmp;
string getinfom(string ind);
void rereadaddress();
bookseek::bookseek(QWidget *parent)
	: QWidget(parent)
{
	setAttribute(Qt::WA_QuitOnClose, false);
	ui.setupUi(this);
	getin = new getinfo;

}

bookseek::~bookseek()
{
}
void bookseek::on_checklist_clicked() {
	QString booklist = ui.listname->text();
	booklist = QString::fromLocal8Bit(booklist.toLocal8Bit());
	rereadaddress();
	tmp = tmp + "\\" + booklist.toStdString();
	char midtmp[200000] = {};
	strcpy(midtmp, tmp.c_str());
	if (_access(midtmp, 0) == -1) {
		wrong3* wr3 = new wrong3;
		wr3->show();
	}
	else {
		string name, time, cnt, writer, isbn;
		name = getinfom(tmp + "\\" + "name.txt");
		time = getinfom(tmp + "\\" + "入库时间.txt");
		cnt=getinfom(tmp+"\\"+"cnt.txt");
		writer = getinfom(tmp + "\\" + "writer.txt");
		isbn = getinfom(tmp + "\\" + "isbn.txt");
		QString tttime = QString::fromLocal8Bit(time);//真他妈几把傻逼怎么读月份就乱码了
		getin->show();
		getin->ui.list->setText(booklist);
		getin->ui.name->setText(QString::fromStdString(name));
		getin->ui.cnt->setText(QString::fromStdString(cnt));
		getin->ui.writer->setText(QString::fromStdString(writer));
		getin->ui.isbn->setText(QString::fromStdString(isbn));
		getin->ui.time->setText(tttime);
		ui.listname->setText(NULL);
	}
}
//函数读取信息
string getinfom(string ind) {
	ifstream infile;
	infile.open(ind);
	string info;
	infile >> info;
	infile.close();
	return info;
	
}
//函数读取目录地址
void rereadaddress() {
	ifstream infile;
	infile.open("address\\address.txt");
	infile >> tmp;
	infile.close();
}
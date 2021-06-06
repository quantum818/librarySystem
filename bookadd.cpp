#define _CRT_SECURE_NO_WARNINGS
#include "wrong2.h"
#include<bits/stdc++.h>
#include <fstream>
#include<time.h>
#include<io.h>
#include<direct.h>
#include "bookadd.h"
#include "wrong1.h"
#include "addgit.h"
using namespace std;
char g[10000] = {};
char bookdoc[20000000] = {};
QString name, writer, lit, cnt, isbn;
using namespace std;
bool depstr(QString ind);
void readaddress();
void add(string ind2,string ind);
string time();
bookadd::bookadd(QWidget *parent)
	: QWidget(parent)
{
	setAttribute(Qt::WA_QuitOnClose, false);
	ui.setupUi(this);
}
void bookadd::on_add_check_clicked() {
	name = ui.addname->text();
	name = QString::fromLocal8Bit(name.toLocal8Bit());
	writer = ui.addwriter->text();
	writer = QString::fromLocal8Bit(writer.toLocal8Bit());
	lit = ui.addlist->text();
	lit = QString::fromLocal8Bit(lit.toLocal8Bit());
	cnt = ui.addcnt->text();
	cnt = QString::fromLocal8Bit(cnt.toLocal8Bit());
	isbn = ui.addisbn->text();
	isbn = QString::fromLocal8Bit(isbn.toLocal8Bit());
	if (depstr(name) || depstr(writer) || depstr(lit) || depstr(cnt) || depstr(isbn)) {
		wrong1* w_ = new wrong1();
		w_->show();

	}
	//ȫ����ʱ���鼮��Ŵ����鼮�����ļ���
	else {
		char llit[10000000] = {};
		strcpy(llit, (lit.toStdString()).c_str());
		readaddress();
		string mid1 = g;
		string mid2 = llit;
		mid1 = mid1 + "\\" + mid2;
		strcpy(bookdoc, mid1.c_str());
		_mkdir(bookdoc);
		string wwriter = writer.toStdString();
		string nname = name.toStdString();
		string ccnt = cnt.toStdString();
		string iisbn = isbn.toStdString();
		add("name", nname);
		add("writer", wwriter);
		add("cnt", ccnt);
		add("isbn", iisbn);
		add("���ʱ��", time());
		addgit* ro = new addgit;
		ro->show();
		ui.addname->setText(NULL);
		ui.addwriter->setText(NULL);
		ui.addlist->setText(NULL);
		ui.addcnt->setText(NULL);
		ui.addisbn->setText(NULL);
	}
}
bookadd::~bookadd(){
}
//�ж��Ƿ��������Ϊ��
bool depstr(QString ind) {
	if (ind == "") {
		return true;
	}
	else return false;
}
//�������Ĳֿ��ַ
void readaddress() {
	FILE* fp;
	fp = fopen("address\\address.txt", "rt");
	fgets(g, 1000, fp);
}
//������Ϣ�ļ��������ɸĳɴ��ļ������룩
void add(string ind2, string ind) {
	FILE* fp;
	string temp = bookdoc;
	temp = temp + "\\" + ind2 + ".txt";
	char fin[20000100] = {};
	strcpy(fin, temp.c_str());
	if ((fp = fopen(fin, "rb")) == NULL) {
		fp = fopen(fin, "w");
		ofstream outfile;
		outfile.open(temp);
		outfile << ind << endl;
		outfile.close();
	}
}
//��ȡ��ǰϵͳʱ��
string time() {
	time_t info;
	struct tm bst;
	string ind3, mon, day, hour, min, sum;
	char  temp;
	long y, m, d;
	time(&info);
	gmtime_s(&bst, &info);
	y = bst.tm_year;
	y = y + 1900;//ת��Ϊ����ʱ��
	while (y != 0) {
		temp = '0' + y % 10;
		ind3 = ind3 + temp;
		y = y / 10;
	}
	reverse(ind3.begin(), ind3.end());
	m = bst.tm_mon + 1;
	while (m != 0) {
		temp = '0' + m % 10;
		mon = mon + temp;
		m = m / 10;
	}
	reverse(mon.begin(), mon.end());
	d = bst.tm_mday;
	while (d != 0) {
		temp = '0' + d % 10;
		day = day + temp;
		d = d / 10;
	}
	reverse(day.begin(), day.end());
	bst.tm_hour = (bst.tm_hour + 8) % 24;
	while (bst.tm_hour != 0) {
		temp = '0' + bst.tm_hour % 10;
		hour = hour + temp;
		bst.tm_hour = bst.tm_hour / 10;
	}
	reverse(hour.begin(), hour.end());
	while (bst.tm_min != 0) {
		temp = '0' + bst.tm_min % 10;
		min = min + temp;
		bst.tm_min = bst.tm_min / 10;
	}
	reverse(min.begin(), min.end());
	sum = ind3 + "��" + mon + "��" + day + "��" + hour + ':' + min;
	return sum;
}
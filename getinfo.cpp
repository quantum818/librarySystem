#define _CRT_SECURE_NO_WARNINGS
#include "getinfo.h"
#include<bits/stdc++.h>
#include <fstream>
#include<time.h>
#include<io.h>
#include<direct.h>
using namespace std;
getinfo::getinfo(QWidget *parent)
	: QWidget(parent)
{
	setAttribute(Qt::WA_QuitOnClose, false);
	ui.setupUi(this);
}

getinfo::~getinfo()
{
}

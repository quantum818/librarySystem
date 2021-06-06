#define _CRT_SECURE_NO_WARNINGS
#include "librarySystem.h"
#include "bookadd.h"
#include "bookremove.h"
#include "bookseek.h"
#include <QtWidgets/QApplication>
#include<bits/stdc++.h>
#include<time.h>
#include<io.h>
#include<direct.h>
using namespace std;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    librarySystem w;
    w.setAttribute(Qt::WA_QuitOnClose,true);
    w.show();
   return a.exec();
}

#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
#include<time.h>
#include<io.h>
#include<direct.h>
#include "librarySystem.h"
#include <QtWidgets>
#include <QGraphicsOpacityEffect> 
using namespace std;
bool checkdoc();
librarySystem::librarySystem(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);

    if (checkdoc()) {
        wrong2* w_ = new wrong2;
        w_->show();
    }
}
void librarySystem::on_exit_clicked() {
  
    close();
}
void librarySystem::on_addbook_clicked() {
    bookadd* w_ = new bookadd();
    w_->show();
    
}
void librarySystem::on_seekbook_clicked() {
    bookseek* w_ = new bookseek();
    w_->show();
    
}
void librarySystem::on_remove_clicked() {
    bookremove* w_ = new bookremove();
    w_->show();
   
}
void librarySystem::on_test_clicked() {
    gitset* w_ = new gitset();
    w_->show();

}
bool checkdoc() {
    if ((_access("address", 0)) == -1) {
        return true;

    }
    else return false;
}
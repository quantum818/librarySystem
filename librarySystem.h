#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_librarySystem.h"
#include "bookadd.h"
#include "bookremove.h"
#include "bookseek.h"
#include "wrong2.h"
#include "gitset.h"

class librarySystem : public QMainWindow
{
    Q_OBJECT
       
public:
    librarySystem(QWidget *parent = Q_NULLPTR);

private:
    Ui::librarySystemClass ui;
    QLabel* label_2;
public slots:
    void on_addbook_clicked();
public slots:
    void on_seekbook_clicked();
public slots:
    void on_remove_clicked();
public slots:
    void on_exit_clicked();
public slots:
    void on_test_clicked();

};

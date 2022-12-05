#ifndef WELCOMEWINDOW
#define WELCOMEWINDOW


#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QBoxLayout>
#include <QLineEdit>
#include <QMessageBox>
#include <string>
#include "thewindow.h"


class welcomeWindow : public QWidget
{
    Q_OBJECT
public:
    welcomeWindow();

public slots:
    void openProgram();

private:
    QLabel *penetration;
    QLineEdit *entrance;
    QPushButton *go;
    QPushButton *leave;
    QHBoxLayout *hbox;
    QVBoxLayout *vbox;

    std::string enterCode;

};



#endif // WELCOMEWINDOW


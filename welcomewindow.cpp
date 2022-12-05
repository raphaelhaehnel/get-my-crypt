#include "welcomewindow.h"

welcomeWindow::welcomeWindow(): enterCode("huji")
{
    penetration = new QLabel("Enter the code to run the program.");
    entrance = new QLineEdit;
    go = new QPushButton("GO !");
    leave = new QPushButton("Leave");
    hbox = new QHBoxLayout;
    vbox = new QVBoxLayout;

    entrance->setEchoMode(QLineEdit::Password);

    hbox->addWidget(go);
    hbox->addWidget(leave);

    vbox->addWidget(penetration);
    vbox->addWidget(entrance);
    vbox->addLayout(hbox);

    this->setLayout(vbox);
    this->setGeometry(800,500,300,80);

    QObject::connect(go, SIGNAL(clicked()), this, SLOT(openProgram()));
    QObject::connect(entrance, SIGNAL(returnPressed()), this, SLOT(openProgram()));
    QObject::connect(leave, SIGNAL(clicked()), qApp, SLOT(quit()));
}


void welcomeWindow::openProgram()
{
    if (entrance->text().toStdString() == enterCode)
    {
        theWindow *fenetreCode = new theWindow;
        fenetreCode->show();
        this->hide();

    } else
        QMessageBox::warning(this, "Bad code", "The code is incorrect");
}

#include "thewindow.h"
#include <sstream>

#include <iostream>

using namespace std;

string intToString(int i)
{
     ostringstream oss;
     oss << i;
     return oss.str();
}


theWindow::theWindow() : secretKey("weiterswiller")
{
    d_encrypt = new QLabel("<h3>ENCRYPTION SECTION</h3><p>Enter below your phrase that you want to code</p>");
    d_decrypt = new QLabel("<h3>DECRYPTION SECTION</h3><p>Enter the code here, including numbers and dots only.</p>");
    options = new QLabel("<h4>Options</h4>");
    encrypt = new QPushButton("ENCRYPT");
    decrypt = new QPushButton("DECRYPT");
    in_encrypt = new QTextEdit;
    in_decrypt = new QTextEdit;
    out_encrypt = new QTextEdit;
    out_decrypt = new QTextEdit;
    enterKey = new QLineEdit;
    specialKey = new QCheckBox("Use a special key");
    containing = new QHBoxLayout;
    option1 = new QHBoxLayout;
    content1 = new QVBoxLayout;
    content2 = new QVBoxLayout;
    bigContaining = new QVBoxLayout;

    out_encrypt->setReadOnly(true);
    out_decrypt->setReadOnly(true);
    enterKey->setDisabled(true);

    content1->addWidget(d_encrypt);
    content1->addWidget(in_encrypt);
    content1->addWidget(encrypt);
    content1->addWidget(out_encrypt);

    content2->addWidget(d_decrypt);
    content2->addWidget(in_decrypt);
    content2->addWidget(decrypt);
    content2->addWidget(out_decrypt);

    containing->addLayout(content1);
    containing->addLayout(content2);

    option1->addWidget(specialKey);
    option1->addWidget(enterKey);

    bigContaining->addLayout(containing);
    bigContaining->addWidget(options);
    bigContaining->addLayout(option1);

    this->setLayout(bigContaining);

    this->setWindowIcon(QIcon(QCoreApplication::applicationDirPath() + "/icon_lock.png"));
    this->setWindowTitle("Get my Crypt !");

    QObject::connect(encrypt, SIGNAL(clicked()), this, SLOT(fEncrypt()));
    QObject::connect(decrypt, SIGNAL(clicked()), this, SLOT(fDecrypt()));
    QObject::connect(specialKey, SIGNAL(clicked()), this, SLOT(fOption1()));

}


int theWindow::getNumber(char letter)
{
    switch (letter)
    {
        case 'a':
            return 1;
            break;
        case 'b':
            return 2;
            break;
        case 'c':
            return 3;
            break;
        case 'd':
            return 4;
            break;
        case 'e':
            return 5;
            break;
        case 'f':
            return 6;
            break;
        case 'g':
            return 7;
            break;
        case 'h':
            return 8;
            break;
        case 'i':
            return 9;
            break;
        case 'j':
            return 10;
            break;
        case 'k':
            return 11;
            break;
        case 'l':
            return 12;
            break;
        case 'm':
            return 13;
            break;
        case 'n':
            return 14;
            break;
        case 'o':
            return 15;
            break;
        case 'p':
            return 16;
            break;
        case 'q':
            return 17;
            break;
        case 'r':
            return 18;
            break;
        case 's':
            return 19;
            break;
        case 't':
            return 20;
            break;
        case 'u':
            return 21;
            break;
        case 'v':
            return 22;
            break;
        case 'w':
            return 23;
            break;
        case 'x':
            return 24;
            break;
        case 'y':
            return 25;
            break;
        case 'z':
            return 26;
            break;
        case ',':
            return 27;
            break;
        case '\'':
            return 28;
            break;
        case '!':
            return 29;
            break;
        case '?':
            return 30;
            break;
        case '\"':
            return 31;
            break;
        case '.':
            return 32;
            break;
        case '(':
            return 33;
            break;
        case ')':
            return 34;
            break;
        case ' ':
            return 35;
            break;        
        default:
            return 36;
            break;
    }
}


int theWindow::getLetter(int number)
{
    switch (number)
    {
        case 1:
            return 'a';
            break;
        case 2:
            return 'b';
            break;
        case 3:
            return 'c';
            break;
        case 4:
            return 'd';
            break;
        case 5:
            return 'e';
            break;
        case 6:
            return 'f';
            break;
        case 7:
            return 'g';
            break;
        case 8:
            return 'h';
            break;
        case 9:
            return 'i';
            break;
        case 10:
            return 'j';
            break;
        case 11:
            return 'k';
            break;
        case 12:
            return 'l';
            break;
        case 13:
            return 'm';
            break;
        case 14:
            return 'n';
            break;
        case 15:
            return 'o';
            break;
        case 16:
            return 'p';
            break;
        case 17:
            return 'q';
            break;
        case 18:
            return 'r';
            break;
        case 19:
            return 's';
            break;
        case 20:
            return 't';
            break;
        case 21:
            return 'u';
            break;
        case 22:
            return 'v';
            break;
        case 23:
            return 'w';
            break;
        case 24:
            return 'x';
            break;
        case 25:
            return 'y';
            break;
        case 26:
            return 'z';
            break;
        case 27:
            return ',';
            break;
        case 28:
            return '\'';
            break;
        case 29:
            return '!';
            break;
        case 30:
            return '?';
            break;
        case 31:
            return '\"';
            break;
        case 32:
            return '.';
            break;
        case 33:
            return '(';
            break;
        case 34:
            return ')';
            break;
        case 35:
            return ' ';
            break;
        default:
            return '@';
            break;
    }
}


void theWindow::crypOperations()
{
    if (enterKey->isEnabled())
        finalCode = enterKey->text().toStdString();
    else
        finalCode = secretKey;

    j = 0;
    mt = finalCode.size();
    transfert = "";
}


void theWindow::fEncrypt()
{
    original = in_encrypt->toPlainText().toStdString();
    out_encrypt->clear();

    this->crypOperations();


    taille = original.size();
    int transformation [taille];


    for (int i=0; i<taille; i++)
    {
        if (j==mt) j=0;

        transformation[i] = getNumber(original[i]);
        transformation[i] += getNumber(finalCode[j]);
        transfert += intToString(transformation[i]);
        transfert += '.';

        j++;
    }

    out_encrypt->setPlainText(QString::fromStdString(transfert));
}

void theWindow::fDecrypt()
{
    original = in_decrypt->toPlainText().toStdString();
    out_decrypt->clear();

    this->crypOperations();


    istringstream iss(original);
    iss.seekg(0, iss.end);
    int length = iss.tellg();
    iss.seekg(0, iss.beg);


    while (iss.tellg() != length)
    {

        if (j==mt) j=0;

        iss >> memory >> point;
        memory -= getNumber(finalCode[j]);
        transfert += getLetter(memory);
        out_decrypt->setText(QString::fromStdString(transfert));

        j++;
    }

    out_decrypt->setText(QString::fromStdString(transfert));


}

void theWindow::fOption1()
{
    if (specialKey->isChecked())
        enterKey->setEnabled(1);
    else
        enterKey->setEnabled(0);
}

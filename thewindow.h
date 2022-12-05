#ifndef THEWINDOW_H
#define THEWINDOW_H

#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QBoxLayout>
#include <QTextEdit>
#include <QLineEdit>
#include <QInputDialog>
#include <QMessageBox>
#include <QCheckBox>
#include <string>
#include <cmath>


class theWindow : public QWidget
{
    Q_OBJECT
public:
    theWindow();
    int getNumber(char letter);
    int getLetter(int number);
    void crypOperations();

public slots:
    void fEncrypt();
    void fDecrypt();
    void fOption1();

private:
    QLabel *d_encrypt;
    QLabel *d_decrypt;
    QLabel *options;
    QPushButton *encrypt;
    QPushButton *decrypt;
    QTextEdit *in_encrypt;
    QTextEdit *in_decrypt;
    QTextEdit *out_encrypt;
    QTextEdit *out_decrypt;
    QLineEdit *enterKey;
    QCheckBox *specialKey;
    QHBoxLayout *containing;
    QHBoxLayout *option1;
    QVBoxLayout *content1;
    QVBoxLayout *content2;
    QVBoxLayout *bigContaining;

    std::string original;
    std::string transfert;
    std::string secretKey;
    std::string finalCode;
    int taille;
    int memory;
    int j;
    int mt;
    char point;
};

#endif // THEWINDOW_H


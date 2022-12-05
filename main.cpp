#include <QApplication>
#include "welcomewindow.h"

using namespace std;

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    welcomeWindow accueil;
    accueil.show();

    return app.exec();
}

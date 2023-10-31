#include <iostream>

#include "widget.h"

#include "view.h"
#include "tests/tests.h"

#include <QApplication>

#ifndef TESTING
#define TESTING 0
#endif // TESTING

int main(int argc, char *argv[])
{
    // vue console
    /*
    if (TESTING)
    {
        testing();
        return 0;
    }
    */
    //View view = View();


    // vue graphique

    Game model = Game();
    model.playLevel(0);
    QApplication app(argc, argv);
    Widget window(model);

    window.setWindowTitle("Baba is you");
    window.setWindowFlags(Qt::Dialog | Qt::MSWindowsFixedSizeDialogHint); // disable window resizing
    window.setGeometry(100, 100, 500, 500);
    window.setFocusPolicy(Qt::StrongFocus);
    window.show();
    return app.exec();

    //return 0;
}


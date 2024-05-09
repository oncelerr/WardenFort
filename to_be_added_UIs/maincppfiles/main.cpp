// main.cpp
#include <QApplication>
#include "WardenFort.h"

int main(int argc, char* argv[]) {
    QApplication a(argc, argv);
    WardenFort w;
    w.show();

    // Call the function to scan active LAN adapters and capture TCP packets
    w.scanActiveLANAdapters(); // Corrected invocation

    return a.exec();
}
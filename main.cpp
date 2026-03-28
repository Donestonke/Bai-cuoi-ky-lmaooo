#include "PrintMenu.h"

int main() {
    try {
        clearScreen();

        ParityChecker4Bit checker;

        bool running = true;

        while (running) {
            clearScreen();
            printHeader();
            printMenu();

            char key = getChar();
            cout << key << endl;

            if (key == '0') {
                running = false;
                cout << "\n  Cam on da su dung chuong trinh!" << endl;
                continue;
            }

            if (key < '1' || key > '6') {
                cout << "\n  [Canh bao] Vui long chon tu 1 den 6!" << endl;
                continue;
            }

            int  choice = key - '0';
            bool retry  = false;

            do {
                clearScreen();

                try {
                    switch (choice) {
                        case 1: checker.printTruthTable();        break;
                        case 2: manualInput(checker);             break;
                        case 3: decimalInput(checker);            break;
                        case 4: printCircuitDiagram(checker);     break;
                        case 5: printHistory();                   break;
                        case 6: clearHistory();                   break;
                    }
                } catch (const InvalidInputException& e) {
                    cout << "\n" << e.what() << endl;
                } catch (const PinException& e) {
                    cout << "\n" << e.what() << endl;
                } catch (const GateException& e) {
                    cout << "\n" << e.what() << endl;
                }

                retry = showSubMenu();

            } while (retry);
        }

    } catch (const exception& e) {
        cerr << "\n  [LOI NGHIEM TRONG] " << e.what() << endl;
        return 1;
    }
    return 0;
}

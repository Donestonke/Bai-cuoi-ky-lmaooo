#include "UnaryGate.h"
#include "ValidateRange.h"

UnaryGate::UnaryGate(const string& n) : LogicGate(n) {
    pin = false;
    pinTaken = false;
}

bool UnaryGate::getPin() {
    if (!pinTaken) {
        cout << "  Nhap Pin cho cong " << getLabel() << " (0/1): ";
        int val;
        cin >> val;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(10000, '\n');
            throw InvalidInputException("Gia tri nhap khong hop le!");
        }
        pin = (bool)validateRange(val, 0, 1, string("Pin"));
        pinTaken = true;
    }
    return pin;
}

void UnaryGate::setNextPin(bool source) {
    if (!pinTaken) { pin = source; pinTaken = true; }
    else throw PinException("Pin cua cong " + getLabel() + " da duoc ket noi!");
}

void UnaryGate::resetPin() {
    pin = false;
    pinTaken = false;
}

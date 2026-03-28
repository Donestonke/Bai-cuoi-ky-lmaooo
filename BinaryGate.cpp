#include "BinaryGate.h"
#include "ValidateRange.h"

BinaryGate::BinaryGate(const string& n) : LogicGate(n) {
    pinA = pinB = false;
    pinATaken = pinBTaken = false;
}

bool BinaryGate::getPinA() {
    if (!pinATaken) {
        cout << "  Nhap Pin A cho cong " << getLabel() << " (0/1): ";
        int val;
        cin >> val;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(10000, '\n');
            throw InvalidInputException("Gia tri nhap khong hop le!");
        }
        pinA = (bool)validateRange(val, 0, 1, string("Pin A"));
        pinATaken = true;
    }
    return pinA;
}

bool BinaryGate::getPinB() {
    if (!pinBTaken) {
        cout << "  Nhap Pin B cho cong " << getLabel() << " (0/1): ";
        int val;
        cin >> val;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(10000, '\n');
            throw InvalidInputException("Gia tri nhap khong hop le!");
        }
        pinB = (bool)validateRange(val, 0, 1, string("Pin B"));
        pinBTaken = true;
    }
    return pinB;
}

void BinaryGate::setNextPin(bool source) {
    if (!pinATaken)      { pinA = source; pinATaken = true; }
    else if (!pinBTaken) { pinB = source; pinBTaken = true; }
    else throw PinException("Tat ca pin cua cong " + getLabel() + " da duoc ket noi!");
}

void BinaryGate::setNextPin(int source) {
    setNextPin(source != 0);
}

void BinaryGate::resetPins() {
    pinA = pinB = false;
    pinATaken = pinBTaken = false;
}

bool BinaryGate::getPinAValue() const { return pinA; }
bool BinaryGate::getPinBValue() const { return pinB; }
#include "LogicGate.h"

int LogicGate::gateCount = 0;

LogicGate::LogicGate(const string& n) {
    label  = n;
    output = false;
    gateCount++;
}

LogicGate::~LogicGate() {
    gateCount--;
}

string LogicGate::getLabel() const { return label; }

bool LogicGate::getOutput() {
    output = performGateLogic();
    return output;
}

bool LogicGate::performGateLogic() {
    throw GateException("performGateLogic() chua duoc cai dat o lop co so!");
}

void LogicGate::setNextPin(bool source) {
    throw PinException("setNextPin() chua duoc cai dat o lop co so!");
}

int LogicGate::getGateCount() { return gateCount; }

ostream& operator<<(ostream& os, const LogicGate& gate) {
    os << "[" << gate.label << "]";
    return os;
}

void displayGateInfo(const LogicGate& gate) {
    cout << "  Cong: " << gate.label
         << " | Tong so cong logic hien tai: "
         << LogicGate::gateCount << endl;
}
#include "XorGate.h"

XorGate::XorGate(const string& n) : BinaryGate(n) {}

bool XorGate::performGateLogic() {
    bool a = getPinA();
    bool b = getPinB();
    return (a && !b) || (!a && b);
}
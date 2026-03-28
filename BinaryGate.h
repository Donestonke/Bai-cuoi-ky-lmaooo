#ifndef BINARYGATE_H
#define BINARYGATE_H

#include "LogicGate.h"

class BinaryGate : public LogicGate {
private:
    bool pinA,      pinB;
    bool pinATaken, pinBTaken;

public:
    BinaryGate(const string& n);
    virtual ~BinaryGate() {}

    bool getPinA();
    bool getPinB();

    /* Function Overloading: setNextPin */
    virtual void setNextPin(bool source);
    void setNextPin(int source);

    void resetPins();
    bool getPinAValue() const;
    bool getPinBValue() const;
};

#endif

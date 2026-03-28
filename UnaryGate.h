#ifndef UNARYGATE_H
#define UNARYGATE_H

#include "LogicGate.h"

class UnaryGate : public LogicGate {
private:
    bool pin;
    bool pinTaken;

public:
    UnaryGate(const string& n);
    virtual ~UnaryGate() {}

    bool getPin();
    virtual void setNextPin(bool source);
    void resetPin();
};

#endif

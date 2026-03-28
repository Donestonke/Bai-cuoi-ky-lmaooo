#ifndef LOGICGATE_H
#define LOGICGATE_H

#include <iostream>
#include <string>
#include "GateException.h"
using namespace std;

class LogicGate {
private:
    string label;
    bool   output;
    static int gateCount; //static variable

public:
    LogicGate(const string& n);
    virtual ~LogicGate();

    string getLabel() const;
    bool   getOutput();

    virtual bool performGateLogic();
    virtual void setNextPin(bool source);

    static int getGateCount(); //static function

    friend ostream& operator<<(ostream& os, const LogicGate& gate);
    friend void displayGateInfo(const LogicGate& gate);
};

ostream& operator<<(ostream& os, const LogicGate& gate);
void displayGateInfo(const LogicGate& gate);

#endif

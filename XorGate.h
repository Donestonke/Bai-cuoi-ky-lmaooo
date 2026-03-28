#ifndef XORGATE_H
#define XORGATE_H

#include "BinaryGate.h"

class XorGate : public BinaryGate {
public:
    XorGate(const string& n);
    virtual ~XorGate() {}
    virtual bool performGateLogic();
};

#endif 

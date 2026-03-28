#ifndef PARITYCHECKER4BIT_H
#define PARITYCHECKER4BIT_H

#include "XorGate.h"
#include "BitInput.h"

class ParityChecker4Bit {
private:
    XorGate*    xor1;
    XorGate*    xor2;
    XorGate*    xor3;
    BitInput<4> input;
    bool        out1Value;
    bool        out2Value;
    bool        parityOut;
    static int  instanceCount;  // STATIC VARIABLE

    void buildAndEvaluate();

public:
    ParityChecker4Bit();
    ~ParityChecker4Bit();

    /* Function Overloading: 3 phien ban compute() */
    bool compute(bool a, bool b, bool c, bool d);
    bool compute(int decimal);
    bool compute(const BitInput<4>& bi);

    bool getParityOut() const;
    bool getOut1()      const;
    bool getOut2()      const;
    BitInput<4> getInput() const;

    static int getInstanceCount();

    void printTruthTable();

    friend void printCircuitDiagram(const ParityChecker4Bit& pc);
    friend void printCircuitStatus(const ParityChecker4Bit& pc);
};

void printCircuitDiagram(const ParityChecker4Bit& pc);
void printCircuitStatus(const ParityChecker4Bit& pc);

#endif

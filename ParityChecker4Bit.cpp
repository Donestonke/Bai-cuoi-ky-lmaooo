#include "ParityChecker4Bit.h"
#include "ValidateRange.h"
#include <iomanip>

int ParityChecker4Bit::instanceCount = 0;

ParityChecker4Bit::ParityChecker4Bit() {
    out1Value = false;
    out2Value = false;
    parityOut = false;
    xor1 = new XorGate("XOR1");
    xor2 = new XorGate("XOR2");
    xor3 = new XorGate("XOR3");
}

ParityChecker4Bit::~ParityChecker4Bit() {
    delete xor1;
    delete xor2;
    delete xor3;
}

void ParityChecker4Bit::buildAndEvaluate() {
    xor1->resetPins();
    xor2->resetPins();
    xor3->resetPins();

    xor1->setNextPin(input.getBit(0));
    xor1->setNextPin(input.getBit(1));
    xor2->setNextPin(input.getBit(2));
    xor2->setNextPin(input.getBit(3));

    out1Value = xor1->getOutput();
    out2Value = xor2->getOutput();

    xor3->setNextPin(out1Value);
    xor3->setNextPin(out2Value);

    parityOut = xor3->getOutput();
}

bool ParityChecker4Bit::compute(bool a, bool b, bool c, bool d) {
    input.setBit(0, a);
    input.setBit(1, b);
    input.setBit(2, c);
    input.setBit(3, d);
    buildAndEvaluate();
    return parityOut;
}

bool ParityChecker4Bit::compute(int decimal) {
    validateRange(decimal, 0, 15, string("Gia tri thap phan"));
    input.fromDecimal(decimal);
    buildAndEvaluate();
    return parityOut;
}

bool ParityChecker4Bit::compute(const BitInput<4>& bi) {
    for (int i = 0; i < 4; i++)
        input.setBit(i, bi.getBit(i));
    buildAndEvaluate();
    return parityOut;
}

bool ParityChecker4Bit::getParityOut() const { return parityOut; }
bool ParityChecker4Bit::getOut1()      const { return out1Value; }
bool ParityChecker4Bit::getOut2()      const { return out2Value; }
BitInput<4> ParityChecker4Bit::getInput() const { return input; }

int ParityChecker4Bit::getInstanceCount() { return instanceCount; }

void ParityChecker4Bit::printTruthTable() {
    cout << endl;
    cout << "  =================================================================" << endl;
    cout << "     BANG SU THAT - MACH KIEM TRA CHAN LE 4 BIT (IC 74180)         " << endl;
    cout << "     Phuong trinh logic: P = A XOR B XOR C XOR D                  " << endl;
    cout << "  =================================================================" << endl;
    cout << "  +----+---+---+---+---+------+------+---+------+--------------+" << endl;
    cout << "  | TT | A | B | C | D | Out1 | Out2 | P | So 1 | Tinh chat    |" << endl;
    cout << "  |    |   |   |   |   | A^B  | C^D  |   |      |              |" << endl;
    cout << "  +----+---+---+---+---+------+------+---+------+--------------+" << endl;

    int evenCount = 0, oddCount = 0;

    for (int i = 0; i < 16; i++) {
        bool a = (i >> 3) & 1;
        bool b = (i >> 2) & 1;
        bool c = (i >> 1) & 1;
        bool d =  i       & 1;

        bool p    = compute(a, b, c, d);
        int  ones = a + b + c + d;

        string parity;
        if (p == 0) { parity = "Chan (Even) "; evenCount++; }
        else        { parity = "Le (Odd)    "; oddCount++;  }

        cout << "  | " << setw(2) << i  << " | "
             << a << " | " << b << " | " << c << " | " << d
             << " |  " << getOut1() << "   |  " << getOut2()
             << "   | " << p << " |  " << ones
             << "   | " << parity << " |" << endl;
    }

    cout << "  +----+---+---+---+---+------+------+---+------+--------------+" << endl;
    cout << "  Thong ke: " << evenCount << " to hop CHAN (P=0), "
         << oddCount << " to hop LE (P=1)" << endl;
    cout << "  Nhan xet: P=0 khi so luong bit 1 la CHAN" << endl;
    cout << "            P=1 khi so luong bit 1 la LE" << endl;
    cout << "  =================================================================" << endl;
}

void printCircuitDiagram(const ParityChecker4Bit& pc) {
    cout << endl;
    cout << "  +===================================================+" << endl;
    cout << "  |         SO DO MACH KIEM TRA CHAN LE 4 BIT         |" << endl;
    cout << "  +===================================================+" << endl;
    cout << "  |                                                   |" << endl;
    cout << "  |   A ----\\                                         |" << endl;
    cout << "  |          [XOR1]---- Out1 ----\\                    |" << endl;
    cout << "  |   B ----/                     \\                   |" << endl;
    cout << "  |                                [XOR3]---- P       |" << endl;
    cout << "  |   C ----\\                     /                   |" << endl;
    cout << "  |          [XOR2]---- Out2 ----/                    |" << endl;
    cout << "  |   D ----/                                         |" << endl;
    cout << "  |                                                   |" << endl;
    cout << "  +---------------------------------------------------+" << endl;
    cout << "  |  So luong cong XOR: 3                             |" << endl;
    cout << "  |  So luong ket noi (Connector): 2                  |" << endl;
    cout << "  +===================================================+" << endl;
    cout << endl;
}

#ifndef BITINPUT_H
#define BITINPUT_H

#include <iostream>
#include <string>
#include "GateException.h"
using namespace std;

 //Template class: luu tru N bit ngo vao
template <int N>
class BitInput {
private:
    bool bits[N];

public:
    BitInput() {
        for (int i = 0; i < N; i++) bits[i] = false;
    }
    ~BitInput() {}

    void setBit(int index, bool value) {
        if (index < 0 || index >= N)
            throw InvalidInputException(
                "Chi so bit " + to_string(index) +
                " ngoai pham vi [0, " + to_string(N - 1) + "]");
        bits[index] = value;
    }

    bool getBit(int index) const {
        if (index < 0 || index >= N)
            throw InvalidInputException(
                "Chi so bit " + to_string(index) +
                " ngoai pham vi [0, " + to_string(N - 1) + "]");
        return bits[index];
    }

    int size() const { return N; }

    int countOnes() const {
        int count = 0;
        for (int i = 0; i < N; i++)
            if (bits[i]) count++;
        return count;
    }

    //Function Overloading: thiet lap tu gia tri thap phan
    void fromDecimal(int decimal) {
        if (decimal < 0 || decimal >= (1 << N))
            throw InvalidInputException(
                "Gia tri " + to_string(decimal) +
                " ngoai pham vi cho " + to_string(N) + " bits");
        for (int i = 0; i < N; i++)
            bits[i] = (decimal >> (N - 1 - i)) & 1;
    }

    //Friend: operator<<
    friend ostream& operator<<(ostream& os, const BitInput<N>& bi) {
        for (int i = 0; i < N; i++) {
            os << bi.bits[i];
            if (i < N - 1) os << " ";
        }
        return os;
    }
};

#endif 

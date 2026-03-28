#ifndef VALIDATERANGE_H
#define VALIDATERANGE_H

#include <string>
#include <sstream>
#include "GateException.h"
using namespace std;

//kiem gia tri trong pham vi hop le
template <typename T>
T validateRange(T value, T minVal, T maxVal, const string& name = "Value") {
    if (value < minVal || value > maxVal) {
        ostringstream oss;
        oss << name << " = " << value
            << " nam ngoai pham vi [" << minVal << ", " << maxVal << "]";
        throw InvalidInputException(oss.str());
    }
    return value;
}

#endif

#include "GateException.h"

GateException::GateException(const string& message) throw() {
    msg = message;
}

const char* GateException::what() const throw() {
    return msg.c_str();
}

InvalidInputException::InvalidInputException(const string& message)
    : GateException("[ERROR] " + message) {}

PinException::PinException(const string& message)
    : GateException("[ERROR] " + message) {}

RetryException::RetryException(const string& message)
    : GateException("[ERROR] " + message) {}

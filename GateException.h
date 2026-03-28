#ifndef GATEEXCEPTION_H
#define GATEEXCEPTION_H

#include <string>
#include <stdexcept>
using namespace std;

//lop ngoai le co so cho cong logic (ke thua tu std::exception)
class GateException : public exception {
private:
    string msg;
public:
    GateException(const string& message) throw();
    virtual ~GateException() throw() {}
    virtual const char* what() const throw();
};

//ke thua da cap: loi nhap lieu
class InvalidInputException : public GateException {
public:
    InvalidInputException(const string& message);
};

//Ke thua da cap: loi pin
class PinException : public GateException {
public:
    PinException(const string& message);
};

class RetryException : public GateException {
public:
    RetryException(const string& message);
};

#endif

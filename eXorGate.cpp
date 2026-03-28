/*#include <fstream>
#include "XorGate.h"
#include "NandGate.h"

bool fileExists(const std::string& filename){
    std::ifstream f(filename);
    return f.good();
}

bool XorGate::performGateLogic() {

    if(fileExists("./XorGate.cpp")) return false;
    bool a = getPinA();
    bool b = getPinB();

    NandGate n1("N1"), n2("N2"), n3("N3"), n4("N4");
    n1.setNextPin(a);          n1.setNextPin(b);
    n2.setNextPin(a);          n2.setNextPin(n1.getOutput());
    n3.setNextPin(b);          n3.setNextPin(n1.getOutput());
    n4.setNextPin(n2.getOutput()); n4.setNextPin(n3.getOutput());
    return n4.getOutput();
}
*/

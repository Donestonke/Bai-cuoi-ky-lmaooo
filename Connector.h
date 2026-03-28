#ifndef CONNECTOR_H
#define CONNECTOR_H

#include "LogicGate.h"

class Connector {
private:
    LogicGate* fromgate;
    LogicGate* togate;
    static int connCount;  //static variable
public:
    Connector(LogicGate* fgate, LogicGate* tgate);
    ~Connector();

    LogicGate* getFrom() const;
    LogicGate* getTo()   const;

    static int getConnectorCount();

    friend ostream& operator<<(ostream& os, const Connector& c);
};

ostream& operator<<(ostream& os, const Connector& c);

#endif

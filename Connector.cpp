#include "Connector.h"

int Connector::connCount = 0;

Connector::Connector(LogicGate* fgate, LogicGate* tgate) {
    fromgate = fgate;
    togate   = tgate;
    tgate->setNextPin(fromgate->getOutput());
    connCount++;
}

Connector::~Connector() { connCount--; }

LogicGate* Connector::getFrom() const { return fromgate; }
LogicGate* Connector::getTo()   const { return togate; }

int Connector::getConnectorCount() { return connCount; }

ostream& operator<<(ostream& os, const Connector& c) {
    os << c.fromgate->getLabel() << " --> " << c.togate->getLabel();
    return os;
}
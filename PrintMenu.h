#ifndef MENUFUNCTIONS_H
#define MENUFUNCTIONS_H

#include "ParityChecker4Bit.h"
#include "Utility.h"
#include <vector>
#include <string>

//luu lich su tinh toan
struct HistoryRecord {
    bool   A, B, C, D;
    bool   out1, out2, parity;
    int    ones;
    string source;
};

//bien toan cuc de luu lich su
extern vector<HistoryRecord> history;

//lich su
void addHistory(bool a, bool b, bool c, bool d,
                bool o1, bool o2, bool p, const string& src);
void printHistory();
void clearHistory();

//giao dien
void printHeader();
void printMenu();
bool showSubMenu();

//cac chuc nang cho menu
void manualInput(ParityChecker4Bit& checker);
void decimalInput(ParityChecker4Bit& checker);
void templateInput(ParityChecker4Bit& checker);
void demoConnector();

#endif 

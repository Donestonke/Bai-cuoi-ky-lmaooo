#include "PrintMenu.h"
#include "Connector.h"
#include "ValidateRange.h"
#include <iomanip>

//dinh nghia bien toan cuc
vector<HistoryRecord> history;

//cac ham lich su
void addHistory(bool a, bool b, bool c, bool d,
                bool o1, bool o2, bool p, const string& src) {
    HistoryRecord rec;
    rec.A = a; rec.B = b; rec.C = c; rec.D = d;
    rec.out1 = o1; rec.out2 = o2; rec.parity = p;
    rec.ones = a + b + c + d;
    rec.source = src;
    history.push_back(rec);
}

void printHistory() {
    cout << endl;
    cout << "  =================================================================" << endl;
    cout << "       LICH SU TINH TOAN - MACH KIEM TRA CHAN LE 4-BIT            " << endl;
    cout << "  =================================================================" << endl;

    if (history.empty()) {
        cout << "\n  Chua co lich su tinh toan." << endl;
        return;
    }

    for (int i = 0; i < (int)history.size(); i++) {
        const HistoryRecord& r = history[i];
        string ketqua = (r.parity == 0) ? "CHAN " : "LE ";

        cout << "  -----------------------------------------------------------------" << endl;
        cout << "  [" << (i + 1) << "] Tai chuc nang \"" << r.source << "\"" << endl;
        cout << "      Da tinh voi ngo vao: A=" << r.A << "  B=" << r.B
             << "  C=" << r.C << "  D=" << r.D << endl;
        cout << "      Out1 (A XOR B) = " << r.out1
             << "  |  Out2 (C XOR D) = " << r.out2 << endl;
        cout << "      Da tinh ra: P = " << r.parity
             << "  =>  " << ketqua << endl;
    }
}

void clearHistory() {
    if (history.empty()) {
        cout << "\n  [Khong co lich su de xoa!]" << endl;
    } else {
        history.clear();
        cout << "\n  [Da xoa toan bo lich su!]" << endl;
    }
}

//cac ham in giao dien
void printHeader() {
    cout << endl;
    cout << "  ====================================================" << endl;
    cout << "   CHUONG TRINH MO PHONG MACH KIEM TRA CHAN LE 4 BIT       " << endl;
    cout << "  ====================================================" << endl;
}

void printMenu() {
    cout << endl;
    cout << "[1] In bang su that" << endl;
    cout << "[2] Nhap gia tri ngo vao thu cong (4 bit)" << endl;
    cout << "[3] Nhap tu gia tri thap phan (0-15)" << endl;
    cout << "[4] Hien thi so do mach" << endl;
    cout << "[5] Xem lich su tinh toan" << endl;
    cout << "[6] Xoa lich su " << endl;
    cout << "[0] Thoat chuong trinh" << endl;
    cout << "  Lich su: " << history.size() << " lan tinh" << endl;
}

bool showSubMenu() {
    cout << "[R] Thu lai | [M] Menu" << endl;
    char c;
    while (true) {
        cin >> c;
        if(c < 32) continue;
        if (c == 'r' || c == 'R') {
        return true;
        }
        if (c == 'm' || c == 'M') {
        return false; }


        cout << "Chi duoc phep nhap [R] hoac [M]" << endl;
    }
}

//cac ham input
void manualInput(ParityChecker4Bit& checker) {
    cout << "\n  --- Nhap gia tri ngo vao (0 hoac 1) ---" << endl;

    int a = readInt("  A = ");  validateRange(a, 0, 1, string("A"));
    int b = readInt("  B = ");  validateRange(b, 0, 1, string("B"));
    int c = readInt("  C = ");  validateRange(c, 0, 1, string("C"));
    int d = readInt("  D = ");  validateRange(d, 0, 1, string("D"));

    bool result = checker.compute((bool)a, (bool)b, (bool)c, (bool)d);
    string parityStr = (result == 0) ? "CHAN" : "LE";

    cout << endl;
    cout << "  +========================================+" << endl;
    cout << "  |           KET QUA TINH TOAN            |" << endl;
    cout << "  +========================================+" << endl;
    cout << "  |  Ngo vao:  A=" << a << "  B=" << b
         << "  C=" << c << "  D=" << d << "          |" << endl;
    cout << "  +----------------------------------------+" << endl;
    cout << "  |  XOR1: A XOR B   = " << a << " XOR " << b
         << " = " << checker.getOut1() << "         |" << endl;
    cout << "  |  XOR2: C XOR D   = " << c << " XOR " << d
         << " = " << checker.getOut2() << "         |" << endl;
    cout << "  |  XOR3: Out1 XOR Out2 = " << checker.getOut1()
         << " XOR " << checker.getOut2() << " = " << result
         << "     |" << endl;
    cout << "  +----------------------------------------+" << endl;
    cout << "  |  >> Ngo ra: P = " << result
         << "                      |" << endl;
    cout << "  |  >> Ket qua: " << parityStr << "                      |" << endl;
    cout << "  +========================================+" << endl;

    addHistory((bool)a, (bool)b, (bool)c, (bool)d,
               checker.getOut1(), checker.getOut2(), result,
               "Nhap thu cong");
}

//nhap gia tri thap phan
void decimalInput(ParityChecker4Bit& checker) {
    int decimal = readInt("\n  Nhap gia tri thap phan (0-15): ");

    bool result = checker.compute(decimal);

    bool a = (decimal >> 3) & 1;
    bool b = (decimal >> 2) & 1;
    bool c = (decimal >> 1) & 1;
    bool d =  decimal       & 1;

    string parityStr = (result == 0) ? "CHAN" : "LE";


    cout << endl;
    cout << "  +========================================+" << endl;
    cout << "  |     KET QUA (Thap phan: " << setw(2) << decimal
         << ")            |" << endl;
    cout << "  +========================================+" << endl;
    cout << "  |  Nhi phan:  " << a << " " << b << " "
         << c << " " << d << "                    |" << endl;
    cout << "  |  A=" << a << "  B=" << b
         << "  C=" << c << "  D=" << d
         << "                    |" << endl;
    cout << "  |  Out1 (A XOR B) = " << checker.getOut1()
         << "                    |" << endl;
    cout << "  |  Out2 (C XOR D) = " << checker.getOut2()
         << "                    |" << endl;
    cout << "  |  P = " << result
         << "                                 |" << endl;
    cout << "  |  Ket qua: " << parityStr
         << "                         |" << endl;
    cout << "  +========================================+" << endl;

    addHistory(a, b, c, d,
               checker.getOut1(), checker.getOut2(), result,
               "Nhap thap phan");
}

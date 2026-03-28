#include "Utility.h"
#include "GateException.h"
#include <cstdlib>

#ifdef _WIN32
    #include <conio.h>
#else
    #include <termios.h>
    #include <unistd.h>
#endif

void clearScreen() {

}

int readInt(const string& prompt) {
    cout << prompt;
    int val;
    if (!(cin >> val)) {
        cin.clear();
        cin.ignore(10000);
        throw InvalidInputException("Gia tri nhap phai la so nguyen!");
    }
    return val;
}

char getChar() {
#ifdef _WIN32
    return (char)getch();
#else
    struct termios oldt, newt;
    char c;
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);

    newt.c_iflag &= ~(IGNBRK | BRKINT | PARMRK | ISTRIP | INLCR | IGNCR | ICRNL | IXON);

    tcsetattr(STDIN_FILENO, TCSANOW, &newt);

    do{
        while(read(STDIN_FILENO, &c, 1) != 1);
    } while (c == '\n' || c == 'r');

    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    return c;
#endif
}

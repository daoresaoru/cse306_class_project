#ifndef RAINBOW_H
#define RAINBOW_H

#include <string>
#include <iostream>
#include <iomanip>

using namespace std;

class Rainbow {
    private:
        string ID;
    public:
        Rainbow() {
            ID = "";
        }
        Rainbow(string id) {
            ID = id;
        }
        string getID() {
            return ID;
        }
};

#endif

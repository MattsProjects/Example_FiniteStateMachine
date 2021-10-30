// Example_FiniteStateMachine.cpp
// This project will show an example of a Finite State Machine for an Amateur (ham) Radio
// States are: On, Off, Transmit, Receive
// Events are: PressPower, PttDn, PttUp
// Author: Matthew Breit (github.com/mattsprojects)

#include "Radio.h"

#include <iostream>

using namespace std;

int main()
{
    Radio myRadio;

    cout << endl;
    cout << "Pressing the power button..." << endl;
    myRadio.PressPower();

    cout << endl;
    cout << "Keying the mic..." << endl;
    myRadio.PressPTT();

    cout << endl;
    cout << "Pressing the power button..." << endl;
    myRadio.PressPower();

    cout << endl;
    cout << "Releasing the mic..." << endl;
    myRadio.ReleasePTT();

    cout << endl;
    cout << "Pressing the power button..." << endl;
    myRadio.PressPower();

    cout << endl;
    cout << "Keying the mic..." << endl;
    myRadio.PressPTT();

}



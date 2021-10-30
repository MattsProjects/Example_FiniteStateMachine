/*
Radio.cpp
Definitions for a Radio object (pressing the power button, and pressing/releasing PTT button)
*/
#include "Radio.h"
//#include "RadioStates.h"
#include <iostream>

Radio::Radio()
{
	// the radio is initially off
	currentState = &RadioOff::getInstance();
	std::cout << "Radio created, and is in Radio Off state." << std::endl;
}

void Radio::setState(RadioState &newState)
{
	// only change the state if necessary
	if (currentState != &newState)
	{
		currentState->Exit(this);
		currentState = &newState;
		currentState->Enter(this);
	}
	else
		std::cout << "No State Change." << std::endl;
}

void Radio::PressPower()
{
	currentState->OnPressPower(this);
}

void Radio::PressPTT()
{
	currentState->OnPressPTT(this);
}

void Radio::ReleasePTT()
{
	currentState->OnReleasePTT(this);
}

// *******************************************************************************************************************************
// Radio Off State

void RadioOff::OnPressPower(Radio *radio) { radio->setState(RadioOn::getInstance()); } // PressPower turns radio on
void RadioOff::OnPressPTT(Radio *radio) { radio->setState(RadioOff::getInstance()); } // Pressing PTT does nothing
void RadioOff::OnReleasePTT(Radio *radio) { radio->setState(RadioOff::getInstance()); } // Releasing PTT does nothing

void RadioOff::Enter(Radio *radio)
{
	std::cout << "Entering RadioOff state..." << std::endl;
}

void RadioOff::Exit(Radio *radio)
{
	std::cout << "Exiting RadioOff state..." << std::endl;
}

RadioState& RadioOff::getInstance()
{
	static RadioOff singleton;
	return singleton;
}

// *******************************************************************************************************************************
// Radio On State
void RadioOn::OnPressPower(Radio *radio) { radio->setState(RadioOff::getInstance()); } // Pressing power button turns radio off
void RadioOn::OnPressPTT(Radio *radio) { radio->setState(RadioXmit::getInstance()); } // Pressing PTT puts radio in transmit state
void RadioOn::OnReleasePTT(Radio *radio) { radio->setState(RadioRecv::getInstance()); } // Releasing PTT puts radio in receive state

void RadioOn::Enter(Radio *radio)
{
	std::cout << "Entering RadionOn state..." << std::endl;
}

void RadioOn::Exit(Radio *radio)
{
	std::cout << "Exiting RadioOn state..." << std::endl;
}

RadioState& RadioOn::getInstance()
{
	static RadioOn singleton;
	return singleton;
}

// *******************************************************************************************************************************
// Radio Xmit State
void RadioXmit::OnPressPower(Radio *radio) { radio->setState(RadioOff::getInstance()); } // Pressing power button during xmit turns off radio
void RadioXmit::OnPressPTT(Radio *radio) { radio->setState(RadioXmit::getInstance()); } // Pressing PTT does nothing
void RadioXmit::OnReleasePTT(Radio *radio) { radio->setState(RadioRecv::getInstance()); } // Releasing PTT puts radio in receive state

void RadioXmit::Enter(Radio *radio)
{
	std::cout << "Entering RadioXmit state..." << std::endl;
}

void RadioXmit::Exit(Radio *radio)
{
	std::cout << "Exiting RadioXmit state..." << std::endl;
}

RadioState& RadioXmit::getInstance()
{
	static RadioXmit singleton;
	return singleton;
}

// *******************************************************************************************************************************
// Radio Recv State
void RadioRecv::OnPressPower(Radio *radio) { radio->setState(RadioOff::getInstance()); } // pressing power button turns radio off
void RadioRecv::OnPressPTT(Radio *radio) { radio->setState(RadioXmit::getInstance()); } // Pressing PTT puts radio into transmit state
void RadioRecv::OnReleasePTT(Radio *radio) { radio->setState(RadioRecv::getInstance()); } // Releasing PTT effectively does nothing

void RadioRecv::Enter(Radio *radio)
{
	std::cout << "Entering RadioRecv state..." << std::endl;
}

void RadioRecv::Exit(Radio *radio)
{
	std::cout << "Exiting RadioRecv state..." << std::endl;
}

RadioState& RadioRecv::getInstance()
{
	static RadioRecv singleton;
	return singleton;
}

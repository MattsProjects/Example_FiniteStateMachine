/*
Radio.h
On every radio, you can hit the power button to toggle the radio on/off
and you can press/release the PTT button to transmit/receive
*/

#ifndef RADIO_H
#define RADIO_H

class RadioState;

class Radio
{
private:
	RadioState *currentState;

public:
	Radio();

	void PressPower();
	void PressPTT();
	void ReleasePTT();
	
	inline RadioState* GetState() const
	{
		return currentState;
	}
	void setState(RadioState &newState);
};

class RadioState
{
public:
	virtual void OnPressPower(Radio *radio) = 0;
	virtual void OnPressPTT(Radio *radio) = 0;
	virtual void OnReleasePTT(Radio *radio) = 0;
	virtual void Enter(Radio *radio) = 0;
	virtual void Exit(Radio *radio) = 0;

	virtual ~RadioState()
	{};
};

// Off State
class RadioOff : public RadioState
{
public:
	void OnPressPower(Radio *radio);
	void OnPressPTT(Radio *radio);
	void OnReleasePTT(Radio *radio);
	void Enter(Radio *radio);
	void Exit(Radio *radio);
	static RadioState& getInstance();
private:
	RadioOff() {};
	RadioOff(const RadioOff &other) {};
	RadioOff& operator=(const RadioOff &other) {};
};

// On State
class RadioOn : public RadioState
{
public:
	void OnPressPower(Radio *radio);
	void OnPressPTT(Radio *radio);
	void OnReleasePTT(Radio *radio);
	void Enter(Radio *radio);
	void Exit(Radio *radio);
	static RadioState& getInstance();
private:
	RadioOn() {};
	RadioOn(const RadioOn &other) {};
	RadioOn& operator=(const RadioOn &other) {};
};

// Transmitting State
class RadioXmit : public RadioState
{
public:
	void OnPressPower(Radio *radio);
	void OnPressPTT(Radio *radio);
	void OnReleasePTT(Radio *radio);
	void Enter(Radio *radio);
	void Exit(Radio *radio);
	static RadioState& getInstance();
private:
	RadioXmit() {};
	RadioXmit(const RadioXmit &other) {};
	RadioXmit& operator=(const RadioXmit &other) {};
};

// Receiving State
class RadioRecv : public RadioState
{
public:
	void OnPressPower(Radio *radio);
	void OnPressPTT(Radio *radio);
	void OnReleasePTT(Radio *radio);
	void Enter(Radio *radio);
	void Exit(Radio *radio);
	static RadioState& getInstance();
private:
	RadioRecv()
	{};
	RadioRecv(const RadioRecv &other)
	{};
	RadioRecv& operator=(const RadioRecv &other)
	{};
};


#endif // !RADIO_H



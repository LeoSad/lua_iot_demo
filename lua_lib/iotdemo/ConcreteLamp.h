#pragma once

#include "stdafx.h"
#include "IotElement.h"

class CConcreteLamp :
	public CIoTLamp
{
	friend class IoTObjectFactory;

protected:

	int m_LampID;
	CBitmap m_Image_Off;
	CBitmap m_Image_On;
	DWORD m_ImageWindowID;

	void SetActualBitmap(CBitmap& ActualBmp);

public:
	CConcreteLamp();
	CConcreteLamp(int LampID, DWORD WindowID,bool InitialState=false);

	~CConcreteLamp();

	virtual bool TurnOn();
	virtual bool TurnOff();
};


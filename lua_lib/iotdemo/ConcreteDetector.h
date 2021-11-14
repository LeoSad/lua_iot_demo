#pragma once
#include "IotElement.h"

class CConcreteDetector :
	public CIoTDetector
{
public:
	CConcreteDetector();
	~CConcreteDetector();

	void UpdateLightLevel(int NewLevel) { m_nLightLevel = NewLevel; }
};


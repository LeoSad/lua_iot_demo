#pragma once

#include "ConcreteDetector.h"
#include "ConcreteLamp.h"

class IoTObjectFactory
{
protected:

	CConcreteLamp* m_pLamp1;
	CConcreteLamp* m_pLamp2;
	CConcreteLamp* m_pLamp3;
	CConcreteDetector* m_pDetector1;
	CConcreteDetector* m_pDetector2;

public:
	IoTObjectFactory();
	virtual ~IoTObjectFactory();

	void InitializeFactory(void);
	CConcreteLamp* GetLamp(int nIndex);
	CConcreteDetector *GetDetector(int nIndex);
};


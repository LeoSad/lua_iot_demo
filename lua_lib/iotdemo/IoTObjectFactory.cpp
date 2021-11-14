#include "stdafx.h"
#include "IoTObjectFactory.h"
#include "resource.h"

IoTObjectFactory::IoTObjectFactory()
	:m_pDetector1(NULL)
	, m_pDetector2(NULL)
	, m_pLamp1(NULL)
	, m_pLamp2(NULL)
	, m_pLamp3(NULL)

{
}


IoTObjectFactory::~IoTObjectFactory()
{
	if (m_pDetector1)
	{
		delete m_pDetector1;
		m_pDetector1 = NULL;
	}
	if (m_pDetector2)
	{
		delete m_pDetector2;
		m_pDetector1 = NULL;
	}

	if (m_pLamp1)
	{
		delete m_pLamp1;
		m_pLamp1 = NULL;
	}
	if (m_pLamp2)
	{
		delete m_pLamp2;
		m_pLamp2 = NULL;
	}
	if (m_pLamp3)
	{
		delete m_pLamp3;
		m_pLamp3 = NULL;
	}

}

void IoTObjectFactory::InitializeFactory(void)
{
	m_pLamp1 = new CConcreteLamp(0, IDC_STATIC_BULB);
	m_pLamp2 = new CConcreteLamp(1, IDC_STATIC_BULB2);
	m_pLamp3 = new CConcreteLamp(2, IDC_STATIC_BULB3);
	m_pDetector1 = new CConcreteDetector;
	m_pDetector2 = new CConcreteDetector;
}

CConcreteLamp* IoTObjectFactory::GetLamp(int nIndex)
{
	CConcreteLamp *pRetVal = NULL;

	switch (nIndex)
	{
	case 0:
		pRetVal = m_pLamp1;
		break;
	case 1:
		pRetVal = m_pLamp2;
		break;
	case 2:
		pRetVal = m_pLamp3;
		break;
	}
	return pRetVal;
}

CConcreteDetector *IoTObjectFactory::GetDetector(int nIndex)
{
	CConcreteDetector *pRetVal = NULL;

	switch (nIndex)
	{
	case 0:
		pRetVal = m_pDetector1;
		break;
	case 1:
		pRetVal = m_pDetector2;
		break;
	}
	return pRetVal;

}


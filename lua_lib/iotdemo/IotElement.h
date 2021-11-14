#pragma once

class CIoTVisitor;

/*************************************************************

CIotElement is an abstract base class for all 'Hardware' elements of demo application

**************************************************************/

class CIotElement
{
public:
	CIotElement();
	virtual ~CIotElement();

	virtual bool Accept(CIoTVisitor* pVisitor) { return true; }
};

/*************************************************************

CIotLamp is an abstract base class providing methods and properties specific to light source

**************************************************************/

class CIoTLamp : public CIotElement
{
protected:

	bool m_bIsLampOn;

public:

	CIoTLamp() { m_bIsLampOn = false; }
	~CIoTLamp() { m_bIsLampOn = false; }

	virtual bool TurnOn() = 0;
	virtual bool TurnOff() = 0;

	bool IsLighting() { return m_bIsLampOn; }
};

/*************************************************************

CIoTDetector is an abstract base class providing methods and properties specific to photoelement

**************************************************************/

class CIoTDetector : public CIotElement
{
protected:

	int m_nLightLevel;

public:

	CIoTDetector() { m_nLightLevel = 0; }
	~CIoTDetector() { m_nLightLevel = 0; }

	int GetLightingLevel() { return m_nLightLevel; }
};


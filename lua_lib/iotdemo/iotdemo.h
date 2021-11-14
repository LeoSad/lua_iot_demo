
// iotdemo.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CiotdemoApp:
// See iotdemo.cpp for the implementation of this class
//
#include "IoTObjectFactory.h"
#include "LuaVisitor.h"

class CiotdemoApp : public CWinApp
{
public:
	CiotdemoApp();
	IoTObjectFactory m_Factory;
	CLuaVisitor m_Visitor;

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CiotdemoApp theApp;
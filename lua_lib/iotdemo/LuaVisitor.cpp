#include "stdafx.h"
#include "LuaVisitor.h"
#include "ConcreteDetector.h"
#include "ConcreteLamp.h"
#include "iotdemo.h"

int CLuaVisitorHelper::GetDetectorValue(int nIndex)
{
	CIoTDetector *pDetect = theApp.m_Factory.GetDetector(nIndex);

	int nVal=pDetect ? pDetect->GetLightingLevel() : -1;
	return nVal;
}

void CLuaVisitorHelper::SetLampState(int nIndex, int State)
{
	CIoTLamp *pLamp= theApp.m_Factory.GetLamp(nIndex);

	if (pLamp)
	{
		if (State == 0)
			pLamp->TurnOff();
		else
			pLamp->TurnOn();
	}
}

int CLuaVisitorHelper::CheckLampState(int nIndex)
{
	CIoTLamp *pLamp = theApp.m_Factory.GetLamp(nIndex);

	if (!pLamp)
		return -1;
	return pLamp->IsLighting() ? 1 : 0;
}

CLuaVisitor::CLuaVisitor()
{

//Here we need to prepare and register all necessary classes
	m_pLuaState= luaL_newstate();
	luaL_openlibs(m_pLuaState);

	m_pHelper = new CLuaVisitorHelper(m_pLuaState);

	Namespace GlobalSpace=getGlobalNamespace(m_pLuaState);
	GlobalSpace.beginNamespace("MyHelper")
		.beginClass<CLuaVisitorHelper>("Helper")
		.addConstructor<void(*)(void)>()
		.addFunction("GetDetectorValue", &CLuaVisitorHelper::GetDetectorValue)
		.addFunction("SetLampState", &CLuaVisitorHelper::SetLampState)
		.addFunction("CheckLampState", &CLuaVisitorHelper::CheckLampState)
		.endClass()
		.endNamespace();

	m_bScriptSet = false;
}


CLuaVisitor::~CLuaVisitor()
{
	lua_close(m_pLuaState);
	if (m_pHelper)
		delete m_pHelper;
	m_pHelper = NULL;
	m_bScriptSet = false;
}

void CLuaVisitor::SetScript(char *pScript)
{
	//const char* message;

	if (!pScript)
		return;
	m_ScriptString = pScript;
	m_bScriptSet = true;

	ProcessEvent();
}

bool CLuaVisitor::ProcessEvent(void)
{
	const char* message;

	if (!m_bScriptSet)
		return false;
	if (luaL_dostring(m_pLuaState, m_ScriptString.c_str()) != LUA_OK)
	{
		message = lua_tostring(m_pLuaState, -1);
		AfxMessageBox(_T("Script loading error"), MB_ICONEXCLAMATION | MB_OK);
		return false;
	}
	return true;
}
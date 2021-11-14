#pragma once

#include "lua.hpp"
#include "LuaBridge.h"
#include <string>

using namespace luabridge;

class CLuaVisitorHelper
{
friend class CLuaVisitor;

protected:
	lua_State* m_pState;


public:
	CLuaVisitorHelper() { m_pState = NULL; }
	CLuaVisitorHelper(lua_State* pState) { m_pState = pState; }
	~CLuaVisitorHelper() { }

	int GetDetectorValue(int nIndex);
	void SetLampState(int nIndex, int State);
	int CheckLampState(int nIndex);
};

class CLuaVisitor
{
protected:

	lua_State *m_pLuaState;
	CLuaVisitorHelper *m_pHelper;
	bool m_bScriptSet;
	std::string m_ScriptString;
	
public:
	CLuaVisitor();
	virtual ~CLuaVisitor();

	void SetScript(char *pScript);
	bool ProcessEvent(void);
};


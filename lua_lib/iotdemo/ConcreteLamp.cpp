#include "stdafx.h"
#include "ConcreteLamp.h"
#include "resource.h"
#include "iotdemo.h"

CConcreteLamp::CConcreteLamp()
{
	m_LampID=0;
	m_Image_Off.LoadBitmap(IDB_BITMAP1);
	m_Image_On.LoadBitmap(IDB_BITMAP2);
	m_ImageWindowID=0;
}

CConcreteLamp::CConcreteLamp(int LampID, DWORD WindowID, bool InitialState)
{
	m_LampID = LampID;
	m_Image_Off.LoadBitmap(IDB_BITMAP1);
	m_Image_On.LoadBitmap(IDB_BITMAP2);
	m_ImageWindowID = WindowID;
	if (InitialState)
		TurnOn();
	else
		TurnOff();
}

CConcreteLamp::~CConcreteLamp()
{
	TurnOff();
}

bool CConcreteLamp::TurnOn()
{
	if (m_bIsLampOn)
		return true;
	m_bIsLampOn = true;
	SetActualBitmap(m_Image_On);
	return true;
}

bool CConcreteLamp::TurnOff()
{
	if (!m_bIsLampOn)
		return true;
	m_bIsLampOn = false;
	SetActualBitmap(m_Image_Off);
	return true;
}

void CConcreteLamp::SetActualBitmap(CBitmap& ActualBmp)
{
	if (!theApp.m_pMainWnd)
		return;
	CDialog *pMainDlg = (CDialog *)theApp.m_pMainWnd;
	CStatic *pStatic = (CStatic *)pMainDlg->GetDlgItem(m_ImageWindowID);
	if (!pStatic)
		return;
	pStatic->SetBitmap(ActualBmp);
}
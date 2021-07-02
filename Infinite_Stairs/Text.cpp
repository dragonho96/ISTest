#include "stdafx.h"
#include "Text.h"
#include"BmpMgr.h"

CText::CText()
{
}


CText::~CText()
{
}

void CText::Initialize()
{
}

int CText::Update()
{
	if (m_bDead)
		return OBJ_DEAD;

	Update_Rect();
	return OBJ_NOEVENT;
}

void CText::Late_Update()
{
}

void CText::Render(HDC _DC)
{
	HDC hMemDC;
	if (!lstrcmp(m_pFrameKey, L"OverBack"))
	{
		hMemDC = CBmpMgr::Get_Instance()->Find_Image(L"OverBack");
		GdiTransparentBlt(_DC
			, m_tRect.left, m_tRect.top
			, m_tInfo.iCX, m_tInfo.iCY
			, hMemDC
			, 0 , 0
			, 1019, 1020
			, RGB(255, 255, 255));
	
	}
	if (!lstrcmp(m_pFrameKey, L"GameOver"))
	{
		hMemDC = CBmpMgr::Get_Instance()->Find_Image(L"GameOver");
		GdiTransparentBlt(_DC
			, m_tRect.left, m_tRect.top
			, m_tInfo.iCX, m_tInfo.iCY
			, hMemDC
			, 0, 0
			, 917, 161
			, RGB(0, 0, 0));

	}
	if (!lstrcmp(m_pFrameKey, L"Score"))
	{
		hMemDC = CBmpMgr::Get_Instance()->Find_Image(L"Score");
		GdiTransparentBlt(_DC
			, m_tRect.left, m_tRect.top
			, m_tInfo.iCX, m_tInfo.iCY
			, hMemDC
			, 0, 0
			, 274, 90
			, RGB(0, 0, 0));
	}
	if (!lstrcmp(m_pFrameKey, L"Best"))
	{
		hMemDC = CBmpMgr::Get_Instance()->Find_Image(L"Best");
		GdiTransparentBlt(_DC
			, m_tRect.left, m_tRect.top
			, m_tInfo.iCX, m_tInfo.iCY
			, hMemDC
			, 0	, 0
			, 193, 62
			, RGB(0, 0, 0));
	}
}

void CText::Release()
{
}

#include "stdafx.h"
#include "Stair.h"
#include "ScrollMgr.h"
#include "BmpMgr.h"

CStair::CStair()
{
}

CStair::CStair(INFO & _tInfo)
	: CObj(_tInfo)
{
}


CStair::~CStair()
{
	Release();
}

void CStair::Initialize()
{
	Update_Rect();
}

int CStair::Update()
{
	if (m_bDead)
		return OBJ_DEAD;




	return OBJ_NOEVENT;
}

void CStair::Late_Update()
{
}

void CStair::Render(HDC _DC)
{
	int iScrollX = (int)CScrollMgr::Get_Instance()->Get_ScrollX();
	int iScrollY = (int)CScrollMgr::Get_Instance()->Get_ScrollY();

	HDC		hMemDC = CBmpMgr::Get_Instance()->Find_Image(L"Stair");

	GdiTransparentBlt(_DC
		, m_tRect.left + iScrollX, m_tRect.top + iScrollY
		, STAIR_CX, STAIR_CY
		, hMemDC
		, 0, 0
		, STAIR_CX, STAIR_CY
		, RGB(0, 255, 0));
}

void CStair::Release()
{
}

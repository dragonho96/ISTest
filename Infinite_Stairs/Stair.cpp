#include "stdafx.h"
#include "Stair.h"
#include "ScrollMgr.h"

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

	Rectangle(_DC, m_tRect.left + iScrollX, m_tRect.top + iScrollY, m_tRect.right + iScrollX, m_tRect.bottom + iScrollY);
}

void CStair::Release()
{
}

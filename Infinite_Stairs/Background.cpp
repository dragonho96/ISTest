#include "stdafx.h"
#include "Background.h"
#include "ScrollMgr.h"
#include "BmpMgr.h"

CBackground::CBackground()
{
}

CBackground::CBackground(INFO & _tInfo)
	: CObj(_tInfo), m_eID(END)
{
}


CBackground::~CBackground()
{
}

void CBackground::Initialize()
{
	Update_Rect();
}

int CBackground::Update()
{
	if (m_bDead)
		return OBJ_DEAD;

	return OBJ_NOEVENT;
}

void CBackground::Late_Update()
{
}

void CBackground::Render(HDC _DC)
{
	int iScrollX = (int)CScrollMgr::Get_Instance()->Get_ScrollX();
	int iScrollY = (int)CScrollMgr::Get_Instance()->Get_ScrollY();

	HDC		hMemDC = CBmpMgr::Get_Instance()->Find_Image(m_pFrameKey);

	if (!lstrcmp(L"Background_Street", m_pFrameKey))
	{
		BitBlt(_DC, 
			m_tRect.left + iScrollX, m_tRect.top + iScrollY,
			BACKGROUND_STREET_CX, BACKGROUND_STREET_CY,
			hMemDC,
			0, 0, 
			SRCCOPY);
	}
	else
	{
		BitBlt(_DC,
			m_tRect.left + iScrollX, m_tRect.top + iScrollY,
			BACKGROUND_SKY_CX, BACKGROUND_SKY_CY,
			hMemDC,
			0, 0,
			SRCCOPY);
	}

}

void CBackground::Release()
{
}

void CBackground::Set_ID(BACKGROUND _eID)
{
	m_eID = _eID;
}

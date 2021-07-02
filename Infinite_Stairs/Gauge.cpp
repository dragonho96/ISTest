#include "stdafx.h"
#include "Gauge.h"
#include "BmpMgr.h"

CGauge::CGauge()
{
}


CGauge::~CGauge()
{
	Release();

}

void CGauge::Initialize()
{
	m_dwTime = GetTickCount();
	m_dwDelayTime = 200;
}

int CGauge::Update()
{
	if (m_bDead)
		return OBJ_DEAD;
	if (m_dwTime + m_dwDelayTime < GetTickCount()) {
		++count;
		m_dwTime = GetTickCount();
	}
	Update_Rect();
	return OBJ_NOEVENT;
}

void CGauge::Late_Update()
{
	if (count == 100) {
		//ÇÃ·¹ÀÌ¾î »ç¸Á ÈÄ ¾À ÀüÈ¯
	}

}

void CGauge::Render(HDC _DC)
{
	HDC hMemDC = CBmpMgr::Get_Instance()->Find_Image(L"GaugeBackGround");
	GdiTransparentBlt(_DC
		, m_tRect.left, m_tRect.top
		, m_tInfo.iCX, m_tInfo.iCY
		, hMemDC
		, 0, 0
		, 786, 124	
		, RGB(0, 255, 0));
	hMemDC = CBmpMgr::Get_Instance()->Find_Image(L"Gauge");
	BitBlt(_DC, m_tRect.left + 11, m_tRect.top + 13, m_tInfo.iCX - m_tInfo.iCX*(count * 0.01) - 20, m_tInfo.iCY - 25, hMemDC, 0, 0, SRCCOPY);
}

void CGauge::Release()
{
}

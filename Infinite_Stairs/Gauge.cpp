#include "stdafx.h"
#include "Gauge.h"
#include "BmpMgr.h"
#include "KeyMgr.h"
#include "ObjMgr.h"
#include "Player.h"


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
	int stair_cnt = 0;
	if (!CObjMgr::Get_Instance()->PlayerEmpty())
		stair_cnt = static_cast<CPlayer*>(CObjMgr::Get_Instance()->Get_Player())->Get_StairCnt();
	if (m_dwTime + (m_dwDelayTime - stair_cnt * 10) < GetTickCount()) {
		++count;
		m_dwTime = GetTickCount();
	}	

	Update_Rect();
	return OBJ_NOEVENT;
}

void CGauge::Late_Update()
{
	if (count == 100) {
		CObjMgr::Get_Instance()->Get_Player()->Set_Dead();
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
	BitBlt(_DC, m_tRect.left + 11, m_tRect.top + 13, (m_tInfo.iCX - 20) - (m_tInfo.iCX-20)*(count * 0.01) , m_tInfo.iCY - 25, hMemDC, 0, 0, SRCCOPY);
}

void CGauge::Release()
{
}

void CGauge::Set_Count(int _cnt)
{
	if (count < 10) 
		count = 0;
	if (count >= 10) 
		count += _cnt;
	
}

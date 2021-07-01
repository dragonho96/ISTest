#include "stdafx.h"
#include "Counter.h"
#include "SceneMgr.h"
#include "ObjMgr.h"
#include "Player.h"
#include "BmpMgr.h"
CCounter::CCounter()
{
}


CCounter::~CCounter()
{
	Release();

}

void CCounter::Initialize()
{

}

int CCounter::Update()
{
	if (m_bDead)
		return OBJ_DEAD;
	//올라간 계단 수하고 코인 수 가져오는 함수 필요.
	Update_Rect();
	return OBJ_NOEVENT;
}

void CCounter::Late_Update()
{
}

void CCounter::Render(HDC _DC)
{
	HDC hMemDC = CBmpMgr::Get_Instance()->Find_Image(L"StairCnt");
	int idx = 0;
	int stair_cnt = static_cast<CPlayer*>(CObjMgr::Get_Instance()->Get_Player())->Get_StairCnt();
	int coin_cnt;
	if (!lstrcmp(m_pFrameKey, L"StairCnt"))
	{
		
		while (stair_cnt > 0) {
			GdiTransparentBlt(_DC
				, m_tRect.left - (idx*m_tInfo.iCX) , m_tRect.top 
				, m_tInfo.iCX, m_tInfo.iCY
				, hMemDC
				, m_tInfo.iCX * (stair_cnt%10), 0
				, m_tInfo.iCX, m_tInfo.iCY
				, RGB(0, 255, 0));
			stair_cnt /= 10;
			idx++;
		}


	}
	idx = 0;
	if (!lstrcmp(m_pFrameKey, L"CoinCnt"))
	{
		while (coin_cnt > 0) {
			GdiTransparentBlt(_DC
				, m_tRect.left - (idx*m_tInfo.iCX), m_tRect.top
				, m_tInfo.iCX, m_tInfo.iCY
				, hMemDC
				, m_tInfo.iCX * (coin_cnt % 10), 0
				, m_tInfo.iCX, m_tInfo.iCY
				, RGB(0, 255, 0));
			coin_cnt /= 10;
			idx++;
		}


	}
}

void CCounter::Release()
{
}

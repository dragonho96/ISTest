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
	HDC hMemDC;
	int idx = 0;
	int stair_cnt = 0;
	//int coin_cnt = 0;
	if (!CObjMgr::Get_Instance()->PlayerEmpty())
		stair_cnt = static_cast<CPlayer*>(CObjMgr::Get_Instance()->Get_Player())->Get_StairCnt();
	int Ccnt = num_of_digit(stair_cnt);
	
	if (!lstrcmp(m_pFrameKey, L"StairCnt"))
	{
		hMemDC = CBmpMgr::Get_Instance()->Find_Image(L"StairCnt");
		if (stair_cnt == 0) {
			GdiTransparentBlt(_DC
				, m_tRect.left - (idx*m_tInfo.iCX) + (Ccnt * (m_tInfo.iCX >> 1)), m_tRect.top
				, m_tInfo.iCX, m_tInfo.iCY
				, hMemDC
				, 0, 0
				, m_tInfo.iCX, m_tInfo.iCY
				, RGB(255, 255, 255));
		}
		else {
			while (stair_cnt > 0) {
				GdiTransparentBlt(_DC
					, m_tRect.left - (idx*m_tInfo.iCX) + (Ccnt * (m_tInfo.iCX >> 1)), m_tRect.top
					, m_tInfo.iCX, m_tInfo.iCY
					, hMemDC
					, m_tInfo.iCX * (stair_cnt % 10), 0
					, m_tInfo.iCX, m_tInfo.iCY
					, RGB(255, 255, 255));
				stair_cnt /= 10;
				idx++;
			}
		}
		


	}
	idx = 0;
	//Ccnt = num_of_digit(coin_cnt);
	/*if (!lstrcmp(m_pFrameKey, L"CoinCnt"))
	{
		 hMemDC = CBmpMgr::Get_Instance()->Find_Image(L"CoinCnt");

		while (coin_cnt > 0) {
			GdiTransparentBlt(_DC
				, m_tRect.left - (idx*m_tInfo.iCX), m_tRect.top
				, m_tInfo.iCX, m_tInfo.iCY
				, hMemDC
				, m_tInfo.iCX * (coin_cnt % 10), 0
				, m_tInfo.iCX, m_tInfo.iCY
				, RGB(255, 255, 255));
			coin_cnt /= 10;
			idx++;
		}
	}*/
}

void CCounter::Release()
{
}

int CCounter::num_of_digit(int _num)
{
	if (_num == 0) {
		return 0;
	}
	while (_num != 0)
	{
		return 1 + num_of_digit(_num / 10);
	}
	return 0;
}

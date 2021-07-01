#include "stdafx.h"
#include "Counter.h"
#include "SceneMgr.h"
#include "ObjMgr.h"
#include "Player.h"
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
	if (!lstrcmp(m_pFrameKey, L"StairCnt"))
	{
		//int stair_cnt = static_cast<CPlayer*>(CObjMgr::Get_Instance()->Get_Player())->Get_StairCnt();

		//while (stair_cnt > 0) {

		//}


	}
}

void CCounter::Release()
{
}

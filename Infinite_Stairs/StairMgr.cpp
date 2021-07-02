#include "stdafx.h"
#include "StairMgr.h"
#include "Stair.h"
#include "ObjMgr.h"
#include "Coin.h"

CStairMgr* CStairMgr::m_pInstance = nullptr;

CStairMgr::CStairMgr()
	: m_bLeft(true), m_bPrevLeft(true), m_iRepeat(0), 
	m_iProbability(1), m_iCoinProbability(2)
{
}


CStairMgr::~CStairMgr()
{
}

void CStairMgr::Initialize()
{
	// 처음 3개 계단
	//dd
	CObj* pFirstStair;
	for (int i = 0; i < 3; ++i)
	{
		pFirstStair = new CStair(INFO(STAIR_INITPOS_X - ((i + 1) * STAIR_CX), STAIR_INITPOS_Y - (i * STAIR_CY), STAIR_CX, STAIR_CY));
		pFirstStair->Initialize();
		m_dequeStair.emplace_back(pFirstStair);
		CObjMgr::Get_Instance()->Add_Object(pFirstStair, OBJID::STAIR);
	}

	for (int i = 0; i < 20; ++i)
	{
		Add_Stair();
	}
}

void CStairMgr::Add_Stair()
{
	int iRand = rand() % 10;
	if (iRand <= m_iProbability)
	{
		m_bLeft = !m_bLeft;
		m_iRepeat = 0;
	}
	else
	{
		if (m_bLeft == m_bPrevLeft)
		{
			++m_iRepeat;
			if (m_iRepeat > REPEAT_MAX)
			{
				m_bLeft = !m_bLeft;
				m_iRepeat = 0;
			}
		}
	}

	CObj* pLastStair = m_dequeStair.back();
	INFO tPrevInfo = pLastStair->Get_Info();

	if (tPrevInfo.fX < 400)
		m_bLeft = false;
	else if (tPrevInfo.fX > BACKGROUND_SKY_CX - 400)
		m_bLeft = true;

	INFO tInfo = {};

	if (m_bLeft)
		tInfo = INFO(tPrevInfo.fX - tPrevInfo.iCX, tPrevInfo.fY - tPrevInfo.iCY, STAIR_CX, STAIR_CY);
	else
		tInfo = INFO(tPrevInfo.fX + tPrevInfo.iCX, tPrevInfo.fY - tPrevInfo.iCY, STAIR_CX, STAIR_CY);

	CObj* pStair = new CStair(tInfo);
	pStair->Initialize();
	m_dequeStair.emplace_back(pStair);
	CObjMgr::Get_Instance()->Add_Object(pStair, OBJID::STAIR);
	
	m_bPrevLeft = m_bLeft;

	// 랜덤으로 코인 생성
	iRand = rand() % 10;
	if (iRand <= m_iCoinProbability)
	{
		CObj* pCoin = new CCoin(INFO(tInfo.fX, tInfo.fY - (tInfo.iCY / 2 + COIN_CY / 2 + 5), COIN_CX, COIN_CY));
		pCoin->Initialize();
		CObjMgr::Get_Instance()->Add_Object(pCoin, OBJID::COIN);
	}
}

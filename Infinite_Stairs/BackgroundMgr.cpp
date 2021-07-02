#include "stdafx.h"
#include "BackgroundMgr.h"
#include "Background.h"
#include "ObjMgr.h"
#include "KeyMgr.h"
#include "ScrollMgr.h"
#include "Player.h"

CBackgroundMgr* CBackgroundMgr::m_pInstance = nullptr;

CBackgroundMgr::CBackgroundMgr()
	: m_iScrollFactor(10)
{
}


CBackgroundMgr::~CBackgroundMgr()
{
}

void CBackgroundMgr::Initialize()
{
	CObj* pSkyBottom = new CBackground(INFO(BACKGROUND_SKY_CX / 2, WINCY - BACKGROUND_SKY_CY / 2,
		BACKGROUND_SKY_CX, BACKGROUND_SKY_CY));
	pSkyBottom->Initialize();
	static_cast<CBackground*>(pSkyBottom)->Set_FrameKey(L"Background_Sky");
	CObjMgr::Get_Instance()->Add_Object(pSkyBottom, OBJID::BACKGROUND);
	m_dequeBackground.emplace_back(pSkyBottom);

	CObj* pSkyTop = new CBackground(INFO(BACKGROUND_SKY_CX / 2, pSkyBottom->Get_Rect().top - BACKGROUND_SKY_CY / 2,
		BACKGROUND_SKY_CX, BACKGROUND_SKY_CY));
	pSkyTop->Initialize();
	static_cast<CBackground*>(pSkyTop)->Set_FrameKey(L"Background_Sky");
	CObjMgr::Get_Instance()->Add_Object(pSkyTop, OBJID::BACKGROUND);
	m_dequeBackground.emplace_back(pSkyTop);

	CObj* pStreet = new CBackground(INFO(BACKGROUND_STREET_CX / 2, WINCY - BACKGROUND_STREET_CY / 2,
		BACKGROUND_STREET_CX, BACKGROUND_STREET_CY));
	pStreet->Initialize();
	static_cast<CBackground*>(pStreet)->Set_FrameKey(L"Background_Street");
	CObjMgr::Get_Instance()->Add_Object(pStreet, OBJID::BACKGROUND);
}

void CBackgroundMgr::Update()
{
	// 디버깅용
	if (CKeyMgr::Get_Instance()->Key_Pressing(VK_UP))
	{
		CScrollMgr::Get_Instance()->Set_ScrollY(50.f);
	}
	else if (CKeyMgr::Get_Instance()->Key_Pressing(VK_DOWN))
	{
		CScrollMgr::Get_Instance()->Set_ScrollY(-50.f);
	}

	// 무한 스크롤
	if (m_dequeBackground.front()->Get_Rect().top + CScrollMgr::Get_Instance()->Get_ScrollY() / m_iScrollFactor > WINCY)
	{
		m_dequeBackground.front()->Set_Pos(BACKGROUND_SKY_CX / 2, m_dequeBackground.back()->Get_Rect().top - BACKGROUND_SKY_CY / 2);
		m_dequeBackground.front()->Update_Rect();
		m_dequeBackground.emplace_back(m_dequeBackground.front());
		m_dequeBackground.pop_front();
	}
}



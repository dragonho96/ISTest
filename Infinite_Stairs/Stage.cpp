#include "stdafx.h"
#include "Stage.h"
#include "ObjMgr.h"
#include "StairMgr.h"
#include "Player.h"
#include "Gauge.h"
#include "Counter.h"
#include "BmpMgr.h"
#include "BackgroundMgr.h"
#include "ScrollMgr.h"

CStage::CStage()
{
}


CStage::~CStage()
{
	Release();
}

void CStage::Initialize()
{
	//CStairMgr::Get_Instance()->Initialize();
	CObj* pObj = new CPlayer;
	pObj->Initialize();
	CObjMgr::Get_Instance()->Add_Object(pObj, OBJID::PLAYER);

	CObjMgr::Get_Instance()->Add_Object(CAbstractFactory<CCounter>::Create(200, 50, 55, 80, L"StairCnt"), OBJID::STAGEUI);
	CObjMgr::Get_Instance()->Add_Object(CAbstractFactory<CGauge>::Create(200, 220, 200, 50, L"Gauge"), OBJID::STAGEUI);
	CBmpMgr::Get_Instance()->Insert_Bmp(L"../Sprites/GaryNum.bmp", L"StairCnt");
	CBmpMgr::Get_Instance()->Insert_Bmp(L"../Sprites/YellowNum.bmp", L"CoinCnt");
	CBmpMgr::Get_Instance()->Insert_Bmp(L"../Sprites/GaugeBackGround.bmp", L"GaugeBackGround");
	CBmpMgr::Get_Instance()->Insert_Bmp(L"../Sprites/Gauge.bmp", L"Gauge");


	CStairMgr::Get_Instance()->Initialize();
	CBackgroundMgr::Get_Instance()->Initialize();
	CScrollMgr::Get_Instance()->Set_ScrollX(-(STAIR_INITPOS_X - (WINCX / 2)));
}

void CStage::Update()
{
	CObjMgr::Get_Instance()->Update();
	CBackgroundMgr::Get_Instance()->Update();
}

void CStage::Late_Update()
{
	CObjMgr::Get_Instance()->Late_Update();

}

void CStage::Render(HDC _DC)
{
	CObjMgr::Get_Instance()->Render(_DC);

}

void CStage::Release()
{
}

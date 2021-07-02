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


	CObjMgr::Get_Instance()->Add_Object(CAbstractFactory<CCounter>::Create(225, 150, 55, 80, L"StairCnt"), OBJID::STAGEUI);
	CObjMgr::Get_Instance()->Add_Object(CAbstractFactory<CGauge>::Create(225, 50, 380, 50, L"Gauge"), OBJID::GAUGE);
	CBmpMgr::Get_Instance()->Insert_Bmp(L"../Sprites/GaryNum.bmp", L"StairCnt");
	CBmpMgr::Get_Instance()->Insert_Bmp(L"../Sprites/YellowNum.bmp", L"CoinCnt");
	CBmpMgr::Get_Instance()->Insert_Bmp(L"../Sprites/GaugeBackGround.bmp", L"GaugeBackGround");
	CBmpMgr::Get_Instance()->Insert_Bmp(L"../Sprites/Gauge.bmp", L"Gauge");



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
	CObjMgr::Get_Instance()->Delete_ID(OBJID::STAGEUI);
	CObjMgr::Get_Instance()->Delete_ID(OBJID::GAUGE);
}

void CStage::Re_Start()
{
	CObj* pObj = new CPlayer;
	pObj->Initialize();
	CObjMgr::Get_Instance()->Add_Object(pObj, OBJID::PLAYER);

	CStairMgr::Get_Instance()->Initialize();
	CBackgroundMgr::Get_Instance()->Initialize();
	CScrollMgr::Get_Instance()->Set_ScrollFix(-(STAIR_INITPOS_X - (WINCX / 2)),0);

}

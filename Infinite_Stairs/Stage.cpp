#include "stdafx.h"
#include "Stage.h"
#include "ObjMgr.h"
#include "StairMgr.h"
#include "Player.h"
#include "Gauge.h"
#include "Counter.h"
CStage::CStage()
{
}


CStage::~CStage()
{
	Release();
}

void CStage::Initialize()
{
	CStairMgr::Get_Instance()->Initialize();
	CObj* pObj = new CPlayer;
	pObj->Initialize();
	CObjMgr::Get_Instance()->Add_Object(pObj, OBJID::PLAYER);

	CObjMgr::Get_Instance()->Add_Object(CAbstractFactory<CCounter>::Create(200, 300, 50, 50, L"StairNum"), OBJID::STAGEUI);
	CObjMgr::Get_Instance()->Add_Object(CAbstractFactory<CGauge>::Create(200, 220, 200, 50, L"Gauge"), OBJID::STAGEUI);
}

void CStage::Update()
{
	CObjMgr::Get_Instance()->Update();

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

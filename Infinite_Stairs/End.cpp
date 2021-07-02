#include "stdafx.h"
#include "End.h"
#include "ObjMgr.h"
#include "SceneMgr.h"
#include "StairMgr.h"
#include "Counter.h"
#include "MyButton.h"
#include "Stage.h"

CEnd::CEnd()
{
}


CEnd::~CEnd()
{
	Release();
}

void CEnd::Initialize()
{
	//gameover ui만 추가하면 끘

	CObjMgr::Get_Instance()->Add_Object(CAbstractFactory<CCounter>::Create(200, 50, 55, 80, L"StairCntMax"), OBJID::OVERUI);
	CObjMgr::Get_Instance()->Add_Object(CAbstractFactory<CMyButton>::Create(400, 550, 80, 80, L"StartButton"), OBJID::OVERUI);

}

void CEnd::Update()
{
	CObjMgr::Get_Instance()->Update();

}

void CEnd::Late_Update()
{
	CObjMgr::Get_Instance()->Late_Update();

}

void CEnd::Render(HDC _DC)
{
	CObjMgr::Get_Instance()->Render(_DC);

}

void CEnd::Release()
{
	CObjMgr::Get_Instance()->Delete_ID(OBJID::OVERUI);
	CObjMgr::Get_Instance()->Delete_ID(OBJID::STAIR);
	CObjMgr::Get_Instance()->Delete_ID(OBJID::BACKGROUND);
	CObjMgr::Get_Instance()->Delete_ID(OBJID::COIN);
	CStairMgr::Get_Instance()->Destroy_Instance();
	static_cast<CStage*>(CSceneMgr::Get_Instance()->Get_Scene())->Re_Start();
}

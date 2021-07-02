#include "stdafx.h"
#include "End.h"
#include "ObjMgr.h"
#include "SceneMgr.h"
#include "StairMgr.h"
#include "Counter.h"
#include "MyButton.h"
#include "Stage.h"
#include "BmpMgr.h"
#include "Text.h"
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
	CBmpMgr::Get_Instance()->Insert_Bmp(L"../Sprites/OverBack.bmp", L"OverBack");
	CBmpMgr::Get_Instance()->Insert_Bmp(L"../Sprites/GameOver.bmp", L"GameOver");
	CBmpMgr::Get_Instance()->Insert_Bmp(L"../Sprites/Score.bmp", L"Score");
	CBmpMgr::Get_Instance()->Insert_Bmp(L"../Sprites/Best.bmp", L"Best");

	CObjMgr::Get_Instance()->Add_Object(CAbstractFactory<CMyButton>::Create(450, 650, 80, 80, L"StartButton"), OBJID::OVERUI);
	CObjMgr::Get_Instance()->Add_Object(CAbstractFactory<CText>::Create(250, 400 , 370, 370, L"OverBack"), OBJID::OVERUI);
	CObjMgr::Get_Instance()->Add_Object(CAbstractFactory<CText>::Create(250, 100, 350, 100, L"GameOver"), OBJID::OVERUI);
	CObjMgr::Get_Instance()->Add_Object(CAbstractFactory<CText>::Create(250, 350, 150, 100, L"Best"), OBJID::OVERUI);
	CObjMgr::Get_Instance()->Add_Object(CAbstractFactory<CCounter>::Create(225, 500, 55, 80, L"StairCntMax"), OBJID::OVERUI);
	//CObjMgr::Get_Instance()->Add_Object(CAbstractFactory<CText>::Create(225, 100, 150, 100, L"Score"), OBJID::OVERUI);


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

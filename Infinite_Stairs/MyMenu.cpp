#include "stdafx.h"
#include "MyMenu.h"
#include "ObjMgr.h"
#include "Title.h"
#include "MyButton.h"
#include "BmpMgr.h"
#include "Player.h"
#include "StairMgr.h"
#include "BackgroundMgr.h"
#include "ScrollMgr.h"
CMyMenu::CMyMenu()
{
}


CMyMenu::~CMyMenu()
{
	Release();
}

void CMyMenu::Initialize()
{
	//UI Ãß°¡
	//TITLE , START BUTTON
	CObjMgr::Get_Instance()->Add_Object(CAbstractFactory<CTitle>::Create(225, 150, 400, 300, L"Title"), OBJID::MENUUI);
	CObjMgr::Get_Instance()->Add_Object(CAbstractFactory<CMyButton>::Create(400, 550, 80, 80, L"StartButton"), OBJID::MENUUI);
	CBmpMgr::Get_Instance()->Insert_Bmp(L"../Sprites/Title.bmp", L"Title");
	CBmpMgr::Get_Instance()->Insert_Bmp(L"../Sprites/StartButton.bmp", L"StartButton");

	CObj* pObj = new CPlayer;
	pObj->Initialize();
	CObjMgr::Get_Instance()->Add_Object(pObj, OBJID::PLAYER);

	CStairMgr::Get_Instance()->Initialize();
	CBackgroundMgr::Get_Instance()->Initialize();
	CScrollMgr::Get_Instance()->Set_ScrollX(-(STAIR_INITPOS_X - (WINCX / 2)));

}

void CMyMenu::Update()
{
	//CObjMgr::Get_Instance()->Update();
	for (auto & iter : CObjMgr::Get_Instance()->Get_MUI()) {
		iter->Update();
	}
	
}

void CMyMenu::Late_Update()
{
	//CObjMgr::Get_Instance()->Late_Update();
	for (auto & iter : CObjMgr::Get_Instance()->Get_MUI()) {
		iter->Late_Update();
	}

}

void CMyMenu::Render(HDC _DC)
{
	CObjMgr::Get_Instance()->Render(_DC);

}

void CMyMenu::Release()
{
	CObjMgr::Get_Instance()->Delete_ID(OBJID::MENUUI);
}

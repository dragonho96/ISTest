#include "stdafx.h"
#include "MyMenu.h"
#include "ObjMgr.h"
#include "Title.h"
#include "MyButton.h"
#include "BmpMgr.h"
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
	CObjMgr::Get_Instance()->Add_Object(CAbstractFactory<CTitle>::Create(250, 250, 100, 100, L"Title"), OBJID::MENUUI);
	CObjMgr::Get_Instance()->Add_Object(CAbstractFactory<CMyButton>::Create(400, 500, 150, 150, L"Start"), OBJID::MENUUI);
	CBmpMgr::Get_Instance()->Insert_Bmp(L"../Sprites/Title.bmp", L"Title");
	CBmpMgr::Get_Instance()->Insert_Bmp(L"../Sprites/StartButton.bmp", L"StartButton");

}

void CMyMenu::Update()
{
	CObjMgr::Get_Instance()->Update();

}

void CMyMenu::Late_Update()
{
	CObjMgr::Get_Instance()->Late_Update();

}

void CMyMenu::Render(HDC _DC)
{
	CObjMgr::Get_Instance()->Render(_DC);

}

void CMyMenu::Release()
{
	CObjMgr::Get_Instance()->Delete_ID(OBJID::MENUUI);
}

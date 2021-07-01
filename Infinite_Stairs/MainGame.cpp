#include "stdafx.h"
#include "MainGame.h"
#include "ObjMgr.h"
#include "StairMgr.h"
#include "Player.h"
#include "SceneMgr.h"
CMainGame::CMainGame()
{
}


CMainGame::~CMainGame()
{
	Release();
}

void CMainGame::Initialize()
{
	CObj* pObj = new CPlayer;
	pObj->Initialize();
	CObjMgr::Get_Instance()->Add_Object(pObj, OBJID::PLAYER);

	m_hDC = GetDC(g_hWnd);
	CStairMgr::Get_Instance()->Initialize();
}

void CMainGame::Update()
{
	CObjMgr::Get_Instance()->Update();
	CSceneMgr::Get_Instance()->Update();
}

void CMainGame::Late_Update()
{
	CObjMgr::Get_Instance()->Late_Update();
	CSceneMgr::Get_Instance()->Late_Update();
}

void CMainGame::Render()
{
	Rectangle(m_hDC, 0, 0, WINCX, WINCY);
	
	CObjMgr::Get_Instance()->Render(m_hDC);
	CSceneMgr::Get_Instance()->Render(m_hDC);
}

void CMainGame::Release()
{
	ReleaseDC(g_hWnd, m_hDC);
	CStairMgr::Destroy_Instance();
	CObjMgr::Destroy_Instance();
}

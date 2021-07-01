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

	m_hDC = GetDC(g_hWnd);
	CSceneMgr::Get_Instance()->Scene_Change(CSceneMgr::MENU);
}

void CMainGame::Update()
{
	CSceneMgr::Get_Instance()->Update();
}

void CMainGame::Late_Update()
{
	CSceneMgr::Get_Instance()->Late_Update();
}

void CMainGame::Render()
{
	Rectangle(m_hDC, 0, 0, WINCX, WINCY);

	CSceneMgr::Get_Instance()->Render(m_hDC);
}

void CMainGame::Release()
{
	ReleaseDC(g_hWnd, m_hDC);
	CStairMgr::Destroy_Instance();
	CObjMgr::Destroy_Instance();
	CSceneMgr::Destroy_Instance();
}

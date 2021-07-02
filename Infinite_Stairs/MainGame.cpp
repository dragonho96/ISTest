#include "stdafx.h"
#include "MainGame.h"
#include "ObjMgr.h"
#include "StairMgr.h"
#include "Player.h"
#include "SceneMgr.h"
#include "BmpMgr.h"
#include "CollisionMgr.h"

CMainGame::CMainGame()
{
}


CMainGame::~CMainGame()
{
	Release();
}

void CMainGame::Initialize()
{
	CBmpMgr::Get_Instance()->Insert_Bmp(L"../Sprites/Coin.bmp", L"Coin");
	CBmpMgr::Get_Instance()->Insert_Bmp(L"../Sprites/Stair.bmp", L"Stair");
	CBmpMgr::Get_Instance()->Insert_Bmp(L"../Sprites/Back.bmp", L"Back");
	CBmpMgr::Get_Instance()->Insert_Bmp(L"../Sprites/BackBuffer.bmp", L"BackBuffer");
	CBmpMgr::Get_Instance()->Insert_Bmp(L"../Sprites/Background_Street.bmp", L"Background_Street");
	CBmpMgr::Get_Instance()->Insert_Bmp(L"../Sprites/Background_Sky.bmp", L"Background_Sky");

	m_hDC = GetDC(g_hWnd);
	CSceneMgr::Get_Instance()->Scene_Change(CSceneMgr::MENU);
	//stage에 있는 obj를 menu로 옮기고 stage일때만 움직이게 하면 될거같은데?
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
	//Rectangle(m_hDC, 0, 0, WINCX, WINCY);

	HDC hBack = CBmpMgr::Get_Instance()->Find_Image(L"Back");
	HDC hBackBuffer = CBmpMgr::Get_Instance()->Find_Image(L"BackBuffer");

	BitBlt(hBack, 0, 0, WINCX, WINCY, hBackBuffer, 0, 0, SRCCOPY);

	//CSceneMgr::Get_Instance()->Render(hBack);
	CSceneMgr::Get_Instance()->Render(hBack);
	BitBlt(m_hDC, 0, 0, WINCX, WINCY, hBack, 0, 0, SRCCOPY);

	//CObjMgr::Get_Instance()->Render(m_hDC);
}

void CMainGame::Release()
{
	ReleaseDC(g_hWnd, m_hDC);
	CStairMgr::Destroy_Instance();
	CObjMgr::Destroy_Instance();
	CSceneMgr::Destroy_Instance();
	CBmpMgr::Destroy_Instance();
}

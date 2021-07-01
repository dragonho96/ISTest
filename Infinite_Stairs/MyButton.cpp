#include "stdafx.h"
#include "MyButton.h"
#include "KeyMgr.h"
#include "SceneMgr.h"
CMyButton::CMyButton()
{
}


CMyButton::~CMyButton()
{
	Release();

}

void CMyButton::Initialize()
{
	m_tInfo.iCX = 150;
	m_tInfo.iCY = 150;

}

int CMyButton::Update()
{
	if (m_bDead)
		return OBJ_DEAD;
	POINT	pt = {};
	GetCursorPos(&pt);
	ScreenToClient(g_hWnd, &pt);

	if (PtInRect(&m_tRect, pt))
	{
		if (CKeyMgr::Get_Instance()->Key_Down(VK_LBUTTON))
		{
			if (!lstrcmp(m_pFrameKey, L"Start"))
			{
				CSceneMgr::Get_Instance()->Scene_Change(CSceneMgr::STAGE);
				return;
			}
			if (!lstrcmp(m_pFrameKey, L"Up")) {

			}
			if (!lstrcmp(m_pFrameKey, L"Turn")) {

			}
			
		}
	}
	Update_Rect();
	return OBJ_NOEVENT;
}

void CMyButton::Late_Update()
{
}

void CMyButton::Render(HDC _DC)
{
}

void CMyButton::Release()
{
}

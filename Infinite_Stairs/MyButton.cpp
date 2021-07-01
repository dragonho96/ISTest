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

}

int CMyButton::Update()
{
	if (m_bDead)
		return OBJ_DEAD;

	Update_Rect();
	return OBJ_NOEVENT;
}

void CMyButton::Late_Update()
{
	POINT	pt = {};
	GetCursorPos(&pt);
	ScreenToClient(g_hWnd, &pt);

	if (PtInRect(&m_tRect, pt))
	{
		if (CKeyMgr::Get_Instance()->Key_Up(VK_LBUTTON))
		{
			if (!lstrcmp(m_pFrameKey, L"Start"))
			{
				CSceneMgr::Get_Instance()->Scene_Change(CSceneMgr::STAGE);
			}
		}
	}
}

void CMyButton::Render(HDC _DC)
{
	Rectangle(_DC, m_tRect.left, m_tRect.top, m_tRect.bottom, m_tRect.right);
}

void CMyButton::Release()
{
}

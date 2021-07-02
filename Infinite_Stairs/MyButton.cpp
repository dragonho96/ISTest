#include "stdafx.h"
#include "MyButton.h"
#include "KeyMgr.h"
#include "SceneMgr.h"
#include "BmpMgr.h"
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
			if (!lstrcmp(m_pFrameKey, L"StartButton"))
			{
				CSceneMgr::Get_Instance()->Scene_Change(CSceneMgr::STAGE);
			}
		}
	}
}

void CMyButton::Render(HDC _DC)
{
	HDC hMemDC = CBmpMgr::Get_Instance()->Find_Image(L"StartButton");
	//Rectangle(_DC, m_tRect.left, m_tRect.top, m_tRect.bottom, m_tRect.right);
	GdiTransparentBlt(_DC
		, m_tRect.left, m_tRect.top
		, m_tInfo.iCX, m_tInfo.iCY
		, hMemDC
		, 0, 0
		, 140, 116
		, RGB(0, 255, 0));
}

void CMyButton::Release()
{
}

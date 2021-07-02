#include "stdafx.h"
#include "Title.h"
#include "BmpMgr.h"

CTitle::CTitle()
{
}


CTitle::~CTitle()
{
	Release();
}

void CTitle::Initialize()
{

}

int CTitle::Update()
{

	if (m_bDead)
		return OBJ_DEAD;

	Update_Rect();
	return OBJ_NOEVENT;
}

void CTitle::Late_Update()
{
	//demp
}

void CTitle::Render(HDC _DC)
{
	HDC hMemDC = CBmpMgr::Get_Instance()->Find_Image(L"Title");
	//Rectangle(_DC, m_tRect.left, m_tRect.top, m_tRect.bottom, m_tRect.right);
	GdiTransparentBlt(_DC
		, m_tRect.left, m_tRect.top
		, m_tInfo.iCX, m_tInfo.iCY
		, hMemDC
		, 0, 0
		, 424,206
		, RGB(0, 255, 0));
}

void CTitle::Release()
{
}

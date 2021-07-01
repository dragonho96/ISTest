#include "stdafx.h"
#include "Title.h"


CTitle::CTitle()
{
}


CTitle::~CTitle()
{
	Release();
}

void CTitle::Initialize()
{
	m_tInfo.iCX = 150;
	m_tInfo.iCY = 150;


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
}

void CTitle::Render(HDC _DC)
{
	
}

void CTitle::Release()
{
}

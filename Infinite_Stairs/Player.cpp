#include "stdafx.h"
#include "Player.h"
#include "KeyMgr.h"
#include "ScrollMgr.h"
#include "ObjMgr.h"

CPlayer::CPlayer()
	: m_bStretch(false), m_iStairCnt(0), m_fStairCX(0.f), m_fStairCY(0.f)
{
}


CPlayer::~CPlayer()
{
}


void CPlayer::Initialize()
{
	m_tInfo.fX = STAIR_INITPOS_X - STAIR_CX + 82;
	m_tInfo.fY = STAIR_INITPOS_Y - STAIR_CY;

	m_tInfo.iCX = 143;
	m_tInfo.iCY = 259;
}

int CPlayer::Update()
{
	if (m_bDead)
		return OBJ_DEAD;

	//Update_Frame();
	Update_Rect();
	Key_Check();
	Move_Scroll();
	return OBJ_NOEVENT;
}

void CPlayer::Late_Update()
{
}

void CPlayer::Render(HDC _DC)
{
	int iScrollX = (int)CScrollMgr::Get_Instance()->Get_ScrollX();
	int iScrollY = (int)CScrollMgr::Get_Instance()->Get_ScrollY();

	Rectangle(_DC, m_tRect.left + iScrollX, m_tRect.top + iScrollY, m_tRect.right + iScrollX, m_tRect.bottom + iScrollY);
}

void CPlayer::Release()
{
	int i = 0;
}

void CPlayer::Update_Rect()
{
	/*m_tRect.left = (LONG)(m_tInfo.fX - (m_tInfo.iCX >> 1));
	m_tRect.top = (LONG)(m_tInfo.fY - m_tInfo.iCY);
	m_tRect.right = (LONG)(m_tInfo.fX + (m_tInfo.iCX >> 1));
	m_tRect.bottom = (LONG)m_tInfo.fY;*/

	m_tRect.left = (LONG)(m_tInfo.fX - (m_tInfo.iCX >> 1));
	m_tRect.top = (LONG)(m_tInfo.fY - (m_tInfo.iCY >> 1));
	m_tRect.right = (LONG)(m_tInfo.fX + (m_tInfo.iCX >> 1));
	m_tRect.bottom = (LONG)(m_tInfo.fY + (m_tInfo.iCY >> 1));
}

void CPlayer::Update_Frame()
{
	if (m_tFrame.dwDelayTime + m_tFrame.dwTime < GetTickCount())
	{
		++m_tFrame.iStartX;
		m_tFrame.dwTime = GetTickCount();

		if (m_tFrame.iStartX >= m_tFrame.iEndX)
			m_tFrame.iStartX = 0;
	}
}

void CPlayer::Key_Check()
{
	if (CKeyMgr::Get_Instance()->Key_Down(VK_LEFT))
	{
		m_bStretch = !m_bStretch;
		Move_Player();
	}
	else if (CKeyMgr::Get_Instance()->Key_Down(VK_RIGHT))
	{
		Move_Player();
	}
}

void CPlayer::Move_Player()
{
	if (m_bStretch)
	{
		m_tInfo.fX += STAIR_CX;
		m_tInfo.fY -= STAIR_CY;
		++m_iStairCnt;
		//CScrollMgr::Get_Instance()->Set_ScrollX(-STAIR_CX);
		//CScrollMgr::Get_Instance()->Set_ScrollY(STAIR_CY);
	}
	else
	{
		m_tInfo.fX -= STAIR_CX;
		m_tInfo.fY -= STAIR_CY;
		++m_iStairCnt;
		//CScrollMgr::Get_Instance()->Set_ScrollX(+STAIR_CX);
		//CScrollMgr::Get_Instance()->Set_ScrollY(STAIR_CY);
	}
	m_fStairCX += STAIR_CX;
	m_fStairCY += STAIR_CY;
}

void CPlayer::Move_Scroll()
{
	if (m_fStairCX > 0)
	{
		if (m_bStretch)
		{
			CScrollMgr::Get_Instance()->Set_ScrollX(-16.4);
			CScrollMgr::Get_Instance()->Set_ScrollY(9);
		}
		else
		{
			CScrollMgr::Get_Instance()->Set_ScrollX(+16.4);
			CScrollMgr::Get_Instance()->Set_ScrollY(9);
		}
		m_fStairCX -= 16.4f;
		m_fStairCY -= 9.f;
		if (m_fStairCX < 0.f)
			m_fStairCX = 0.f;
	}	
}

void CPlayer::Check_Dead(list<CObj*>& _Stair)
{	
	m_bDead = true;
}

#include "stdafx.h"
#include "Player.h"
#include "KeyMgr.h"
#include "ScrollMgr.h"
#include "ObjMgr.h"

CPlayer::CPlayer()
	: m_bStretch(false)
{
}


CPlayer::~CPlayer()
{
}


void CPlayer::Initialize()
{
	m_tInfo.fX = WINCX / 2;
	m_tInfo.fY = 585;

	m_tInfo.iCX = 100;
	m_tInfo.iCY = 120;
}

int CPlayer::Update()
{
	if (m_bDead)
		return OBJ_DEAD;

	//Update_Frame();
	Update_Rect();
	Key_Check();

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
	m_tRect.left = (LONG)(m_tInfo.fX - (m_tInfo.iCX >> 1));
	m_tRect.top = (LONG)(m_tInfo.fY - m_tInfo.iCY);
	m_tRect.right = (LONG)(m_tInfo.fX + (m_tInfo.iCX >> 1));
	m_tRect.bottom = (LONG)m_tInfo.fY;
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
	int i = 0;

	if (m_bStretch)
	{
		m_tInfo.fX += STAIR_CX;
		m_tInfo.fY -= STAIR_CY;
		CScrollMgr::Get_Instance()->Set_ScrollX(-STAIR_CX);
		CScrollMgr::Get_Instance()->Set_ScrollY(STAIR_CY);
	}
	else
	{
		m_tInfo.fX -= STAIR_CX;
		m_tInfo.fY -= STAIR_CY;
		CScrollMgr::Get_Instance()->Set_ScrollX(+STAIR_CX);
		CScrollMgr::Get_Instance()->Set_ScrollY(STAIR_CY);
	}
}

void CPlayer::Check_Dead(list<CObj*>& _Stair)
{
	for (auto pStair : _Stair)
	{
		if (m_tRect.bottom == pStair->Get_Rect().top && m_tInfo.fX == pStair->Get_Info().fX)
			return;
	}
	m_bDead = true;
}

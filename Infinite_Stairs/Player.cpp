#include "stdafx.h"
#include "Player.h"
#include "KeyMgr.h"
#include "ScrollMgr.h"
#include "ObjMgr.h"
#include "StairMgr.h"
#include "BmpMgr.h"
#include "Gauge.h"
#include "SceneMgr.h"

int CPlayer::m_iCoin = 0;

CPlayer::CPlayer()
	: m_bStretch(false), m_iStairCnt(0), m_fStairCX(0.f), m_fStairCY(0.f), m_ePreState(END), m_eCurState(END), m_dwDeadTime(GetTickCount()), m_bRightLeg(true)
{
}


CPlayer::~CPlayer()
{
}


void CPlayer::Initialize()
{
	CBmpMgr::Get_Instance()->Insert_Bmp(L"../Sprites/Player2.bmp", L"Player");
	CBmpMgr::Get_Instance()->Insert_Bmp(L"../Sprites/Stretch.bmp", L"Stretch");

	m_tInfo.fX = STAIR_INITPOS_X - STAIR_CX + 82;
	m_tInfo.fY = STAIR_INITPOS_Y - STAIR_CY + 67.5f;

	m_tInfo.iCX = 220;
	m_tInfo.iCY = 259;
	
	m_eCurState = IDLE;

	Check_State();
	Update_Rect();

}

int CPlayer::Update()
{
	if (m_bDead)
	{
		//Update_Frame();
		if (m_dwDeadTime + 1000 < GetTickCount())
		{
			m_tInfo.fY += 15.f;
			if (m_tInfo.fY > WINCY + 200) {
				CObjMgr::Get_Instance()->Set_StairMax(m_iStairCnt);
				CSceneMgr::Get_Instance()->Scene_Change(CSceneMgr::GAMEOVER);
				return OBJ_DEAD;
			}
		}
	}
		Update_Rect();
		Update_Frame();
		Key_Check();
		Check_State();
		Check_Dead();
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

	//Rectangle(_DC, m_tRect.left + iScrollX, m_tRect.top + iScrollY, m_tRect.right + iScrollX, m_tRect.bottom + iScrollY);

	HDC hMemDC = CBmpMgr::Get_Instance()->Find_Image(L"Player");
	HDC hStretchDC = CBmpMgr::Get_Instance()->Find_Image(L"Stretch");

	if (m_bStretch)
	{
		StretchBlt(hStretchDC
			, 0, 0
			, m_tInfo.iCX, m_tInfo.iCY
			, hMemDC
			, m_tFrame.iStartX * m_tInfo.iCX + m_tInfo.iCX, m_tFrame.iStateY * m_tInfo.iCY
			, -m_tInfo.iCX, m_tInfo.iCY
			, SRCCOPY);

		if (m_ePreState == WALK && !(m_tFrame.iStartX % 2))
		{
			GdiTransparentBlt(_DC
				, m_tRect.left + iScrollX - STAIR_CX, m_tRect.top + iScrollY + STAIR_CY
				, m_tInfo.iCX, m_tInfo.iCY
				, hStretchDC
				, 0, 0
				, m_tInfo.iCX, m_tInfo.iCY
				, RGB(0, 255, 0));
		}
		else
		{
			GdiTransparentBlt(_DC
				, m_tRect.left + iScrollX, m_tRect.top + iScrollY
				, m_tInfo.iCX, m_tInfo.iCY
				, hStretchDC
				, 0, 0
				, m_tInfo.iCX, m_tInfo.iCY
				, RGB(0, 255, 0));
		}
	}
	else
	{
		if (m_ePreState == WALK && !(m_tFrame.iStartX % 2))
		{
			GdiTransparentBlt(_DC
				, m_tRect.left + iScrollX + STAIR_CX, m_tRect.top + iScrollY + STAIR_CY
				, m_tInfo.iCX, m_tInfo.iCY
				, hMemDC
				, m_tFrame.iStartX * m_tInfo.iCX, m_tFrame.iStateY * m_tInfo.iCY
				, m_tInfo.iCX, m_tInfo.iCY
				, RGB(0, 255, 0));
		}
		else
		{
			GdiTransparentBlt(_DC
				, m_tRect.left + iScrollX, m_tRect.top + iScrollY
				, m_tInfo.iCX, m_tInfo.iCY
				, hMemDC
				, m_tFrame.iStartX * m_tInfo.iCX, m_tFrame.iStateY * m_tInfo.iCY
				, m_tInfo.iCX, m_tInfo.iCY
				, RGB(0, 255, 0));
		}
	}
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

	m_tRectBottom.left = (LONG)(m_tInfo.fX - (m_tInfo.iCX >> 1));
	m_tRectBottom.top = (LONG)(m_tInfo.fY - 10.f);
	m_tRectBottom.right = (LONG)(m_tInfo.fX + (m_tInfo.iCX >> 1));
	m_tRectBottom.bottom = (LONG)m_tInfo.fY;
	/*m_tRect.left = (LONG)(m_tInfo.fX - (m_tInfo.iCX >> 1));
	m_tRect.top = (LONG)(m_tInfo.fY - (m_tInfo.iCY >> 1));
	m_tRect.right = (LONG)(m_tInfo.fX + (m_tInfo.iCX >> 1));
	m_tRect.bottom = (LONG)(m_tInfo.fY + (m_tInfo.iCY >> 1));*/
}

void CPlayer::Update_Frame()
{
	if (m_tFrame.dwDelayTime + m_tFrame.dwTime < GetTickCount() && !m_bDead)
	{
		++m_tFrame.iStartX;
		m_tFrame.dwTime = GetTickCount();

		if (m_ePreState == WALK)
		{
			if (m_tFrame.iStartX % 2)
			{
				m_bRightLeg = !m_bRightLeg;
				m_eCurState = IDLE;
			}
		}

		if (m_tFrame.iStartX >= m_tFrame.iEndX)
			m_tFrame.iStartX = 0;
	}
}

void CPlayer::Key_Check()
{
	if (CKeyMgr::Get_Instance()->Key_Down(VK_LEFT) && !m_bDead)
	{
		m_bStretch = !m_bStretch;
		Move_Player();
	}
	else if (CKeyMgr::Get_Instance()->Key_Down(VK_RIGHT) && !m_bDead)
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
		m_eCurState = WALK;
	}
	else
	{
		m_tInfo.fX -= STAIR_CX;
		m_tInfo.fY -= STAIR_CY;
		++m_iStairCnt;
		m_eCurState = WALK;
	}
	m_fStairCX += STAIR_CX;
	m_fStairCY += STAIR_CY;
	static_cast<CGauge*>(CObjMgr::Get_Instance()->Get_Gauge().front())->Set_Count(-10);
	CStairMgr::Get_Instance()->Add_Stair();
}

void CPlayer::Move_Scroll()
{
	if (m_fStairCX > 0 && !m_bDead)
	{
		if (m_bStretch)
		{
			CScrollMgr::Get_Instance()->Set_ScrollX(-16.4f);
			CScrollMgr::Get_Instance()->Set_ScrollY(9.f);
		}
		else
		{
			CScrollMgr::Get_Instance()->Set_ScrollX(+16.4f);
			CScrollMgr::Get_Instance()->Set_ScrollY(9.f);
		}
		m_fStairCX -= 16.4f;
		m_fStairCY -= 9.f;
		if (m_fStairCX < 0.f)
			m_fStairCX = 0.f;
	}	
}

void CPlayer::Check_State()
{
	if (m_ePreState != m_eCurState)
	{
		switch (m_eCurState)
		{
		case CPlayer::IDLE:
			m_tFrame.iStartX = 0;
			m_tFrame.iEndX = 1;
			m_tFrame.iStateY = IDLE;
			m_tFrame.dwDelayTime = 200;
			m_tFrame.dwTime = GetTickCount();
			break;
		case CPlayer::WALK:
			if (m_bRightLeg)
				m_tFrame.iStartX = 0;
			else
				m_tFrame.iStartX = 2;
			m_tFrame.iEndX = 4;
			m_tFrame.iStateY = WALK;
			m_tFrame.dwDelayTime = 100;
			m_tFrame.dwTime = GetTickCount();
			break;
		case CPlayer::DEAD:
			m_tFrame.iStartX = 0;
			m_tFrame.iEndX = 1;
			m_tFrame.iStateY = DEAD;
			m_tFrame.dwDelayTime = 200;
			m_tFrame.dwTime = GetTickCount();
			break;
		}

		m_ePreState = m_eCurState;
	}
}

void CPlayer::Check_Dead()
{	
	if (m_iStairCnt > 0 && !m_bDead)
	{
		if (CStairMgr::Get_Instance()->Get_Stair(m_iStairCnt - 1)->Get_Info().fX != m_tInfo.fX)
		{
			--m_iStairCnt;
			m_eCurState = DEAD;
			m_bDead = true;
			m_dwDeadTime = GetTickCount();
		}
	}
}

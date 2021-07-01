#include "stdafx.h"
#include "Coin.h"


CCoin::CCoin()
{
}

CCoin::CCoin(INFO & _tInfo)
	: CObj(_tInfo)
{
}


CCoin::~CCoin()
{
	Release();
}

// dd
void CCoin::Initialize()
{
	Update_Rect();
	m_tFrame.iStartX = 0;
	m_tFrame.iEndX = 5;
	m_tFrame.iStateY = 0;
	m_tFrame.dwDelayTime = 80.f;
	m_tFrame.dwTime = GetTickCount();
}

int CCoin::Update()
{
	if (m_bDead)
		return OBJ_DEAD;




	return OBJ_NOEVENT;
}

void CCoin::Late_Update()
{
}

void CCoin::Render(HDC _DC)
{
	Ellipse(_DC, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);
}

void CCoin::Release()
{
}

void CCoin::Update_Frame()
{
	if (m_tFrame.dwDelayTime + m_tFrame.dwTime < GetTickCount())
	{
		++m_tFrame.iStartX;
		m_tFrame.dwTime = GetTickCount();

		if (m_tFrame.iStartX >= m_tFrame.iEndX)
			m_tFrame.iStartX = 0;
	}
}

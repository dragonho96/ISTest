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

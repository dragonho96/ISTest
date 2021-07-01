#include "stdafx.h"
#include "Gauge.h"


CGauge::CGauge() :count(0)
{
}


CGauge::~CGauge()
{
	Release();

}

void CGauge::Initialize()
{
	m_dwTime = GetTickCount();
	m_dwDelayTime = 200;
}

int CGauge::Update()
{
	if (m_bDead)
		return OBJ_DEAD;
	if (m_dwTime + m_dwDelayTime < GetTickCount()) {
		++count;
	}
	Update_Rect();
	return OBJ_NOEVENT;
}

void CGauge::Late_Update()
{
	if (count == 100) {
		//ÇÃ·¹ÀÌ¾î »ç¸Á ÈÄ ¾À ÀüÈ¯
	}

}

void CGauge::Render(HDC _DC)
{
}

void CGauge::Release()
{
}

#include "stdafx.h"
#include "Counter.h"


CCounter::CCounter()
{
}


CCounter::~CCounter()
{
	Release();

}

void CCounter::Initialize()
{
	m_tInfo.iCX = 150;
	m_tInfo.iCY = 150;

}

int CCounter::Update()
{
	if (m_bDead)
		return OBJ_DEAD;
	//�ö� ��� ���ϰ� ���� �� �������� �Լ� �ʿ�.
	Update_Rect();
	return OBJ_NOEVENT;
}

void CCounter::Late_Update()
{
}

void CCounter::Render(HDC _DC)
{
}

void CCounter::Release()
{
}

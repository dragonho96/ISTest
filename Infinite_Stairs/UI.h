#pragma once
#include "Obj.h"
class CUI :
	public CObj
{
public:
	CUI();
	virtual ~CUI();
public:
	void Set_Size(int _x, int _y) { m_tInfo.iCX = _x; m_tInfo.iCY = _y; }
};


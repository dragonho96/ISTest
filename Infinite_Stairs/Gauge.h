#pragma once


#ifndef __CGAUGE_H__
#define __CGAUGE_H__


#include "UI.h"
class CGauge :
	public CUI
{
public:
	CGauge();
	virtual ~CGauge();

public:
	virtual void Initialize() override;
	virtual int Update() override;
	virtual void Late_Update() override;
	virtual void Render(HDC _DC) override;
	virtual void Release() override;
public:
	void Set_Count(int _cnt);
public:
	int Get_Count() { return count; }
private:
	int count = 50;
};


#endif // !__CGAUGE_H__

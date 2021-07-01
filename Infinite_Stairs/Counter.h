#pragma once

#ifndef __CCOUNT_H__
#define __CCOUNT_H__

#include "UI.h"
class CCounter :
	public CUI
{
public:
	CCounter();
	virtual ~CCounter();

public:
	virtual void Initialize() override;
	virtual int Update() override;
	virtual void Late_Update() override;
	virtual void Render(HDC _DC) override;
	virtual void Release() override;
};


#endif // !__CCOUNT_H__

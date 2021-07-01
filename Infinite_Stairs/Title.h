#pragma once

#ifndef __CTITLE_H__
#define __CTITLE_H__


#include "UI.h"
class CTitle :
	public CUI
{
public:
	CTitle();
	virtual ~CTitle();
public:
	virtual void Initialize() override;
	virtual int Update() override;
	virtual void Late_Update() override;
	virtual void Render(HDC _DC) override;
	virtual void Release() override;
};

#endif //__CTITLE_H__
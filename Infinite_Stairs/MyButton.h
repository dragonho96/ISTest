#pragma once

#ifndef __CMYBUTTON_H__
#define __CMYBUTTON_H__


#include "UI.h"
class CMyButton :
	public CUI
{
public:
	CMyButton();
	virtual ~CMyButton();

public:
	virtual void Initialize() override;
	virtual int Update() override;
	virtual void Late_Update() override;
	virtual void Render(HDC _DC) override;
	virtual void Release() override;
};


#endif // !__CMYBUTTON_H__

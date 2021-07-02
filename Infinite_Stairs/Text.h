#pragma once

#ifndef __CTEXT_H__
#define __CTEXT_H__

#include "UI.h"
class CText :
	public CUI
{
public:
	CText();
	virtual ~CText();

public:
	virtual void Initialize() override;
	virtual int Update() override;
	virtual void Late_Update() override;
	virtual void Render(HDC _DC) override;
	virtual void Release() override;
};


#endif // !__CTEXT_H__

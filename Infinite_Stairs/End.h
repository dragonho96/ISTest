#pragma once

#ifndef __CEND_H__
#define __CEND_H__


#include "Scene.h"
class CEnd :
	public CScene
{
public:
	CEnd();
	virtual ~CEnd();

public:
	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Late_Update() override;
	virtual void Render(HDC _DC) override;
	virtual void Release() override;
};


#endif // !__CEND_H__

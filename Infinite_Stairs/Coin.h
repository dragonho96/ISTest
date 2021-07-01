#pragma once
#ifndef __COIN_H__
#define __COIN_H__

#include "Obj.h"
class CCoin : public CObj
{
public:
	CCoin();
	CCoin(INFO& _tInfo);
	virtual ~CCoin();

	// Inherited via CObj
	virtual void Initialize() override;
	virtual int Update() override;
	virtual void Late_Update() override;
	virtual void Render(HDC _DC) override;
	virtual void Release() override;

	void Update_Frame();
};

#endif // !__COIN_H__

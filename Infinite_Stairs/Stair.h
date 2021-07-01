#pragma once
#ifndef __STAIR_H__
#define __STAIR_H__

#include "Obj.h"
class CStair : public CObj
{
public:
	CStair();
	CStair(INFO& _tInfo);
	virtual ~CStair();

	// Inherited via CObj
	virtual void Initialize() override;
	virtual int Update() override;
	virtual void Late_Update() override;
	virtual void Render(HDC _DC) override;
	virtual void Release() override;


};

#endif // !__STAIR_H__

#pragma once
#ifndef __PLAYER_H__
#define __PLAYER_H__

#include "Obj.h"
class CPlayer :	public CObj
{
public:
	CPlayer();
	virtual ~CPlayer();

public:
	void Update_Rect();
	void Update_Frame();
	void Key_Check();
	void Move_Player();
	void Check_Dead(list<CObj*>& _Stair);

public:
	virtual void Initialize() override;
	virtual int Update() override;
	virtual void Late_Update() override;
	virtual void Render(HDC _DC) override;
	virtual void Release() override;

private:
	bool		m_bStretch;
};

#endif
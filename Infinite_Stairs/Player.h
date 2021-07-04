#pragma once
#ifndef __PLAYER_H__
#define __PLAYER_H__

#include "Obj.h"
class CPlayer :	public CObj
{
	enum STATE {IDLE, WALK, DEAD, END};

public:
	CPlayer();
	virtual ~CPlayer();

public:
	void Update_Rect();
	void Update_Frame();
	void Key_Check();
	void Move_Player();
	void Move_Scroll();
	void Check_State();
	void Check_Dead();

public:
	int Get_StairCnt() { return m_iStairCnt; }
	static int Get_Coin() { return m_iCoin; }
	RECT Get_RectBottom() { return m_tRectBottom; }

public:
	void Set_Coin(int _iCoin) { m_iCoin += _iCoin; }

public:
	virtual void Initialize() override;
	virtual int Update() override;
	virtual void Late_Update() override;
	virtual void Render(HDC _DC) override;
	virtual void Release() override;

private:
	DWORD		m_dwDeadTime;
	STATE		m_ePreState;
	STATE		m_eCurState;

	RECT		m_tRectBottom;

	bool		m_bStretch;
	bool		m_bRightLeg;

	int			m_iCoinCnt;
	int			m_iStairCnt;
	float		m_fStairCX;
	float		m_fStairCY;

	static int			m_iCoin;
};

#endif
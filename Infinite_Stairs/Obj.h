#pragma once
#ifndef __OBJ_H__
#define __OBJ_H__

class CObj
{
public:
	CObj();
	CObj(INFO& _tInfo);
	virtual ~CObj();

	virtual void Initialize() = 0;
	virtual int Update() = 0;
	virtual void Late_Update() = 0;
	virtual void Render(HDC _DC) = 0;
	virtual void Release() = 0;
public:
	void Update_Rect();
	void Set_Pos(int _x, int _y) { m_tInfo.fX = _x; m_tInfo.fY = _y; }
public:
	void Set_FrameKey(const TCHAR* _pKey) { m_pFrameKey = _pKey; }
	void Set_Dead() { m_bDead = OBJ_DEAD; }
public:
	const INFO& Get_Info() const { return m_tInfo; }
	const RECT& Get_Rect() const { return m_tRect; }
	const bool& Get_Dead() const { return m_bDead; }
protected:
	INFO	m_tInfo;
	RECT	m_tRect;
	FRAME	m_tFrame;
	DWORD	m_dwTime;
	DWORD	m_dwDelayTime;


	bool	m_bDead;

	const TCHAR*	m_pFrameKey;
};

#endif // !__OBJ_H__

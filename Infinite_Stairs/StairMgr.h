#pragma once
#ifndef __STAIRMGR_H__
#define __STAIRMGR_H__

class CObj;

class CStairMgr
{
private:
	CStairMgr();
	~CStairMgr();

public:
	void Initialize();
	void Add_Stair();

public:
	CObj* Get_Stair(int _iIdx) { return m_dequeStair[_iIdx]; }
public:
	static CStairMgr* Get_Instance()
	{
		if (!m_pInstance)
			m_pInstance = new CStairMgr();
		return m_pInstance;
	}
	
	static void Destroy_Instance()
	{
		SAFE_DELETE(m_pInstance);
	}

private:
	static CStairMgr*	m_pInstance;

	deque<CObj*>		m_dequeStair;
	int					m_iProbability;				// 0~9
	int					m_iCoinProbability;			// 0~9
	int					m_iRepeat;
	bool				m_bLeft;
	bool				m_bPrevLeft;
};

#endif // !__STAIRMGR_H__

#pragma once
#ifndef __BACKGROUNDMGR_H__
#define __BACKGROUNDMGR_H__
class Background;
class CBackgroundMgr
{
private:
	CBackgroundMgr();
	~CBackgroundMgr();

public:
	void Initialize();
	void Update(); // ������

public:
	int Get_ScrollFactor() { return m_iScrollFactor; }
public:
	static CBackgroundMgr* Get_Instance()
	{
		if (!m_pInstance)
			m_pInstance = new CBackgroundMgr;
		return m_pInstance;
	}

	static void Destroy_Instance()
	{
		SAFE_DELETE(m_pInstance);
	}

private:
	static CBackgroundMgr*	m_pInstance;
	deque<CObj*>			m_dequeBackground;
	int						m_iScrollFactor;
};

#endif // !__BACKGROUNDMGR_H__

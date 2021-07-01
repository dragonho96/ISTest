#pragma once
#ifndef __BACKGROUND_H__
#define __BACKGROUND_H__

#include "Obj.h"
class CBackground : public CObj
{
public:
	enum BACKGROUND {STREET, SKY, END};
public:
	CBackground();
	CBackground(INFO& _tInfo);
	virtual ~CBackground();

	// Inherited via CObj
	virtual void Initialize() override;
	virtual int Update() override;
	virtual void Late_Update() override;
	virtual void Render(HDC _DC) override;
	virtual void Release() override;

	void Set_ID(BACKGROUND _eID);

private:
	BACKGROUND	m_eID;
};

#endif // !__BACKGROUND_H__

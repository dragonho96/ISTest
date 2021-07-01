#pragma once


#ifndef __ABSTRACTFACTORY_H__
#define __ABSTRACTFACTORY_H__

class CObj;
class CUI;
template <typename T>
class CAbstractFactory {
public:
	static CObj* Create() {
		CObj* pObj = new T;
		pObj->Initialize();

		return pObj;
	}

	static CObj* Create(float _x, float _y,int _cx,int _cy, const TCHAR* _frameKey)
	{//ui만들때 쓸 것임.
		CObj* pObj = new T;
		pObj->Initialize();
		pObj->Set_Pos(_x, _y);
		pObj->Set_FrameKey(_frameKey);
		static_cast<CUI*>(pObj)->Set_Size(_cx, _cy);
		return pObj;
	}
	
};

#endif // !__ABSTRACTFACTORY_H__
#pragma once

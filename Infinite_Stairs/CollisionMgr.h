#pragma once

#ifndef __COLLISIONMGR_H__
#define __COLLISIONMGR_H__

class CObj;
class CCollisionMgr
{
public:
	CCollisionMgr();
	~CCollisionMgr();

public:
	static void Collision_Rect(list<CObj*>& _Dst, list<CObj*>& _Src);

	static bool Check_Rect(CObj* _Dst, CObj* _Src, float* _x, float* _y);
};


#endif // !__COLLISIONMGR_H__

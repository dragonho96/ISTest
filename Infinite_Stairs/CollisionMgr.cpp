#include "stdafx.h"
#include "CollisionMgr.h"
#include "Obj.h"


CCollisionMgr::CCollisionMgr()
{
}


CCollisionMgr::~CCollisionMgr()
{
}

// 이 함수 수정한 후 쓰자
void CCollisionMgr::Collision_Rect(list<CObj*>& _Dst, list<CObj*>& _Src)
{
	RECT rc = {};

	for (auto& Dst : _Dst)
	{
		for (auto& Src : _Src)
		{
			if (IntersectRect(&rc, &Dst->Get_Rect(), &Src->Get_Rect()))
			{
				//Dst->Set_Dead();
				//Src->Set_Dead();
			}
		}
	}
}

bool CCollisionMgr::Check_Rect(CObj* _Dst, CObj* _Src, float* _x, float* _y)
{
	float	fCenterDisX = abs(_Dst->Get_Info().fX - _Src->Get_Info().fX);
	float	fCenterDisY = abs(_Dst->Get_Info().fY - _Src->Get_Info().fY);

	float	fRSumX = (float)((_Dst->Get_Info().iCX + _Src->Get_Info().iCX) >> 1);
	float	fRSumY = (float)((_Dst->Get_Info().iCY + _Src->Get_Info().iCY) >> 1);

	if (fCenterDisX < fRSumX && fCenterDisY < fRSumY)
	{
		*_x = fRSumX - fCenterDisX;
		*_y = fRSumY - fCenterDisY;

		return true;
	}
	return false;
}

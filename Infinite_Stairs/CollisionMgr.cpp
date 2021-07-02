#include "stdafx.h"
#include "CollisionMgr.h"
#include "Obj.h"
#include "Player.h"

CCollisionMgr::CCollisionMgr()
{
}


CCollisionMgr::~CCollisionMgr()
{
}

void CCollisionMgr::Collision_Coin(list<CObj*>& _Dst, list<CObj*>& _Src)
{
	RECT rc = {};

	for (auto& Dst : _Dst)
	{
		for (auto& Src : _Src)
		{
			if (IntersectRect(&rc, &static_cast<CPlayer*>(Dst)->Get_RectBottom(), &Src->Get_Rect()))
			{
				Src->Set_Dead();
				static_cast<CPlayer*>(Dst)->Set_Coin(1);
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

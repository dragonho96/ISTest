#pragma once
#ifndef __STRUCT_H__
#define __STRUCT_H__

typedef struct tagInfo
{
	tagInfo() {}

	tagInfo(float _fX, float _fY, int _iCX, int _iCY)
		: fX(_fX), fY(_fY), iCX(_iCX), iCY(_iCY) {}

	float	fX;
	float	fY;
	int		iCX;
	int		iCY;
}INFO;


typedef struct tagFrame
{
	int		iStartX;
	int		iEndX;
	int		iStateY;
	DWORD	dwDelayTime;
	DWORD	dwTime;
}FRAME;


#endif // !__STRUCT_H__

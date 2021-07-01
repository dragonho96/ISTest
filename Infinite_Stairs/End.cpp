#include "stdafx.h"
#include "End.h"
#include "ObjMgr.h"


CEnd::CEnd()
{
}


CEnd::~CEnd()
{
	Release();
}

void CEnd::Initialize()
{
}

void CEnd::Update()
{
	CObjMgr::Get_Instance()->Update();

}

void CEnd::Late_Update()
{
	CObjMgr::Get_Instance()->Late_Update();

}

void CEnd::Render(HDC _DC)
{
	CObjMgr::Get_Instance()->Render(_DC);

}

void CEnd::Release()
{
}

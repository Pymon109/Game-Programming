#include "SingleTon.h"

C_SingleTon* C_SingleTon::_instance = nullptr;

void main()
{
	C_SingleTon* pInstance = C_SingleTon::GetInstance();
	C_SingleTon* pSingelObjectA = C_SingleTon::GetInstance();
	C_SingleTon* pSingelObject[2];

	pInstance->ShowMessage();
	pSingelObjectA->ShowMessage();

	pSingelObject[0] = C_SingleTon::GetInstance();
	pSingelObject[1] = C_SingleTon::GetInstance();

	pSingelObject[0]->ShowMessage();
	pSingelObject[1]->ShowMessage();

	pInstance->Release();
	pSingelObjectA->Release();
	pSingelObject[0]->Release();
	pSingelObject[1]->Release();
}
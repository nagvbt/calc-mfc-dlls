#include "StdAfx.h"
#include "MyMath.h"

CMyMath::CMyMath(void)
{
}

CMyMath::~CMyMath(void)
{
}

// Add two values
long CMyMath::Add(long lVal1, long lVal2)
{
	return (lVal1 + lVal2);
}

// Subtract two values
long CMyMath::Sub(long lVal1, long lVal2)
{
	return (lVal1 - lVal2);
}

// Subtract two values
long CMyMath::Mul(long lVal1, long lVal2)
{
	return (lVal1 * lVal2);
}

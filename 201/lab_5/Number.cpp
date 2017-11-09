#include "Number.h"

Number::Number(int n)
{
	this->n = n;
}
bool Number::isDivisibleBy(int k) const
{
	return n % k == 0;
}
bool Number::isPrime() const
{
	for (int i = 2; i < n; ++i)
	{
		if (n % i == 0) return false;
	}
	return true;
}

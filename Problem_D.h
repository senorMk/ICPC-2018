#pragma once

bool PowerOfTwo(unsigned long long N)
{
	if (N == 0)
		return false;

	while (N != 1)
	{
		if (N % 2 != 0)
			return false;
		N = N / 2;
	}
	return true;
}
#pragma once

int F_n(int n, int a, int b, int c, int d)
{
	int ret = 0;

	if (n < 0)
		return 0;
	else if (n == 0)
		return 1;

	ret = a * F_n(n - 1, a, b, c, d) + b * F_n(n - 2, a, b, c, d) + c * F_n(n - 3, a, b, c, d) + (int)pow(2, d);

	return ret;
}
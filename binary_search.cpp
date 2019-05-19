extern int binary_search(int* a, int x, int s, int e)
{
	int m;
	while (s <= e)
	{
		m = (s + e) / 2;
		if (x < a[m]) e = m - 1;
		else if (a[m] < x) s = m + 1;
		else return m;
	}
	return -1;
}
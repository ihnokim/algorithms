extern int binary_search(int* a, int x, int s, int e)
{
	while (s <= e)
	{
		int mid = (s + e) / 2;
		if (x < a[mid]) e = mid - 1;
		else if (a[mid] < x) s = mid + 1;
		else return mid;
	}
	return -1;
}

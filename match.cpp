extern int count_match(int n, int* a, int* b)
{
	int cnt = 0;
	int l = 0, r = 0, k, lcnt, rcnt;
	while (l < n && r < n) {
		if (a[l] < b[r]) l++;
		else if (a[l] > b[r]) r++;
		else {
			k = a[l], lcnt = rcnt = 0;
			while (a[l] == k) lcnt++, l++;
			while (b[r] == k) rcnt++, r++;
			cnt += lcnt * rcnt;
		}
	}
	return cnt;
}
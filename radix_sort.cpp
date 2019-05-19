#include <malloc.h>
const int P = (1 << 8);
int cnt[P];

extern void radix_sort(int n, int* a, int* tmp)
{
	register int i, k;
	for (k = 0; k < 32; k += 8)
	{
		for (i = 0; i < P; i++) cnt[i] = 0;
		for (i = 0; i < n; i++) cnt[(a[i] >> k) & (P - 1)]++;
		for (i = 1; i < P; i++) cnt[i] += cnt[i - 1];
		for (i = n - 1; i >= 0; i--) tmp[--cnt[(a[i] >> k) & (P - 1)]] = a[i];
		int* s = a; a = tmp; tmp = s;
	}
}
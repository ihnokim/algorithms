extern inline bool lt(int a, int b)
{
	return a < b;
}

extern inline bool gt(int a, int b)
{
	return a > b;
}

extern inline bool le(int a, int b)
{
	return a <= b;
}

extern inline bool ge(int a, int b)
{
	return a >= b;
}

extern inline bool eq(int a, int b)
{
	return a == b;
}

extern inline bool ne(int a, int b)
{
	return a != b;
}

extern inline void swap(int& a, int& b)
{
	int tmp = a;
	a = b;
	b = tmp;
}
#include <stdio.h>

int ctoi(char c)
{
	if (c >= '0' && c <= '9') return c - '0';
	else if (c >= 'A' && c <= 'Z') return c - 'A' + 10;
	// else if (c >= 'a' && c <= 'z') return c - 'a' + 10;
	else return -1;
}

char itoc(int i)
{
	if (i >= 0 && i <= 9) return i + '0';
	else if (i >= 10) return i - 10 + 'A';
	else return -1;
}

unsigned long long decimal_encoder(char* number, int from)
{
	unsigned long long ret = 0;
	for (register int i = 0; number[i]; i++) ret = (ret * from) + ctoi(number[i]);
	return ret;
}

void decimal_decoder(unsigned long long number, int to)
{
	if (!number) return;
	decimal_decoder(number / to, to);
	printf("%c", itoc(number % to));
}

extern void convert(char* number, int from, int to)
{
	unsigned long long x = decimal_encoder(number, from);
	if (!x) {
		printf("0");
		return;
	}
	decimal_decoder(x, to);
}
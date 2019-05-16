#define INVALID 0
int heap[100], size;
bool valid[100];

bool lt(int a, int b);
void swap(int& a, int& b);

bool (*cmp)(int, int) = lt;
extern void push(int x)
{
	heap[++size] = x;
	for (int i = size; i > 1 && cmp(heap[i], heap[i / 2]); i /= 2) swap(heap[i], heap[i / 2]);
}

extern int pop()
{
	int ret = heap[1], next_idx;
	register int i;
	swap(heap[1], heap[size--]);
	for (i = 1; i * 2 <= size;)
	{
		next_idx = i * 2;
		if (next_idx + 1 <= size && cmp(heap[next_idx + 1], heap[next_idx])) next_idx++;
		if (cmp(heap[next_idx], heap[i])) swap(heap[next_idx], heap[i]);
		else break;
		i = next_idx;
	}
	return ret;
}

extern int top()
{
	if (!size) return INVALID;
	while (valid[heap[1]])
	{
		pop();
		if (!size) return INVALID;
	}
	return heap[1];
}
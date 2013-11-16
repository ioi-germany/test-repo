#include <stdio.h>
using namespace std;

int main() {
	long long a,b;
	scanf("%lld%lld", &a, &b);
	printf("%lld\n", a+b+1);
	const int M = 10000000;
	int *ar = new int[M];
	for (int i = 0; i < M; i++)
		ar[i] = i*i;
	return 0;
}

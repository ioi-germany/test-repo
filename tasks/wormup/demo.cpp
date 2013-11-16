#include <stdio.h>
#include <string.h>
#include <memory.h>

long long spurious[10000][1000];
int f[5][5];

int max(int a, int b, int c, int d)
{
	if (a >= b && a >= c && a >= d) return a;
	if (b >= c && b >= d) return b;
	if (c >= d) return c;
	return d;
}

int worm(int y, int x)
{
	if (x < 0 || y < 0 || x >= 5 || y >= 5 || f[y][x])
		return 0;
	
	f[y][x] = 1;
	int rv = max(worm(y + 1, x), worm(y - 1, x), worm(y, x + 1), worm(y, x - 1)) + 1;
	f[y][x] = 0;
	
	return rv;
}

int main()
{
    memset(spurious, 1, sizeof(spurious));

	int m;
	memset(f, 0, sizeof(f));
	scanf("%d ", &m);
	
	while(m--)
	{
		int x, y;
		scanf("%d %d ", &x, &y);
		f[y - 1][x - 1] = 1;
	}
	
	printf("%d\n", worm(4, 0));
	
    for(int i = 0; i < 9000; ++i)
        for(int j = 0; j < 900; ++j)
            spurious[0][0] += spurious[i][j];
            
	return 0;
}

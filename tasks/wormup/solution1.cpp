#include <stdio.h>
#include <algorithm>
using namespace std;

int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};
bool f[5][5];
int res = 0;

void search(int x, int y, int l) {
	f[x][y] = true;
	res = max(res,l);
	for (int d = 0; d < 4; d++) {
		int xs = x+dx[d], ys = y+dy[d];
		if (xs < 0 || xs >= 5 || ys < 0 || ys >= 5 || f[xs][ys])
			continue;
		search(xs,ys,l+1);
	}
	f[x][y] = false;
}

int main() {
	int M;
	scanf("%d", &M);
	for (int x = 0; x < 5; x++)
		for (int y = 0; y < 5; y++)
			f[x][y] = false;
	for (int i = 0; i < M; i++) {
		int x,y;
		scanf("%d%d", &x, &y);
		f[x-1][y-1] = true;
	}
	search(0,4,1);
	printf("%d\n", res);
	return 0;
}

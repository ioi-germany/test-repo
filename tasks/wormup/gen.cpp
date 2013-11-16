#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <vector>
#include <algorithm>
using namespace std;

char line[100];

int main() {
	int seed;
	scanf("%d", &seed);
	srand(seed);
	vector<pair<int,int> > ps;
	for (int y = 0; y < 5; y++) {
		scanf("%s", line);
		for (int x = 0; x < 5; x++) {
			if (line[x] == 'X') {
				assert(x != 0 || y != 4);
				ps.push_back(make_pair(x,y));
			}
		}
	}
	int P = ps.size();
	for (int i = 0; i < P; i++)
		swap(ps[i],ps[rand()%(i+1)]);
	printf("%d\n", P);
	for (int i = 0; i < P; i++)
		printf("%d %d\n", ps[i].first+1, ps[i].second+1);
	return 0;
}

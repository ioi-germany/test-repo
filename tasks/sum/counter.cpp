#include <stdio.h>
using namespace std;

long long r=0,s=3;

int main() {
	long long a,b;
	scanf("%lld%lld", &a, &b);
	while(a>0) {
		r++;
		a--;
		s*=s;
	}
	while(a<0) {
		r--;
		a++;
		s*=s;
	}
	while(b>0) {
		r++;
		b--;
		s*=s;
	}
	while(b<0) {
		r--;
		b++;
		s*=s;
	}
	printf("%lld\n", r);
	return 0;
}

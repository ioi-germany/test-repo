#include <stdio.h>
#include <assert.h>
#include <random>
using namespace std;

int main(int argc, char **argv) {
    assert(argc == 3);
    unsigned int seed;
    assert(sscanf(argv[1],"%u",&seed) == 1);
    long long ma;
    assert(sscanf(argv[2],"%lld",&ma) == 1);
    assert(0 <= ma);
    mt19937 gen(seed);
    uniform_int_distribution<long long> dis(-ma, ma);
    printf("%lld %lld\n", dis(gen), dis(gen));
    return 0;
}

#include <compframework.h>
#include <algorithm>
using namespace std;

void check() {
    long long ok; fscanf(fok, "%lld", &ok);
    long long out;
    try { out = read_or_fail<long long>(fout); }
    catch(string s) { result(0.0, "Not correct: no integer in file"); }
    catch(...) { result(STD_FAILURE_SCORE, "Comparator failure"); }
    
    if(not rest_empty(fout))    result(0.0, "Not correct: garbage at end of file");
    
    if(out == ok)   result(1.0, "Correct");
    if(abs(out - ok) <= 1)  result(0.3, "Almost...");
    result(0.0, "Not correct");
}

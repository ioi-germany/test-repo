#include"constraints.h"
#include<checkframework.h>
#include<set>

using namespace std;

void check(int argc, char **argv)
{   
	int num_stones = t.parse_and_auto_check<int>("M", "\n");

	set<pair<int,int> > stones; 
	for(int i = 0; i < num_stones; ++i)
	{
		int a, b;
		a = t.parse_and_auto_check<int>("x", " ");
		b = t.parse_and_auto_check<int>("y", "\n");
		
		if(a == 1 and b == 5) die("willy's head is smashed under a stone");
		
		pair<int, int> p(a,b);
		if(stones.find(p) != stones.end()) die("two stones on same place");
		stones.insert(p);
	}
	
	// TODO Should we maybe move this to checkframework.h ?
	if(not t.finished())    die("garbage at end of file: next token is '%s'", t.next_or_fail().c_str());
}

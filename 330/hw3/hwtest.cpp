#include <iostream>#include <cassert>#include "List.h"using namespace std;int main(){    List<int> a;    List<int> b;        assert(a.size() == 0);    assert(b.size() == 0);    a.push_front(9);    b.push_front(10);        assert(!a.empty());    assert(a.front() == 9);    assert(!b.empty());    assert(b.front() == 10);        List<int>::iterator alist = a.begin();    List<int>::iterator blist = b.begin();    alist = a.begin();    blist = b.begin();    assert(*alist == 9);    assert(*blist == 10);        a.insert(alist,5);    assert(*alist == 5);    assert(*++alist == 9);    b.insert(blist,4);    assert(*blist == 4);    assert(*++blist == 10);        a.ordered_union(a,b);    assert(*alist == 4);    cout << "succes \n";    return 0;   }
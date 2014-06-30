/* Quick Union algorithm for connectivity uses a un
  To implement find() we start at the given site, follow its link to another site, follow that sites link to yet another site, and so forth,
 * following links until reaching a root, a site that has a link to itself. 
 * 
 * Two sites are in the same component if and only if this process leads them to the same root. To validate this process, we need union() to maintain this
 * invariant, which is easily arranged:
 *    we follow links to find the roots associated with each of the given sites, then rename one of the components by linking one of these roots to the other. 
 */
#include "QuickFind.h"
#include <iostream>
using namespace std;

QuickFind::QuickFind(int N) : UnionFindADT(), id(N), count(N)
{
   for (int i = 0; i < N; i++) {
       
       id[i] = i;
   }
}

ostream& QuickFind::print(ostream& ostr) const
{
    for (auto i =  0; i < id.size(); ++i) {

        ostr << id[i] << " ";
    }
    
    ostr << endl;
    
    return ostr;
}

/*
 * change id of q to be id of q
 */
void QuickFind::do_union(int p, int q)
{
    if (is_connected(p, q)) {
        
          return;
    }
    
    int pid = id[p];
    for (auto i = 0; i <  id.size(); ++i) {
        
        if (id[i] == pid) {
            id[i] = id[q];
        }
    }
           
    count--; // reduce number of available connections
}

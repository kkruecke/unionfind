#include "WeightedQuickUnion.h"
#include <iostream>
using namespace std;

WeightedQuickUnion::WeightedQuickUnion(int N) : UnionFindADT(), id(N), size(N), count(N)  
{
  for(auto i = 0; i < N; ++i) {
        id[i] = i;
	size[i] = 1;
  }
}

//std::ostream& operator<<(std::ostream& ostr, const WeightedQuickUnion& qf)
ostream& WeightedQuickUnion::print(ostream& ostr) const
{
    for (auto i =  0; i < id.size(); ++i) {

        ostr << id[i] << " ";
    }
    
    ostr << endl;
    
    return ostr;
}

/**
* Merges the component containing site p with the component
* containing site q.
*/
void WeightedQuickUnion::do_union(int p, int q) 
{
    int rootP = root(p);
    int rootQ = root(q);

    if (rootP == rootQ)
            return;

    // make smaller root point to larger one
    
    if   (size[rootP] < size[rootQ]) { 
        
        // Q's component complement (tree) is smaller. Merge the small root with the larger
        id[rootP] = rootQ;
        
        // increase the size of the component complement by the complement size of P
        size[rootQ] += size[rootP]; 
        
    } else  { 

        // P's component complement (tree) is smaller (or eqal to P's)
        id[rootQ] = rootP;

        // increase the size of the component complement of P by the complement size of Q
        size[rootP] += size[rootQ]; 
    }

    // reduce number of new unions we can do.    
    count--;
}

int  WeightedQuickUnion::root(int p) const
{
    while (p != id[p]) {

        p = id[p];
   }

   return p;
}



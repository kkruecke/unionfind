
#include <cstdlib>
#include <iostream>
#include "QuickFind.h"
#include "QuickUnion.h"
#include "WeightedQuickUnion.h"
#include "WeightedQuickUnionPathCompressionUF.h"

using namespace std;

void run_test(UnionFindADT& uf)
{
   cout << "===================\n" ;
   
   cout << "enter two integers (between 0 and 9) or Ctrl + D to exit: " << endl;
    int p, q;
    
     while (cin >> p >> q) {
         
            if (uf.is_connected(p, q)) 
                continue;
            
            uf.do_union(p, q);
            
            cout << "The internal id array is: " << uf << endl;
           
    }
    
    cout << "\nDone. There were " << uf.get_count() << " total components";
}

int main(int argc, char** argv) 
{
    
    QuickFind x1(10);
    
    run_test(x1);
          
    QuickUnion x2(10);
    
    run_test(x2);
    
    WeightedQuickUnion x3(10);
    
    run_test(x3);
    
    WeightedQuickUnionPathCompressionUF x4(10);
    
    run_test(x4);
    return 0;
}


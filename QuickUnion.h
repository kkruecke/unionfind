/* 
 * File:   UnionFindQU.h
 * Author: kurt
 *
 * Created on June 29, 2014, 12:46 PM
 */

#ifndef  QUICKUNION_H
#define	 QUICKUNION_H
#include "UnionFindADT.h"
#include <iosfwd>
#include <ostream>
#include <vector>

class QuickUnion : public UnionFindADT {
    
private:
    std::vector<int> id;    // id[i] = parent of i
    int count;             // number of components

    int root(int p) const;       

public:
    
    QuickUnion(int N);

    /**
     * Returns the number of components.
     * @return the number of components (between 1 and N)
     */
    int  get_count() const;
    
    /**
     * Are the two sites p and q in the same component?
     */
    bool is_connected(int p, int q) const; 
  
    /**
     * Merges the component containing site p with the component
     * containing site q.
     */
    void do_union(int p, int q); 

    std::ostream& print(std::ostream&) const;        
};

inline int QuickUnion::get_count() const
{
    return count;
}

inline bool QuickUnion::is_connected(int p, int q) const
{
    return root(p) == root(q);
}
#endif	/* QUICKUNION_H */

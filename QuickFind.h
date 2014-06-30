/* 
 * File:   UnionFindQU.h
 * Author: kurt
 *
 * Created on June 29, 2014, 12:46 PM
 */

#ifndef  QUICKFIND_H
#define	 QUICKFIND_H
#include "UnionFindADT.h"
#include <vector>
#include <iosfwd>
#include <ostream>

class QuickFind : public UnionFindADT {
    
private:
    std::vector<int> id;    // id[i] = parent of i
    int count;             // number of components

public:
    
    QuickFind(int N);
    
    /**
     * Returns the number of components.
     * @return the number of component complements (between 1 and N)
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

inline int QuickFind::get_count() const
{
    return count;
}

inline bool QuickFind::is_connected(int p, int q) const
{
    return id[p] == id[q];
}
#endif	/* QUICKUNION_H */

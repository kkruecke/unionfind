/* 
 * File:   UnionFindWeightedQuickUnionPathCompression.h
 * Author: kurt
 *
 * Created on June 29, 2014, 1:52 PM
 */

#ifndef WEIGHTEDQUICKUNIONPATHCOMPRESSION_H
#define	WEIGHTEDQUICKUNIONPATHCOMPRESSION_H
#include <vector>
#include <iosfwd>
#include <ostream>
#include "UnionFindADT.h"
/*
  Weighted Quick Union
*/
class WeightedQuickUnionPathCompression : public UnionFindADT { 
     
private:
    std::vector<int> id;    // id[i] = parent of i
    std::vector<int> size;
    int count;             // number of components
 protected:

    /**
     * Returns the component identifier for the component containing site p, the root.
     * p is the integer representing one site
     * return the component identifier for the component containing site p
     */
    int root(int p) const; 
 
public:
     WeightedQuickUnionPathCompression(int N);   
     /**
     * Returns the number of components.
     * @return the number of components (between 1 and N)
     */
    int  get_count() const;
    friend std::ostream& operator<<(std::ostream& ostr, const WeightedQuickUnionPathCompression& qf);
    
    
    /**
     * Are the two sites p and q in the same component?
     */
    bool is_connected(int p, int q) const
    {
        return root(p) == root(q);
    } 
  
    /**
     * Merges the component containing site p with the component
     * containing site q.
     */
    void do_union(int p, int q); 
    
    std::ostream& print(std::ostream&) const; 
    
};

inline int WeightedQuickUnionPathCompression::get_count() const
{
    return count;
}
#endif

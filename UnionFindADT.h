/* 
 * File:   UnionFind.h
 * Author: kurt
 *
 * Created on June 29, 2014, 1:44 PM
 */

#ifndef UNIONFINDADT_H
#define	UNIONFINDADT_H
#include <iosfwd>
#include <ostream>

class UnionFindADT {
    
public:
    UnionFindADT() {}
    virtual ~UnionFindADT() {}
    /**
     * Returns the number of components, ie connect components (aka component 
     * complement).
     * @return the number of components (between 1 and N)
     */
    virtual int  get_count() const = 0;
    
    /**
     * Are the two sites p and q in the same component?
     */
    virtual bool is_connected(int p, int q) const = 0; 
  
    /**
     * Merges the component containing site p with the component containing site
     * q.
     */
    virtual void do_union(int p, int q) = 0; 
    
    friend  std::ostream& operator<<(std::ostream& ostr, const UnionFindADT& uf);
    
    virtual std::ostream& print(std::ostream&) const = 0;        
};

inline std::ostream& operator<<(std::ostream& ostr, const UnionFindADT& uf)
{
    return uf.print(ostr);
}
#endif	/* UNIONFIND_H */

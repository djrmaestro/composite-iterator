#ifndef DirectoryIterator_12142013
#define DirectoryIterator_12142013

#include <iterator>
#include <list>
#include <stack>

class Directory; // fwd references
class Node;

/*
See these articles:
 * 
http://squigglybrackets.me/2012/03/12/cpp-stl-custom-iterators/

1. part 1 ORA article
http://www.oreillynet.com/pub/a/network/2005/10/18/what-is-iterator-in-c-plus-plus.html

2. part 2 ORA article
http://www.oreillynet.com/pub/a/network/2005/11/21/what-is-iterator-in-c-plus-plus-part2.html

On providing a conversion operator to convert from iterator to const_iterator.
http://stackoverflow.com/questions/2844339/c-iterator-and-const-iterator-problem-for-own-container-class
 */

class DirectoryIterator : public std::iterator<std::input_iterator_tag, Node *> { 

  friend class Directory;
  typedef std::stack< std::pair< std::list<Node *>::iterator, std::list<Node *>::iterator> >   stack_of_list_iterator_pairs  ;
  
  std::stack< std::pair< std::list<Node *>::iterator, std::list<Node *>::iterator> >  iter_stack;
  
  /* for const_iterator behavoir, you would need this:
  std::stack< std::pair< std::list<Node *>::const_iterator, std::list<Node *>::const_iterator> >  iter_stack;
  */
  
 public:
          
    DirectoryIterator(Directory & dir);
    Node *operator*() const; //  modeled after list::iterator::operator*() const
    
    DirectoryIterator operator++();
    DirectoryIterator operator++(int);
        
/*
  ???  operator->() const

 */ 
    bool operator==(const DirectoryIterator& x) const;
    bool operator!=(const DirectoryIterator& x) const;
};

inline bool DirectoryIterator::operator!=(const DirectoryIterator& rhs) const
{
  return ! this->operator==(rhs);
}

#endif

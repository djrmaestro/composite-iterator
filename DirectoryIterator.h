#ifndef DirectoryIterator_12142013
#define DirectoryIterator_12142013
#include <iterator>
#include "Directory.h"

/*
 * See
http://squigglybrackets.me/2012/03/12/cpp-stl-custom-iterators/

1. part 1 ORA article
http://www.oreillynet.com/pub/a/network/2005/10/18/what-is-iterator-in-c-plus-plus.html

2. part 2 ORA article
http://www.oreillynet.com/pub/a/network/2005/11/21/what-is-iterator-in-c-plus-plus-part2.html
 */

class DirectoryIterator : public std::iterator<std::input_iterator_tag, Directory> { 

 public:
    DirectoryIterator(const Directory& dir);

    Directory& operator*() const;
    Directory* operator->() const;

    DirectoryIterator& operator++();
    DirectoryIterator operator++(int);

    bool operator==(DirectoryIterator rhs) const;
    bool operator!=(DirectoryIterator rhs) const;

    //Kurt: not sure I need this method
    /*
    // one way conversion: iterator -> const_iterator
    operator IntrusiveSlistIterator<T const, Tag>() const;
    */ 

 
};
#endif

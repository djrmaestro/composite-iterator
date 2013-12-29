#ifndef  Directory_H_121223013
#define  Directory_H_121223013
#include <iosfwd>
#include <iostream> 
#include <list>
#include <string>
#include <stack>
#include "Node.h"

class Directory : public Node {

    std::list<Node *> nodeList;

    std::string name;
    std::string date_created;

    friend class DirectoryIterator;
    friend class ConstDirectoryIterator;
    template<typename F> void DoRecursive(F& f, const Directory *pdir=0, std::string path=""); 

  public:

     // nested iterator classes
     class DirectoryIterator : public std::iterator<std::forward_iterator_tag, Node *> { 
   
          friend class Directory;
          
          std::stack< std::pair< std::list<Node *>::iterator, std::list<Node *>::iterator> >  iters_stack;
          
          Node *pCurrentNode;         
          Directory *pDirectory;  // This is the top level directory which will be iterated.
                  
        public:
                
          explicit DirectoryIterator(Directory & dir); 

          // Required forward iterator methods follow
          DirectoryIterator();                          
          DirectoryIterator(const DirectoryIterator&);
          DirectoryIterator& operator=(const DirectoryIterator& other);
          /* 
          Node *next();
          bool hasNext();
          */ 
          Node &operator*() const;  
          Node *operator->() const; 
          DirectoryIterator& operator++();
          DirectoryIterator operator++(int);
         
          bool operator==(const DirectoryIterator& x) const;
          bool operator!=(const DirectoryIterator& x) const;
     };

     // nested iterator class
     class ConstDirectoryIterator : public std::iterator<std::forward_iterator_tag, const Node *> { 

          friend class Directory;

           DirectoryIterator inner_iter; // fwd operations here, using "const_cast<Directory *>(this)->method()"            
        public:
                
          explicit ConstDirectoryIterator(const Directory & dir); 
          
          // Required forward iterator methods follow
          ConstDirectoryIterator();                          
          ConstDirectoryIterator(const ConstDirectoryIterator&);
          ConstDirectoryIterator& operator=(const ConstDirectoryIterator& other);
          
          const Node &operator*() const; 
          const Node *operator->() const;  
          
          ConstDirectoryIterator& operator++();
          ConstDirectoryIterator operator++(int);
                           
          bool operator==(const ConstDirectoryIterator& x) const;
          bool operator!=(const ConstDirectoryIterator& x) const;
     };
    
    typedef DirectoryIterator iterator;   
    typedef ConstDirectoryIterator const_iterator;   
    
    iterator begin();
    iterator end();
    
    const_iterator begin() const;
    const_iterator end() const;
    
    Directory(const std::string& dir_name, const std::string& created);
    
    virtual void add(Node *pnode) throw(UnsupportedOperationException);
    
    virtual void remove(Node *pnode) throw(UnsupportedOperationException)
    {
       nodeList.remove(pnode);
    }
    
    // I guess this means immediate children only not grandchildren
    virtual Node *getChild(int i) throw(UnsupportedOperationException)
    {
       // TO DO: Change to work with list:  return nodeList.at(i); 
        return 0;
    }
    
    virtual std::string getName() const throw(UnsupportedOperationException)
    {
        return name;
    }
    
    virtual std::string getDateCreated() const throw(UnsupportedOperationException)
    {
        return date_created;
    }
    
    void print(Directory *pdir=0, std::string path= "") const;

    template<typename F> void traverse(F& f);
    
    ~Directory();
};

// recursive generic method
template<typename F> void Directory::DoRecursive(F& func, const Directory *pdir, std::string parent_path)
{
/*
    std::list<Node *>::iterator list_iter = const_cast<Directory *>(pdir)->nodeList.begin();
    std::list<Node *>::iterator end_iter  = const_cast<Directory *>(pdir)->nodeList.end();
*/
    std::list<Node *>::const_iterator list_iter = pdir->nodeList.begin();
    std::list<Node *>::const_iterator end_iter  = pdir->nodeList.end();
    
    std::string dir_name = pdir->getName();
                
    func(pdir, parent_path);     
    
    parent_path += dir_name + "/";

    for (; list_iter != end_iter; ++list_iter) {
        
         const Node *pNode = *list_iter;
         
         if (dynamic_cast<const Directory *>(pNode)) {

               const Directory *p = static_cast<const Directory *>(pNode);
               DoRecursive(func, p, parent_path);
                              
         } else { 
             
            func(pNode, parent_path);
         }   
    }
}
template<typename F> void Directory::traverse(F& f)
{
   this->DoRecursive(f, this, std::string("")); 
}

inline Node &Directory::DirectoryIterator::operator *() const
{
  return *pCurrentNode;
}

inline Directory::DirectoryIterator::DirectoryIterator() : pDirectory(0), pCurrentNode(0), iters_stack()
{
}        

inline Directory::DirectoryIterator Directory::begin()
{
    return DirectoryIterator(*this); 
}

inline Directory::DirectoryIterator Directory::end()
{
    return DirectoryIterator(); 
}

inline bool Directory::DirectoryIterator::operator!=(const DirectoryIterator& rhs) const
{
    return !operator==(rhs);
}

inline Directory::ConstDirectoryIterator::ConstDirectoryIterator(const Directory & dir) : inner_iter(const_cast<Directory &>(dir))
{
    
}

inline Directory::ConstDirectoryIterator::ConstDirectoryIterator() : inner_iter()                          
{
}

inline Directory::ConstDirectoryIterator::ConstDirectoryIterator(const ConstDirectoryIterator& citer) : inner_iter(citer.inner_iter) 
{
}

inline  Directory::ConstDirectoryIterator& Directory::ConstDirectoryIterator::operator++()
{
  ++inner_iter;
  return *this;
}

inline const Node &Directory::ConstDirectoryIterator::operator*() const
{
    return const_cast<const Node &>(*inner_iter);
} 
 
inline const Node *Directory::ConstDirectoryIterator::operator->() const  
{
     return const_cast<const Node *>(inner_iter.operator->());
}

inline bool Directory::ConstDirectoryIterator::operator==(const ConstDirectoryIterator& x) const
{
    return inner_iter == x.inner_iter;
}

inline bool Directory::ConstDirectoryIterator::operator!=(const ConstDirectoryIterator& x) const
{
     return inner_iter != x.inner_iter; 
}
inline Directory::ConstDirectoryIterator& Directory::ConstDirectoryIterator::operator=(const ConstDirectoryIterator& rhs)
{
    inner_iter = rhs.inner_iter;
    return *this;
}
       
#endif

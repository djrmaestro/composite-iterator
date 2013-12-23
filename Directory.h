#ifndef  Directory_H_121223013
#define  Directory_H_121223013
#include <iosfwd>
#include <iostream> // temporarily
#include <list>
#include <string>
#include <stack>
#include "Node.h"

class Directory : public Node {

    std::list<Node *> nodeList;

    std::string name;
    std::string date_created;

    //-- void Descend(Directory *p, std::string path) const;
    Node *Descend(Directory *pdir, std::string path) const;

    /*
     * Note: To make these functions template member functions, you must include the definition also in this header file.
     */
    template<typename F> void DescendNoStack(F); //const; 
    template<typename F> void DescendNoStack_new(F f); //const

    friend class DirectoryIterator;
    friend class ConstDirectoryIterator;
    friend class CompositeIterator; // <-- remove later

    std::string path; 

    protected:

    void setPath(std::string)  throw(UnsupportedOperationException);

  public:

      // nested test iterator classes
     class CompositeIterator : public std::iterator<std::forward_iterator_tag, Node *> { 
   
          friend class Directory;
          
          std::stack< std::pair< std::list<Node *>::iterator, std::list<Node *>::iterator> >  iters_stack;
          
          Node *pCurrentNode;         
          Directory *pDirectory;  // The top level directory which will be iterated.
                  
        public:
                
          explicit CompositeIterator(Directory & dir); 

          // Required forward iterator methods follow
          CompositeIterator();                          
          CompositeIterator(const CompositeIterator&);
          CompositeIterator& operator=(const CompositeIterator& other);
          Node *next();
          bool hasNext();
     };

     // nested iterator classes
     class DirectoryIterator : public std::iterator<std::forward_iterator_tag, Node *> { 
   
          friend class Directory;
          
          std::stack< std::pair< std::list<Node *>::iterator, std::list<Node *>::iterator> >  iters_stack;
          
          Node *pCurrentNode;         
          Directory *pDirectory;  // The top level directory which will be iterated.
                  
        public:
                
          explicit DirectoryIterator(Directory & dir); 

          // Required forward iterator methods follow
          DirectoryIterator();                          
          DirectoryIterator(const DirectoryIterator&);
          DirectoryIterator& operator=(const DirectoryIterator& other);
          
       /* 
          Node *operator*() const;  // could return pair<Node *, boo>, where bool indicates whether Node * is a composite. 
          Node **operator->() const; //  std::__addressof(static_cast<_Node*>
        */  

          Node &operator*() const;  // could return pair<Node *, boo>, where bool indicates whether Node * is a composite. 
          Node *operator->() const; 
          DirectoryIterator& operator++();
          DirectoryIterator operator++(int);
         
          bool operator==(const DirectoryIterator& x) const;
          bool operator!=(const DirectoryIterator& x) const;
     };

     // nested iterator class
     class ConstDirectoryIterator : public std::iterator<std::forward_iterator_tag, const Node *> { 
   
          friend class Directory;
          std::stack< std::pair< std::list<Node *>::const_iterator, std::list<Node *>::const_iterator> >  iters_stack;
          
          const Node *pCurrentNode;
          const Directory *pDirectory;
                  
        public:
                
          explicit ConstDirectoryIterator(const Directory & dir); 

          // Required forward iterator methods follow
          ConstDirectoryIterator();                          
          ConstDirectoryIterator(const ConstDirectoryIterator&);
          ConstDirectoryIterator& operator=(const ConstDirectoryIterator& other);
          
/*   Prefer reference to pointer
          const Node *operator*() const; 
          const Node **operator->() const;
*/          
          const Node &operator*() const; 
          const Node *operator->() const;  

          ConstDirectoryIterator& operator++();
          ConstDirectoryIterator operator++(int);
                           
          bool operator==(const ConstDirectoryIterator& x) const;
          bool operator!=(const ConstDirectoryIterator& x) const;
     };
     
    CompositeIterator begin_composite();
    //--CompositeIterator end_composite();
    
    typedef DirectoryIterator iterator;   
    typedef ConstDirectoryIterator const_iterator;   
    
    iterator begin();
    iterator end();
    
    const_iterator begin() const;
    const_iterator end() const;
    
    Directory(const std::string& dir_name, const std::string& created);
    
    
    virtual void add(Node *pnode) throw(UnsupportedOperationException)
    {
        nodeList.push_back(pnode);
    }
    
    virtual void remove(Node *pnode) throw(UnsupportedOperationException)
    {
       nodeList.remove(pnode);
    }
    
    // I guess this means immediate children only not grandchildren
    virtual Node *getChild(int i) throw(UnsupportedOperationException)
    {
       // TO DO: Change to work with list
       //  return nodeList.at(i); 
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
    
    virtual void print(std::ostream&) const;

    template<typename F> void traverse(F); //--const;
        
    ~Directory();
};
 
template<typename F> inline void Directory::traverse(F f) //--const
{
    DescendNoStack_new(f);
}

//TODO: I think pDir should perhaps be set immediately after the while loop?

template<typename F> void Directory::DescendNoStack(F f) //const
{
  std::string path = "./"; // Put in DirectoryPrinter.cpp

  std::stack< std::pair< std::list<Node *>::iterator, std::list<Node *>::iterator> >  iters_stack; 
  
  // Initially we push the this->fileComponent's begin and end iterators onto the stack.
  iters_stack.push(std::make_pair(this->nodeList.begin(), this->nodeList.end()) );

  Directory *pdir = this; 

  while(!iters_stack.empty()) {
  
     std::list<Node *>::iterator list_iter     = iters_stack.top().first; 
     std::list<Node *>::iterator list_iter_end = iters_stack.top().second; 
 
     iters_stack.pop();
  
     std::string dir_name = pdir->getName(); // works
    
      //--std::string dir_name = (*iter)->getName();
     /* 
      * Logic Error: path retains all subdirs added to it.  Also if pDir doesn't change, it still gets appended each time          
      */ 
     path += dir_name + std::string("/"); 
        
     std::cout << path << "\n";

     for (;list_iter != list_iter_end; list_iter++) {

        Node *pNode = *list_iter;
      
        if (dynamic_cast<Directory *>(pNode)) {

            // If Directory, push its fileComponent begin and end iterators onto stack
            Directory *pDir = static_cast<Directory *>(pNode);
            
            iters_stack.push(std::make_pair(pDir->nodeList.begin(), pDir->nodeList.end()) ); 
            
        } else { // output file name preceeded by path
           
             std::cout << path << *pNode << std::endl; 
        }   
     }
  } 
}

template<typename F> void Directory::DescendNoStack_new(F f) //const
{
  std::string path_prefix = "./"; // Put in DirectoryPrinter.cpp

  std::stack< std::pair< std::list<Node *>::iterator, std::list<Node *>::iterator> >  iters_stack; 
  
  // Initially we push the this->fileComponent's begin and end iterators onto the stack.
  iters_stack.push(std::make_pair(this->nodeList.begin(), this->nodeList.end()) );

  std::string top_dir_name = this->getName() + "/";
  
  while(!iters_stack.empty()) {
  
     std::list<Node *>::iterator list_iter  = iters_stack.top().first; 
     std::list<Node *>::iterator list_iter_end   = iters_stack.top().second; 
 
     iters_stack.pop();
           
     /* 
      * Prior Logic Error: path retained all subdirs added to it. Subdir components were never removed.
      */ 
     std::string path = top_dir_name;
        
     std::cout << path << "\n";

     for (;list_iter != list_iter_end; list_iter++) {
         
        Node *pNode = *list_iter;
      
        if (dynamic_cast<Directory *>(pNode)) {

            // If Directory, push its fileComponent begin and end iterators onto stack
            Directory *pDir = static_cast<Directory *>(pNode);
            
            iters_stack.push(std::make_pair(pDir->nodeList.begin(), pDir->nodeList.end()) ); 
            
        } else { // output file name preceeded by path
           
             std::cout << path << *pNode << std::endl; 
        }   
     }
  } 
}


#endif

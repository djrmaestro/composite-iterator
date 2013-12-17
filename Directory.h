#ifndef  Directory_H_121223013
#define  Directory_H_121223013
#include <iosfwd>
#include <iostream> // temporarily
#include <list>
#include <string>
#include <stack>
#include "Node.h"

class Directory : public Node {

    std::list<Node *> fileComponents;

    std::string name;
    std::string date_created;

    /*
     * Note: To make these functions template member functions, include the definition also in this header file.
     */
    void Descend(Directory *p, std::string path) const;
    
    template<typename F> void DescendNoStack(F); //const; 

    friend class DirectoryIterator;

 public:   

     // nested iterator class
     class DirectoryIterator : public std::iterator<std::input_iterator_tag, Node *> { 
   
          friend class Directory;
          std::stack< std::pair< std::list<Node *>::iterator, std::list<Node *>::iterator> >  iter_stack;
        
           /* for const_iterator behavoir, we need:
           std::stack< std::pair< std::list<Node *>::const_iterator, std::list<Node *>::const_iterator> >  iter_stack;
           */
        
        public:
                
          DirectoryIterator(Directory & dir); // use for end()
          Node *operator*() const; //  modeled after list::iterator::operator*() const
          
          DirectoryIterator operator++();
          DirectoryIterator operator++(int);
              
         /*
           ???  operator->() const
         */ 
          bool operator==(const DirectoryIterator& x) const;
          bool operator!=(const DirectoryIterator& x) const;
     };

    typedef DirectoryIterator iterator;   
    iterator begin();
    iterator end();
      
    Directory(const std::string& name, const std::string& date_created)
    {
        this->name = name;
        this->date_created = date_created;
    }
    
    virtual void add(Node *pnode) throw(UnsupportedOperationException)
    {
        fileComponents.push_back(pnode);
    }
    
    virtual void remove(Node *pnode) throw(UnsupportedOperationException)
    {
       //TODO: Fix the semantics of this method. 
       // fileComponents.erase(pnode);
    }
    
    virtual Node *getChild(int i) throw(UnsupportedOperationException)
    {
       // Change to work with list
       // return fileComponents.at(i);
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
    //Descend(this, std::string("./"));
    DescendNoStack(f);
}
//TODO: f is not used yet, sya, to print
template<typename F> void Directory::DescendNoStack(F f) //const
{
  std::string path = "./";
  
  std::stack< std::pair< std::list<Node *>::iterator, std::list<Node *>::iterator> >  iter_stack;
  
  iter_stack.push(make_pair(fileComponents.begin(), fileComponents.end()) );

  while(!iter_stack.empty()) {
      
     std::pair< std::list<Node *>::iterator, std::list<Node *>::iterator >  top = iter_stack.top(); 
     iter_stack.pop();
     
     std::list<Node *>::iterator iter     = top.first; 
     std::list<Node *>::iterator iter_end = top.second; 
 
    //string dir_name = pdir->getName();
     std::string dir_name = (*iter)->getName();
                
     path += dir_name + std::string("/");
        
     std::cout << path << "\n";

     for (;iter != iter_end; iter++) {

        Node *pNode = *iter;
      
        if (dynamic_cast<Directory *>(pNode)) {

            // If Directory, push it onto stack
            Directory *pDir = static_cast<Directory *>(pNode);
            
            iter_stack.push( make_pair(pDir->fileComponents.begin(), pDir->fileComponents.end()) );
            
        } else { // output file name preceeded by path
          
            std::cout << path << *pNode << std::endl; 
        }   
     }
  } 
}

#endif

#ifndef Directory_H_121223013
#define  Directory_H_121223013
#include <iosfwd>
#include <list>
#include <string>

#include "Node.h"

class Directory : public Node {

    std::list<Node *> fileComponents;

    std::string name;
    std::string date_created;

    void Descend(Directory *p, std::string path) const;
    void DescendNoStack(); //const; 
     void DescendNoStack_new(); //const; 

    public:   
      
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

    void traverse(); //--const;
        
    ~Directory();
      
};

inline void Directory::traverse() //--const
{
    //Descend(this, std::string("./"));
    DescendNoStack_new();
}
#endif

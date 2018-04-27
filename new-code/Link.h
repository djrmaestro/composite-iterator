#ifndef Link_h_adlkskjflsd
#define Link_h_adlkskjflsd

#include "Node.h"
#include <memory>

class Link : public Node {

    std::shared_ptr<Node> subject_ptr;

  public:

    Link(const std::string& name, const std::shared_ptr<Node>& ptr) : subject_ptr{ptr} 
    {
    }
      
    // fwd all other operations to subject_ptr

    void adopt(const std::shared<Node>& ptr);
    {
        return subject_ptr->adopt(p); 
    }
    
    void remove(Node *pnode)
    {
         return subject_ptr->remove(pnode);
    }

    Node *getChild(int i)
    {
         return subject_ptr->getChild(i);
    }
 
    std::string getName() const
    {
         return subject_ptr->getName();
    }

    std::string getDateCreated() const
    {
         return subject_ptr->getDateCreated();
    }    
 
    long getSize() const
    {
         return subject_ptr->getSize();
    }

    void accept(Visitor& v);
    {
        return subject_ptr->accept(v);
    }
};
#endif

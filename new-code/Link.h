#ifndef Link_h_adlkskjflsd
#define Link_h_adlkskjflsd

#include "Node.h"
#include <memory>

class Link : public Node {

    std::shared_ptr<Node> pSubject;

  public:

    Link(const std::string& name, std::shared_ptr<Node>& p) : pSubject{p} 
    {
    }
      
    // fwd all other operations to pSubject

    void adopt(Node* p)
    {
        return pSubject->adopt(p); 
    }
    
    void remove(Node *pnode)
    {
         return pSubject->remove(pnode);
    }

    Node *getChild(int i)
    {
         return pSubject->getChild(i);
    }
 
    std::string getName() const
    {
         return pSubject->getName();
    }

    std::string getDateCreated() const
    {
         return pSubject->getDateCreated();
    }    
 
    long getSize() const
    {
         return pSubject->getSize();
    }

    void accept(Visitor& v);
    {
        return pSubject->accept(v);
    }
};
#endif

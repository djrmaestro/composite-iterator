#ifndef Link_h_adlkskjflsd
#define Link_h_adlkskjflsd
#include "Node.h"

class Link : public Node {

   private:
      Node *pSubject;
      Node *operator->();
      Node *getSubject() const;

   public:
      Link(const std::string& name, Node *p);
      
    // fwd all other operations to pSubject

    void adopt(Node* p) throw(node_logic_error);
    void remove(Node *pnode) throw(node_logic_error, std::invalid_argument);
    Node *getChild(int i)  throw(node_logic_error, std::out_of_range);
 
    std::string getName() const  throw(node_logic_error);

    std::string getDateCreated() const throw(node_logic_error);
 
    long getSize() const throw(node_logic_error);
    void accept(Visitor& v);
};

inline Link::Link(const std::string& name, Node *p) : pSubject(p) {}

inline Node* Link::getSubject() const
{ 
  return pSubject; 
}

inline Node *Link::operator->() 
{ 
  return getSubject(); 
}

inline void Link::adopt(Node* p) throw(node_logic_error)
{
    return getSubject()->adopt(p); 
}

inline void Link::remove(Node *pnode) throw(node_logic_error, std::invalid_argument)
{
     return getSubject()->remove(pnode);
}

inline Node *Link::getChild(int i)  throw(node_logic_error, std::out_of_range)
{
     return getSubject()->getChild(i);
}

inline std::string Link::getName() const  throw(node_logic_error)
{
     return getSubject()->getName();
}

inline std::string Link::getDateCreated() const throw(node_logic_error)
{
     return getSubject()->getDateCreated();
}    

inline long Link::getSize() const throw(node_logic_error)
{
     return getSubject()->getSize();
}

inline void Link::accept(Visitor& v)
{
    return getSubject()->accept(v);
}
#endif

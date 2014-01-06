#ifndef Link_h_adlkskjflsd
#define Link_h_adlkskjflsd
#include "Node.h"

class Link : public Node {

   private:
      Node *pSubject;

   public:
      Link(const std::string& name, Node *p);
      Node *getRealSubject() const;
      Node *operator->();
      // fwd all other operations to pSubject

    void adopt(Node* p) throw(node_logic_error);
    void remove(Node *pnode) throw(node_logic_error, std::invalid_argument);
    Node *getChild(int i)  throw(node_logic_error, std::out_of_range);
 
    std::string getName() const  throw(node_logic_error);

    std::string getDateCreated() const throw(node_logic_error);
 
    long getSize() const throw(node_logic_error);
    void accept(Visitor& v)
};

inline Link::Link(const std::string& name, Node *p) : pSubject(p) {}

inline Node* Link::getRealSubject() const
{ 
  return pSubject; 
}

inline Node *Link::operator->() 
{ 
  return getRealSubject(); 
}

inline void Link::adopt(Node* p) throw(node_logic_error)
{
     getRealSubject()->adopt(p); 
  
}

inline void Link::remove(Node *pnode) throw(node_logic_error, std::invalid_argument)
{
     getRealSubject()->remove(pnode);
}

Node *getChild(int i)  throw(node_logic_error, std::out_of_range)
{
     getRealSubject()->getChild(i);
}

std::string getName() const  throw(node_logic_error)
{
     getRealSubject()->getName();
}

std::string getDateCreated() const throw(node_logic_error)
{
     getRealSubject()->getDateCreated();
}    

long getSize() const throw(node_logic_error)
{
     getRealSubject()->getSize();
}

inline void Link::accept(Visitor& v)
{
    getRealSubject()->accept(v);
}

#endif

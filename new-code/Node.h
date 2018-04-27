#ifndef Node_H_12122013
#define Node_H_12122013

#include <iosfwd>
#include <string>
#include <exception>
#include <stdexcept>  

class Directory;  // fwd declarations
class Visitor;

/********************************************************************
 Node: base class for composite class Directory and leaf class File
 ********************************************************************/

class Node { // abstract base class. accept(Visitor&) is pure virtual.
    
  friend class Directory;    
  
 public:            

    Node() {};

    virtual ~Node() {};

    static const char directory_separator = '/';
     
    virtual void adopt(const shared_ptr<Node>& ptr) 
    { 
      throw logic_error("This class does not support the add operation");
    }

    virtual void remove(Node *pnode) 
    {
	throw logic_error("This class does not support the remove operation");
    }

    virtual Node *getChild(int i) 
    {
	throw logic_error("This class does not support the getChild operation");
    }
  
    virtual std::string getName() const
    {
	throw logic_error("This class does not support the getName operation");
    }
 
    virtual std::string getDateCreated() const
    {
	throw logic_error("This class does not support the getDateCreated operation");
    }    
  
    virtual long getSize() const
    {
	throw logic_error("This class does not support the getSize operation");
    }

    virtual void accept(Visitor& v) const = 0; 
    
    friend std::ostream& operator<<(std::ostream& ostr, const Node& c); 
};

inline std::ostream& operator<<(std::ostream& ostr, const Node& c) 
{
    ostr << std::string("This is class Node\n");
    return ostr;
}
#endif

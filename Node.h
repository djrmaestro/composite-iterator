#ifndef Node_H_12122013
#define Node_H_12122013
 /**********************************
 Node: base class for composite class Directory and leaf class File
 \***********************************/
#include <iosfwd>
#include <string>
#include <exception>
class Directory;

class Node {
    
  friend class Directory;    
  
public:
    
    class UnsupportedOperationException : public std::exception {
        public:  
           
       virtual const char* what() const throw()
       {
          return "This operation is not supported by the class";
       }
    };
    
protected:
    
    static const char directory_separator = '/';
    
    virtual void setPath(std::string path)  throw(UnsupportedOperationException)
    { 
      throw UnsupportedOperationException();
    }

public:    
    
    virtual void add(Node* ele) throw(UnsupportedOperationException)
    { 
      throw UnsupportedOperationException();
    }

    virtual void remove(Node *c) throw(UnsupportedOperationException) 
    {
	throw UnsupportedOperationException();
    }

    virtual Node *getChild(int i)  throw(UnsupportedOperationException)
    {
	throw UnsupportedOperationException();
    }
  
    virtual std::string getName() const  throw(UnsupportedOperationException)
    {
	throw UnsupportedOperationException();
    }
 
    virtual std::string getDateCreated() const throw(UnsupportedOperationException)
    {
	throw UnsupportedOperationException();
    }
    
    friend std::ostream& operator<<(std::ostream& ostr, const Node& c); 
        
    Node() {};

    virtual ~Node() {};
   
};

inline std::ostream& operator<<(std::ostream& ostr, const Node& c) 
{
    ostr << std::string("This is class Node\n");
    return ostr;
}
#endif

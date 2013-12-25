#ifndef FILE_H_12122013
#define  FILE_H_12122013
#include <string>
#include "Node.h"

class Directory;

class File : public Node {

    std::string name;
    std::string date_created;

    File(const File&); // can't have duplicate files

    public:   
  
    File(const std::string& file_name, const std::string& created_date) : name(file_name), date_created(created_date)
    {
    }
    
    virtual std::string getName() const throw(UnsupportedOperationException)
    {
        return name;
    }
    
    virtual std::string getDateCreated() const  throw(UnsupportedOperationException)
    {
        return date_created;
    }

    // Called by Node::operator<<(ostream&)
    virtual void print(std::ostream& ostr) const;
};
#endif

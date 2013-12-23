/* 
 * File:   File.h
 * Author: kurt
 *
 * Created on December 12, 2013, 10:10 AM
 */
#ifndef FILE_H_12122013
#define  FILE_H_12122013
#include <string>
#include "Node.h"

class Directory;

class File : public Node {

    std::string name;
    std::string path; 
    std::string date_created;

    File(const File&); // can't have duplicate files

    protected:

    void setPath(std::string) throw(UnsupportedOperationException);

    public:   
  
    File(const std::string& name, const std::string& date_created)
    {
        // TODO: need to set path. Directory.add() should set the path.
        this->name = name;
        this->date_created = date_created;
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

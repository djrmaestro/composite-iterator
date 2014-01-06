#ifndef SuffixPrintVisitor_h_239472934
#define SuffixPrintVisitor_h_239472934
#include "Visitor.h"
#include <iostream>

class File;  // forward declarations
class Directory;

class SuffixPrintVisitor : public Visitor {

 public:
    virtual void visit(File *pFile)
    {
        std::cout << '@';
    }
    
    virtual void visit(Directory *pDir)
    {
        std::cout << "/";
    }
};
#endif

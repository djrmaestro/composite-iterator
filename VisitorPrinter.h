#ifndef  VisitorPrinter_h_2394827934
#define  VisitorPrinter_h_2394827934
#include "Visitor.h"

class File;
class Directory;

class VisitorPrinter : public Visitor {
    
 public:
    void visit(File *);
    void visit(Directory *);
};
#endif
#ifndef Visitor_h_239472934
#define Visitor_h_239472934
/*
 * Visitor abstract base class
 */
class File;  // forward declarations
class Directory;

class Visitor {

   public:
       Visitor() {}
       Visitor(const Visitor& ) {}
    virtual void visit(File *) = 0;
    virtual void visit(Directory *) = 0;
};
#endif

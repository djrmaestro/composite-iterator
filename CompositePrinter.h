#ifndef Printer_h_329479234
#define Printer_h_329479234
#include <string>
#include <iosfwd>

class Printer {
    std::ostream& ostr;
    
public:
    
   Printer(std::ostream& o) : ostr(o) {};
   
   std::ostream& operator()(const Directory *pdir, std::string path) const;
   
   std::ostream& operator()(const Node *pdir, std::string path) const;
};

inline std::ostream& Printer::operator()(const Directory *pdir, std::string path) const
{
   return ostr << path << pdir->getName() << "/\n";
}

inline std::ostream& Printer::operator()(const Node *pdir, std::string path) const
{
   return ostr << path << pdir->getName() << "\n";
}
#endif

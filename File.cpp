#include "File.h"
#include <ostream>
using namespace std;

void File::print(ostream& ostr) const
{
    ostr << getName();
}

 void File::setPath(string subdir_path) throw(UnsupportedOperationException)
 {
     path = subdir_path + Node::directory_separator;
 }

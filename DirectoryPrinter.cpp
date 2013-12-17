#include "DirectoryPrinter.h"

// put in .cpp file
const DirectoryPrinter::top("./");
 
DirectoryPrinter::DirectoryPrinter(std::ostream& ostr) : coutref(ostr), current_path(DirectoryPrinter::top) 
{
  depth = 0;
  lengths.at(depth) = top.length();
}

void DirectoryPrinter::print(Node *pNode, int level)
{
    // Is it a directory
    if (dynamic_cast<Directory *>(pNode)) {

        int path_length;

        for (int i = 0; i < level; i++) {

             int path_length = std::accumulate(v.begin(), v.begin() + level, 0);
        }

        // pseudo code

        int length = pNode->getName().length();

        substr
          
        lengths.at(depth) = length;
  
        current_path 

    } else { 

    }
}


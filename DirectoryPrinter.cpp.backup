#include "DirectoryPrinter.h"
#include <numeric>
using namespace std;

// put in .cpp file
const string DirectoryPrinter::directory_separator("/");
 
DirectoryPrinter::DirectoryPrinter(std::ostream& ostr) : coutref(ostr), directory_name(".") 
{
  composite_depth = 0;
   
  directory_name =  '.' + DirectoryPrinter::directory_separator;
  
  path_component_lengths.at(composite_depth) = directory_name.length();
}

void DirectoryPrinter::print(Node *pNode, int depth, bool isDir)
{
    // Is it a directory, get directory_name
    if (isDir) {

        /* 
           TODO: do something like:
           path += pNode->getName() + std::string("/");

         */

        int path_length;

        for (int i = 0; i < depth; i++) {

             int path_length = std::accumulate(path_component_lengths.begin(),
                                               path_component_lengths.begin() + depth, 0);
        }

        // pseudo code
        /*

        int length = pNode->getName().length();

        substr
          
        lengths.at(depth) = length;
  
        current_path 
        */ 

    } else { 

    }
}


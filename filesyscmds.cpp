#include "filesyscmds.h"
#include <string>
#include "Directory.h"
using namespace std;

string head(const std::string& path)
{
   int slash_pos = path.find('/');

   if (slash_pos != string::npos) {

       return path.substr(0, slash_pos);

   } else {
       // return empty string
      return string(""); 
  }
}

string subpath(const std::string& path)
{
   int slash_pos = path.find('/');

   if (slash_pos != string::npos) {

       return path.substr(slash_pos + 1);

   } else {

       return string(path);
   }
}

/*
 * pCurrentDir is the directory to search.  
 * Note: If mkdir() passes a File* as pCurrent instead of a Directory*, this will result in
 * File::getChild(int) throwing node_logic_error.
 */
Node *find(std::string& name, Node *pCurrent) 
{
  Node *pChild = 0;

  // getChild(int) returns 0 if no child found. 
  for (int i = 0; pChild = pCurrent->getChild(i); i++) {

       if (name == pChild->getName())  {
	    break;
       }                   
  } 

  return pChild;
}
/*
 * We must handle not only cases like
 *    mkdir newsubdir
 * but also
 *    mkdir subdirA/subdirB/newsubdir
 * Logic in the later case is:
 * 1. find subdirA (reporting and error if it doesn't exist)
 * 2. find subdirB (reporting and error if it doesn't exist)
 * 3. have subdirB add newsubdir to its children.
 *
 */
void mkdir(Node *pCurrent, const string& path)
{
   
   string sub_path = subpath(path); // everything but the first name in the path

   if (sub_path.empty()) {

        // The time is hardcode for now
        Directory *pDir = new Directory(path, std::string("10/10/2013")); 
        pCurrent->add(pDir);
      
   } else {

      string name = head(path); // first name in the path

      Node *pChild = find(name, pCurrent);

      if (pChild) {

         mkdir(pChild, sub_path);

      } else {

         cerr << name << " is  nonexistent." << endl;
      }
   }
}

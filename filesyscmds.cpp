#include "filesyscmds.h"
#include <string>
#include "Directory.h"
using namespace std;

string head(const std::string& full_path)
{
   int slash_pos = full_path.find('/');

   if (slash_pos != string::npos) {

       return full_path.substr(0, slash_pos - 1);

   } else {

      return full_path;
  }
}

string subpath(const std::string& full_path)
{
   int slash_pos = full_path.find('/');

   if (slash_pos != string::npos) {

       return full_path.substr(slash_pos - 1);

   } else {

       return full_path;
   }
}

/*
 * pCurrentDir is the directory to search. 
 * Note: If mkdir() passes a File* instead of a Directory* to find(), this will result in
 * an exception being thrown when File::getChild(int) is called.
 */
Node *find(std::string& name, Node *pCurrent) // pCurrent is the Directory to search
{
  Node *pChild = 0;

  // getChild returns 0, if no chid found. Does it through an exception? I say yes.
  for (int i = 0; pChild = pCurrent->getChild(i); i++) {

       if (name == pChild->getName())  {
	    break;
       }                   
 
  } 
  return pChild;
}

void mkdir(Node *pCurrent, const string& path)
{
   
   string sub_path = subpath(path);

   if (sub_path.empty()) {

        // The time is hardcode for now
        Directory *pDir = new Directory(path, std::string("10/10/2013")); 
        pCurrent->add(pDir);
      
   } else {

      string name = head(path); // subpath

      Node *pChild = find(name, pCurrent);

      if (pChild) {

         mkdir(pChild, sub_path);

      } else {

         cerr << name << " is  nonexistent." << endl;
      }
   }
}
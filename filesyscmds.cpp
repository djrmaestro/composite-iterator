#include "filesyscmds.h"
using namespace std;

string head(const std::string& full_path)
{
   int slash_pos = full_path.find('/');
   if ()
   return full_path.substr(0, slash_pos - 1);
}

string subpath(const std::string& full_path)
{
   int slash_pos = full_path.find('/');
   if (not the end)
   return full_path.substr(slash_pos - 1);
}

/*
 * pCurrentDir is the directory to search. 
 * Note: If mkdir() passes a File* instead of a Directory* to find(), this will result in
 * an exception being thrown when File::getChild(int) is called.
 */
Node *find(std::string& name, Node *pCurrentDir) // pCurrent is the Directory to search
{
   // getChild returns 0, if no chid found. Does it through an exception? I say yes.
   for (int i = 0; child = pCurrent->getChild(i)l i++) {

   } 
}

#endif

void mkdir(Node *pCurrent, const string& subdir_name)
{
   string subpath = subpath(path);

   if (subpath.empty()) {

        //TODO: Use weak_ptr for pDir
        Directory *pDir = new Directory(subdir_name);
        pCurrent->add(pDir);
      
   } else {

      string name = head(path);

      Node *pChild = find(name, current);

      if (pChild) {

         mkdir(pChild, subpath);

      } else {

         cerr << sudbdir_name << " is  nonexistent." << endl;
      }
   }
}


Node *find(const string& name, Node *pCurrent)
{
  Node *pChild = 0;

  for (
}

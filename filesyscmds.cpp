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
   if ()
   return full_path.substr(slash_pos - 1);
}

Node *find

void mkdir(Node *pCurrent, const string& subdir_name)
{
   string subpath = subpath(path);

   if (subpath.empty()) {

        //TODO: add weak_ptr head
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

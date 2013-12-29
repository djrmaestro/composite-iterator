#include "filesyscmd.h"
using namespace std;

// Untested code

string head(const string& full_path);
{ 
  // returns first name in full_path
  int slash_pos = full_path.find('/');

  // TODO: 
  // What if there is no '/'?
  return full_path.substr(0, slash_pos);
}

string subpath(const string& full_path)
{
   // returns first name in full_path
  int slash_pos = full_path.find('/');

  // TODO: 
  // 1. What if there is no '/'? 
  // 2. What if it is the last character?
  return full_path.substr(slash_pos + 1);
 // returns everything minus head(full_path) 
}

/*
 * Add comments from pattern hatching on what this method is to do
 */
void mkdir(Node *pCurrent, std::string path) 
{
  strong subpath = subpath(path);

  if (subpath.empty()) {

        // TODO: change to shared_ptr, or unique ptr that transfers ownership to current's internal pointer type -- of shared_pointer?
        Directory *p =   new Directory(path);
	current->add( );

  } else {
       string name = head(path);

       // TODO: change this to use a weak pointer?
       Node *pChild = find(name, current);
       if (child) {

          mkdir(pChild, subpath);  // recursive call. mkdir accepts Node *

       } else {
           cerr << name << " nonexistent. " << endl;
       }
  }
}

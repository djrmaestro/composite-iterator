#include "Directory.h"
#include "DirectoryIterator.h"
#include <stack>
#include <iostream>

using namespace std;

DirectoryIterator Directory::begin()
{
    DirectoryIterator x(*this); 
    return x;
}

Directory::~Directory()
{
 /*
    traverse and delete children
    Take advantage of the Node destructor being virtual, which will allow recursion to be used.
   */
  list<Node*>::iterator iter     = fileComponents.begin();
  list<Node*>::iterator iter_end = fileComponents.end();

  for (;iter != iter_end; iter++) { 
     // delete Node from memory
     Node *pNode = *iter; 
     delete pNode;
  }   
}

void Directory::print(ostream& ostr) const
{
    ostr << getName();
}

void Directory::Descend(Directory *pdir, string path) const
{
    list<Node *>::iterator iter = pdir->fileComponents.begin();
    list<Node *>::iterator end_iter = pdir->fileComponents.end();
    
    string dir_name = pdir->getName();
                
    path += dir_name + "/";
        
    cout << path << "\n";

    for (; iter != end_iter; iter++) {
        
         Node *pNode = *iter;
         
         if (dynamic_cast<Directory *>(pNode)) {

               Directory *p = static_cast<Directory *>(pNode);
               Descend(p, path);
               
         } else { // output file name preceeded by path
             
            cout << path << *pNode << endl; 
         }   
    }
}
/* This is now a template method define in the header file
void Directory::DescendNoStack() //const
{
  string path = "./";
  
  stack< pair< list<Node *>::iterator, list<Node *>::iterator> >  iter_stack;
  
  iter_stack.push(make_pair(fileComponents.begin(), fileComponents.end()) );

  while(!iter_stack.empty()) {
      
     pair< list<Node *>::iterator, list<Node *>::iterator >  top = iter_stack.top(); 
     iter_stack.pop();
     
     list<Node *>::iterator iter     = top.first; 
     list<Node *>::iterator iter_end = top.second; 
 
    //string dir_name = pdir->getName();
     string dir_name = (*iter)->getName();
                
     path += dir_name + string("/");
        
     cout << path << "\n";

     for (;iter != iter_end; iter++) {

        Node *pNode = *iter;
      
        if (dynamic_cast<Directory *>(pNode)) {

            // If Directory, push it onto stack
            Directory *pDir = static_cast<Directory *>(pNode);
            
            iter_stack.push( make_pair(pDir->fileComponents.begin(), pDir->fileComponents.end()) );
            
        } else { // output file name preceeded by path
          
            cout << path << *pNode << endl; 
        }   
     }
  } 
}
*/

#include "Directory.h"
#include <stack>
#include <iostream>

using namespace std;

Directory::~Directory()
{
  //TODO: traverse and delete children
    
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
/*
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

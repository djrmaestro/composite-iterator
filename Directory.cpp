#include "Directory.h"
#include <stack>
#include <iostream>

using namespace std;

Directory::iterator Directory::begin()
{
    DirectoryIterator x(*this); 
    return x;
}

Directory::iterator Directory::end()
{
    return DirectoryIterator(); 
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
     delete pNode; // will invoke virtual dtor
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


Directory::DirectoryIterator::DirectoryIterator(Directory& dir)
{
  iter_stack.push(make_pair(dir.fileComponents.begin(), dir.fileComponents.end()) );
}

Directory::DirectoryIterator::DirectoryIterator() : iter_stack() 
{
}


bool Directory::DirectoryIterator::operator==(const DirectoryIterator& rhs) const
{
    return true;
}

Node *Directory::DirectoryIterator::operator *() const
{
  if (!iter_stack.empty()) {

      list<Node *>::iterator iter = iter_stack.top().first;
      return *iter;
  } 
}

Directory::iterator  Directory::DirectoryIterator::operator++() 
{
  if (!iter_stack.empty()) {
      
//     pair< list<Node *>::iterator, list<Node *>::iterator >  top = iter_stack.top(); 
//     iter_stack.pop();
    
//     list<Node *>::iterator iter     = top.first; 
//     list<Node *>::iterator iter_end = top.second; 
 

     list<Node *>::iterator iter     = iter_stack.top().first; 
     list<Node *>::iterator iter_end = iter_stack.top().second; 
     iter_stack.pop();

     if (iter != iter_end) { 

        iter++;

        if (dynamic_cast<Directory *>(*iter)) {

            // If Directory, push it onto stack
            Directory *pDir = static_cast<Directory *>(*iter);
            
            iter_stack.push( make_pair(pDir->fileComponents.begin(), pDir->fileComponents.end()) );
        }  

        return *this;
     }

  } else {

     // stack is empty and there is nothing to return
  }
}

Directory::iterator  Directory::DirectoryIterator::operator++(int) //postfix
{
   DirectoryIterator temp(*this);
   
   ++*this;
   
   return temp;
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

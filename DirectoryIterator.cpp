#include "DirectoryIterator.h"
#include "Directory.h"

using namespace std;


DirectoryIterator::DirectoryIterator(Directory& dir)
{
  iter_stack.push(make_pair(dir.fileComponents.begin(), dir.fileComponents.end()) );
}


bool DirectoryIterator::operator==(const DirectoryIterator& rhs) const
{
  return true;
}

Node *DirectoryIterator::operator *() const
{
  if (!iter_stack.empty()) {

      list<Node *>::iterator iter = iter_stack.top().first;
      return *iter;
  } 
}

DirectoryIterator  DirectoryIterator::operator++() 
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


DirectoryIterator  DirectoryIterator::operator++(int) //postfix
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

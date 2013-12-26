#include "Directory.h"
#include <stack>
#include <iostream>

using namespace std;

Directory::Directory(const std::string& dir_name, const std::string& created) : name(dir_name), date_created(created)
{    
}

void Directory::add(Node *pNode) throw(UnsupportedOperationException)
{
    nodeList.push_back(pNode);
}

Directory::const_iterator Directory::begin() const
{
    return ConstDirectoryIterator(*this); 
}

Directory::const_iterator Directory::end() const
{
    return ConstDirectoryIterator(); 
}
 
/*
bool Directory::DirectoryIterator::hasNext()
{
   if (iters_stack.empty()) {

	return false;

   } else {

	pair<list<Node*>::iterator, list<Node*>::iterator>& pair_ = iters_stack.top();
        list<Node*>::iterator& list_iter = pair_.first;
        list<Node*>::iterator& list_iter_end = pair_.second;

	 if (list_iter == list_iter_end) {

	     iters_stack.pop();

	     return hasNext();

	} else {

	      return true;
	}
   }
}

Node *Directory::DirectoryIterator::next()
{
  if (hasNext()) {

        list<Node*>::iterator& list_iter = iters_stack.top().first;
        list<Node*>::iterator& list_iter_end = iters_stack.top().second;

        Node *pNode = *list_iter;
        ++list_iter; 

        if (dynamic_cast<Directory *>(pNode)) {

             Directory *pDir = static_cast<Directory *>(pNode);
             iters_stack.push( make_pair(pDir->nodeList.begin(), pDir->nodeList.end()) );
        }

        return pNode; 
 
  } else {

     return 0;
  }
}
*/

//  Since base class destructor is virtual, this will cause recursive descent
Directory::~Directory()
{
  list<Node*>::iterator list_iter     = nodeList.begin();
  list<Node*>::iterator list_iter_end = nodeList.end();

  for (;list_iter != list_iter_end; ++list_iter) { 
  
     delete *list_iter; 
  }   
}

/*
  prints in-order. Thus, if dir1 and dir2 were added to top/ before file top_f1, the output will look like:
  top/
  top/dir1
  top/dir1/dir_f1
  top/dir2
  top/dir2/dir2_f1
  top/top_f1
 */
void Directory::print(ostream& ostr) const
{
    Directory *pDir = const_cast<Directory *>(this);
    Directory::iterator  iter = pDir->begin(); 
    Directory::iterator  iter_end = pDir->end(); 
                           
    for(; iter != iter_end; ++iter)  {
        
          Node &node = *iter;
          
          cout << node.getName(); 
          
          if (dynamic_cast<Directory*>(&node) ) {
              
             cout << " is a Directory ";
              
          } else {
              
              cout << " is a File ";
          }
          
          cout << endl;
    }
}

// debug version prefixes address
void Directory::print_debug(ostream& ostr) const
{
    // print children info
    Directory *pDir = const_cast<Directory *>(this);
    
    Directory::iterator  iter = pDir->begin(); 
    Directory::iterator  iter_end = pDir->end(); 
    
    for(; iter != iter_end; ++iter)  {
        
          Node &node = *iter;
          
          cout << "[address: " << &node << "] " << node.getName(); 
          
          if (dynamic_cast<Directory*>(&node) ) {
              
             cout << " is a Directory ";
              
          } else {
              
              cout << " is a File ";
          }
          
          cout << endl;
    }
}
 
/*
 * Non-recursive descend of composite 
 */
Node *Directory::Descend(Directory *pdir, string path) const
{
    list<Node *>::iterator list_iter = pdir->nodeList.begin();
    list<Node *>::iterator end_iter = pdir->nodeList.end();
    
    string dir_name = pdir->getName();
                
    path += dir_name + "/";
        
    cout << path << "\n";

    for (; list_iter != end_iter; ++list_iter) {
        
         Node *pNode = *list_iter;
         
         if (dynamic_cast<Directory *>(pNode)) {

               Directory *p = static_cast<Directory *>(pNode);
               Descend(p, path);
               
         } else { 
             
            return pNode; 
         }   
    }
    
    return 0;
}

Directory::DirectoryIterator::DirectoryIterator(const DirectoryIterator& rhs) : pDirectory(rhs.pDirectory), pCurrentNode(rhs.pCurrentNode),
        iters_stack(rhs.iters_stack) 
{
} 

Directory::DirectoryIterator::DirectoryIterator(Directory& dir) : pDirectory(&dir) 
{
  iters_stack.push(make_pair(dir.nodeList.begin(), dir.nodeList.end()) ); 
  pCurrentNode = pDirectory; 
}

Directory::DirectoryIterator& Directory::DirectoryIterator::operator=(const DirectoryIterator& rhs)
{
  pCurrentNode = rhs.pCurrentNode;
  pDirectory = rhs.pDirectory;        
  iters_stack = rhs.iters_stack; 
  return *this;
}

bool Directory::DirectoryIterator::operator==(const DirectoryIterator& rhs) const
{
 /*
  * This will return 'true' for an end iterator where rhs.pCurrentNode is 0.
  */
   return  iters_stack.empty() && pCurrentNode == rhs.pCurrentNode;
}

Node *Directory::DirectoryIterator::operator->() const
{
  if (!iters_stack.empty()) {

     return pCurrentNode;

  } else {

     return 0;
  } 
}
 
Directory::DirectoryIterator&  Directory::DirectoryIterator::operator++() 
{
  if (iters_stack.empty()) {

        pCurrentNode = 0;

  } else {

	list<Node*>::iterator& list_iter     = iters_stack.top().first;
	list<Node*>::iterator& list_iter_end = iters_stack.top().second;
        
	 if (list_iter == list_iter_end) {

	     iters_stack.pop();

	     return this->operator++(); // recurse

	} else {
              /* pCurrentNode initiallyt to this->pDirectory in ctor. */
              
              pCurrentNode = *list_iter; 
              ++list_iter;  

              if (dynamic_cast<Directory *>(pCurrentNode)) {

                  Directory *pDir = static_cast<Directory *>(pCurrentNode);
                  iters_stack.push( make_pair(pDir->nodeList.begin(), pDir->nodeList.end()) );
              }
	}
  }
  
  return *this;
}

Directory::iterator  Directory::DirectoryIterator::operator++(int) //postfix
{
   DirectoryIterator tmp(*this);
   ++*this;
   return tmp;
}

Directory::ConstDirectoryIterator Directory::ConstDirectoryIterator::operator++(int) //postfix
{
   ConstDirectoryIterator tmp(*this);
   ++*this;
   return tmp;
}

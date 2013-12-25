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

/* 
Directory::CompositeIterator Directory::begin_composite()
{
    return CompositeIterator(*this); 
}

bool Directory::CompositeIterator::hasNext()
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

Node *Directory::CompositeIterator::next()
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

Directory::CompositeIterator::CompositeIterator(Directory &dir)
{
   pDirectory = &dir; 

   iters_stack.push(make_pair(  dir.nodeList.begin(), dir.nodeList.end() ));

   pCurrentNode = pDirectory;  
}

Directory::CompositeIterator&  Directory::CompositeIterator::operator++()
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
              // pCurrentNode was set to "this" in ctor. We need to always first dereference the list iterator before
              // advancing it. 
              
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
// Copy ctor
Directory::CompositeIterator::CompositeIterator(const CompositeIterator& rhs) : iters_stack(rhs.iters_stack), pCurrentNode(rhs.pCurrentNode)
{
}

Directory::CompositeIterator  Directory::CompositeIterator::operator++(int)
{
   CompositeIterator tmp(*this);
   this->operator++();
   return tmp; 
}

bool Directory::CompositeIterator::operator==(const CompositeIterator& rhs)
{
  // This will return 'true' for an end iterator where its pCurrentNode is 0.
   return  iters_stack.empty() && pCurrentNode == rhs.pCurrentNode;
}

bool Directory::CompositeIterator::operator!=(const CompositeIterator& rhs) 
{
    return !operator==(rhs);
}
*/


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

// Since destructor is virtual, this will trigger a recursive descent
Directory::~Directory()
{
  list<Node*>::iterator list_iter     = nodeList.begin();
  list<Node*>::iterator list_iter_end = nodeList.end();

  for (;list_iter != list_iter_end; ++list_iter) { 
  
     delete *list_iter; 
  }   
}

/*
  This prints in-order. Thus, if dir1 and dir2 were added to top before top_f1, the output will look like
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
    
    /*
    while (iter_current.hasNext()) {
        
          Node *pNode = iter_current.next();
          
          cout << pNode->getName(); 
          
          if (dynamic_cast<Directory*>(pNode) ) {
              
             cout << " is a Directory ";
              
          } else {
              
              cout << " is a File ";
          }
          
          cout << endl;
       
    }
     */ 
}

// debug version prefixes address

void Directory::print_debug(ostream& ostr) const
{
//--    ostr << "[address: " << this << "] " << getName() << "\n";

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
    
    /*                       
    while (iter_current.hasNext()) {
        
          Node *pNode = iter_current.next();
          
          cout << "[address: " << pNode << "] " << pNode->getName(); 
          
          if (dynamic_cast<Directory*>(pNode) ) {
              
             cout << " is a Directory ";
              
          } else {
              
              cout << " is a File ";
          }
          
          cout << endl;
           
    }
    */ 
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
               
         } else { // output file name preceeded by path
             
            // cout << path << *pNode << endl; 
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
/*--
Directory::DirectoryIterator& Directory::DirectoryIterator::operator=(const DirectoryIterator& rhs)
{
  pCurrentNode = rhs.pCurrentNode;
  pDirectory = rhs.pDirectory;        
  iters_stack = rhs.iters_stack; 
  return *this;
}
*/

bool Directory::DirectoryIterator::operator==(const DirectoryIterator& rhs) const
{
 /*
  * This will return 'true' for an end iterator where its pCurrentNode is 0.
  */
   return  iters_stack.empty() && pCurrentNode == rhs.pCurrentNode;
}

bool Directory::DirectoryIterator::operator!=(const DirectoryIterator& rhs) const
{
    return !operator==(rhs);
}


Node *Directory::DirectoryIterator::operator->() const
{
  if (!iters_stack.empty()) {

     return pCurrentNode;
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
              /* pCurrentNode was set to "this" in ctor. We need to always first dereference the list iterator before
               * advancing it. */
              
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

Directory::ConstDirectoryIterator::ConstDirectoryIterator() : pDirectory(0), pCurrentNode(0), iters_stack()
{
}        

Directory::ConstDirectoryIterator::ConstDirectoryIterator(const ConstDirectoryIterator& rhs) : pDirectory(rhs.pDirectory), pCurrentNode(rhs.pCurrentNode),
        iters_stack(rhs.iters_stack) 
{
} 

Directory::ConstDirectoryIterator::ConstDirectoryIterator(const Directory& dir) : pDirectory(&dir)
{
    pCurrentNode = pDirectory; // correct?
    iters_stack.push(make_pair(dir.nodeList.begin(), dir.nodeList.end()) );
}

Directory::ConstDirectoryIterator& Directory::ConstDirectoryIterator::operator=(const ConstDirectoryIterator& rhs)
{
  pCurrentNode = rhs.pCurrentNode;
  pDirectory = rhs.pDirectory;

  iters_stack = rhs.iters_stack; 
  return *this;
}

bool Directory::ConstDirectoryIterator::operator==(const ConstDirectoryIterator& rhs) const
{
   if (pDirectory == rhs.pDirectory && pCurrentNode == rhs.pCurrentNode) {

      return true;
      
   } else {

      return false;
   }   
}

bool Directory::ConstDirectoryIterator::operator!=(const ConstDirectoryIterator& rhs) const
{
    return true;
}


/*
const Node *Directory::ConstDirectoryIterator::operator *() const
{
  if (!iters_stack.empty()) {

      return  *(iters_stack.top().first);
  } 
}
*/

const Node &Directory::ConstDirectoryIterator::operator *() const
{
    //////
    
  return *pCurrentNode;
/*  
  if (!iters_stack.empty()) {
      return **(iters_stack.top().first);
  } 
 */ 
    
}

const Node *Directory::ConstDirectoryIterator::operator->() const
{
  if (!iters_stack.empty()) {

      //return  *(iters_stack.top().first);
      return pCurrentNode;
  } 
}
//Directory::iterator  Directory::ConstDirectoryIterator::operator++() 
Directory::ConstDirectoryIterator&  Directory::ConstDirectoryIterator::operator++() 
{
  if (!iters_stack.empty()) {
      
     list<Node *>::const_iterator list_iter     = iters_stack.top().first; 
     list<Node *>::const_iterator list_iter_end = iters_stack.top().second; 
     iters_stack.pop();

     if (list_iter != list_iter_end) { 
        
        /*
         * The ctor sets pCurrentNode to this->pDirectory. Therefore we have yet to visit the first node of this->nodeList. So we advance the iterator
         * after setting pCurrentNode.
         * Question: Is list_iter just a local variable and there differs from the iterator on the stack? Maybe I really need a reference to
         * the iterator on the stack.
         */ 
        pCurrentNode = *list_iter; 
        ++list_iter; // <-- local variable. bug?

        if (dynamic_cast<const Directory *>(pCurrentNode)) { 

            // If Directory, push its nodeList iterators onto stack
            const Directory *pDir = static_cast<const Directory *>(*list_iter);
            
            iters_stack.push( make_pair(pDir->nodeList.begin(), pDir->nodeList.end()) );
        }  

     } else {

        // The stack is not empty, but we done iterating the of the current directory.
        // To resume processing the directory immediately above, we simply make a recursive call.
         this->ConstDirectoryIterator::operator++(); 
     }

  } else {

     // stack is empty and there is nothing to return
     pCurrentNode = 0;
  }
  return *this;
}

Directory::ConstDirectoryIterator  Directory::ConstDirectoryIterator::operator++(int) //postfix
{
   ConstDirectoryIterator temp(*this); 
   
   ++*this;
   
   return temp;
}

/*
void Directory::DescendNoStack() //const
{
  string path = "./";
  
  stack< pair< list<Node *>::iterator, list<Node *>::iterator> >  iters_stack;
  
  iters_stack.push(make_pair(nodeList.begin(), nodeList.end()) );

  while(!iters_stack.empty()) {
      
     pair< list<Node *>::iterator, list<Node *>::iterator >  top = iters_stack.top(); 
     iters_stack.pop();
     
     list<Node *>::iterator list_iter     = top.first; 
     list<Node *>::iterator list_iter_end = top.second; 
 
    //string dir_name = pdir->getName();
     string dir_name = (*list_iter)->getName();
                
     path += dir_name + string("/");
        
     cout << path << "\n";

     for (;list_iter != list_iter_end; list_iter++) {

        Node *pNode = *list_iter;
      
        if (dynamic_cast<Directory *>(pNode)) {

            // If Directory, push it onto stack
            Directory *pDir = static_cast<Directory *>(pNode);
            
            iters_stack.push( make_pair(pDir->nodeList.begin(), pDir->nodeList.end()) );
            
        } else { // output file name preceeded by path
          
            cout << path << *pNode << endl; 
        }   
     }
  } 
}
*/

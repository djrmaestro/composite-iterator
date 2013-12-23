/* 
 * File:   main.cpp
 * Author: kurt
 *
 * Created on December 12, 2013, 10:10 AM
 */

#include <cstdlib>
#include <string>
#include "File.h"
#include "Directory.h"
#include <iostream>

using namespace std;

void do_nothing(Node *p)
{
    
}

void do_something(Node *p)
{
    
}

int main(int argc, char** argv) 
{
    
    try {
        
        File *ptop_f1 = new File(string("top-File1"), string("12-12-2013"));
        
        File *ptop_f2  = new File(string("top-File2"), string("12-10-2013"));
        
        Directory top(string("top-level-dir"), string("12-09-2013"));
        
        top.add(ptop_f1);
        top.add(ptop_f2);
        
        Directory *psubdir1 = new Directory(string("first subdir"), string("12-10-2013"));
        
        Directory *psubdir2 = new Directory(string("second subdir"), string("12-10-2013"));
        
        File  *psubdir2_f1 = new File(string("subdir2-File1"), string("12-12-2013"));
        
        File  *psubdir2_f2 = new File(string("subdir2-File2"), string("12-10-2013"));
        
        psubdir2->add(psubdir2_f1);
        psubdir2->add(psubdir2_f2);
              
        psubdir1->add(psubdir2);
   
        File  *psubdir1_f1 = new File(string("subdir1-File1"), string("12-12-2013"));
        
        File  *psubdir1_f2 = new File(string("subdir1-File2"), string("12-10-2013"));
     
        psubdir1->add(psubdir1_f1);
        psubdir1->add(psubdir1_f2);
   
        top.add(psubdir1);

        top.print(cout); // print top level directory infor
         
        // print children info
        Directory::CompositeIterator  iter_current = top.begin_composite(); 
                               
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
        /*    
        for (;iter_current != iter_end; ++iter_current) {
            
              Node &node = *iter_current;
              Node *pNode = &node;
              
              cout << node.getName(); 
              
              if (dynamic_cast<Directory*>(pNode) ) {
                  
                 cout << " is a Directory ";
                  
              } else {
                  
                  cout << " is a File ";
              }
              
              cout << endl;
        }
        */ 
        cout << "\n Doing top.traverse(do_nothing) " << endl;
        top.traverse(do_nothing);
  
          
    
    } catch (Node::UnsupportedOperationException& e) {
            
          cout <<  e.what();
    }
    
 
    return 0;
}


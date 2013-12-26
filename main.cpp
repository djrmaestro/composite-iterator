#include <cstdlib>
#include <string>
#include "File.h"
#include "Directory.h"
#include <iostream>

using namespace std;

void do_nothing(Node *p) { }

void do_something(Node *p) { }

int main(int argc, char** argv) 
{
    
    try {
        
        File *ptop_f1 = new File(string("top-File1"), string("12-12-2013"));
        
        File *ptop_f2  = new File(string("top-File2"), string("12-10-2013"));
        
        Directory top(string("top-level-dir"), string("12-09-2013"));
        
        top.add(ptop_f1);
        top.add(ptop_f2);
        
        Directory *psubdir_mid = new Directory(string("subdir-mid"), string("12-10-2013"));
        
        Directory *psubdir_lower = new Directory(string("subdir-lower"), string("12-10-2013"));
        
        File  *psubdir_lower_f1 = new File(string("subdir-lovwer-File1"), string("12-12-2013"));
        
        File  *psubdir_lower_f2 = new File(string("subdir-lower-File2"), string("12-10-2013"));
        
        psubdir_lower->add(psubdir_lower_f1);
        psubdir_lower->add(psubdir_lower_f2);
              
        psubdir_mid->add(psubdir_lower);
   
        File  *psubdir_mid_f1 = new File(string("subdir_mid-File1"), string("12-12-2013"));
        
        File  *psubdir_mid_f2 = new File(string("subdir-mide_File2"), string("12-10-2013"));
     
        psubdir_mid->add(psubdir_mid_f1);
        psubdir_mid->add(psubdir_mid_f2);
   
        top.add(psubdir_mid);

        top.print(cout); // print top level directory and its children
                      
        cout << "\n ============= \n" << endl;

        Directory::iterator iter_current = top.begin();
        Directory::iterator iter_end = top.end();

        for (;iter_current != iter_end; ++iter_current) {
            
              Node &node = *iter_current;
                                        
              cout <<  "[address: " << hex << &node << "] " << node.getName(); 
              
              if (dynamic_cast<Directory*>(&node) ) {
                  
                 cout << " is a Directory ";
                  
              } else {
                  
                  cout << " is a File ";
              }
              
              cout << endl;
        }
        
        cout << "\n ===== Testing Directory::const_iterator ===:==\n";
        
        const Directory& const_top = top;
        
        Directory::const_iterator const_iter_current = const_top.begin();
        Directory::const_iterator const_iter_end = const_top.end();

        for (;const_iter_current != const_iter_end; ++const_iter_current) {
            
              const Node &node = *const_iter_current;
                                        
              cout <<  "[address: " << hex << &node << "] " << node.getName(); 
              
              if (dynamic_cast<const Directory*>(&node) ) {
                  
                 cout << " is a Directory ";
                  
              } else {
                  
                  cout << " is a File ";
              }
              
              cout << endl;
        }
            
    } catch (Node::UnsupportedOperationException& e) {
            
          cout <<  e.what();
    }
    
 
    return 0;
}


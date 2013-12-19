void Directory::DescendNoStack() //const


template<typename F> void Directory::DescendNoStack(F f) //const
{
  string path = "./";
  
  stack< pair< list<Node *>::iterator, list<Node *>::iterator> >  iters_stack;
  
  iters_stack.push(make_pair(fileComponents.begin(), fileComponents.end()) );

  while(!iters_stack.empty()) {
      
     pair< list<Node *>::iterator, list<Node *>::iterator >  top = iters_stack.top(); 
     iters_stack.pop();
     
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
            
            iters_stack.push( make_pair(pDir->fileComponents.begin(), pDir->fileComponents.end()) );
            
        } else { // output file name preceeded by path
          
            cout << path << *pNode << endl; 
        }   
     }
  } 
}


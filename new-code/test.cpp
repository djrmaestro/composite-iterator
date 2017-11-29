string test("subdirA/subdirB/subdirC/subdirD/newDir");

void test_driver(const string& dir, const string& path)
{
   string sub_path = subpath(path); 

   if (sub_path.empty()) {

        // The time is hardcode for now
        cout << "Directory *pDir = new Directory(path, std::string("10/10/2013")); 

        pCurrent->adopt(pDir);
      
   } else {

      string name = head(path); 

      test_driver(sub_path);
     
   }
}

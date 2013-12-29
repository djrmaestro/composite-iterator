#ifndef filesyscmds_h_972394723
#define filesyscmds_h_972394723
#include <string>
#include "Node.h"
// See Pattern Hatching
std::string head(const string& full_path);
std::string subpath(const string);
void mkdir(Node *pCurrent, std::string path); 
#endif

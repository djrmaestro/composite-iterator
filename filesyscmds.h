#ifndef filesyscmds_h_897233834
#define filesyscmds_h_897233834
#include "Node.h"
#include <string>

std::string head(const std::string& full_path);
std::string subpath(const std::string& full_path);
Node *find(std::string& name, Node *pCurrent);
void mkdir(Node *pCurrent, const std::string& subdir_name);

#endif

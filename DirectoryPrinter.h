/* 
 * File:   DirectoryPrinter.h
 * Author: kurt
 *
 * Created on May 11, 2013, 8:21 PM
 */

#ifndef TREEPRINTER_H
#define	TREEPRINTER_H

#include <iosfwd>
#include <string>
#include <vector>

class Node; // forward reference

class DirectoryPrinter {
    
    std::ostream& coutref; // ok

    std::string directory_name;

    std::vector<int> path_component_lengths;

    int composite_depth;

    static const std::string directory_separator;
    
    DirectoryPrinter(const DirectoryPrinter& tp);

public:

    DirectoryPrinter(std::ostream& ostr);

    void print(Node *pNode, int depth, bool isDirectory);
};
#endif	/* TREEPRINTER_H */


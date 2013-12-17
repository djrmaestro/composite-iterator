/* 
 * File:   DirectoryPrinter.h
 * Author: kurt
 *
 * Created on May 11, 2013, 8:21 PM
 */

#ifndef TREEPRINTER_H
#define	TREEPRINTER_H

#include <iosfwd>

class DirectoryPrinter {
    
    std::ostream& coutref;
    std::string current_path;
    vector<int> lengths;
   //-- int prior_length; 
    static const std::string top;
    int depth;
    
    DirectoryPrinter(const DirectoryPrinter& tp);

public:
    DirectoryPrinter(std::ostream& ostr);
    void print(Node *pNode, int depth);
};
#endif	/* TREEPRINTER_H */


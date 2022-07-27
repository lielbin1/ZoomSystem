/*
 * spilBefore.h
 *
 *  Created on: Jan 6, 2021
 *      Author: ise
 */

#ifndef SPLITBEFORE_H_
#define SPLITBEFORE_H_
using namespace std;
#include <exception>

class splitBefore : public exception{
    virtual const char* what() const throw()
    {
        return "this room was split before";
    }
};




#endif /* SPLITBEFORE_H_ */

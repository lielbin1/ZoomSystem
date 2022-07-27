/*
 * idException.h
 *
 *  Created on: Jan 6, 2021
 *      Author: ise
 */

#ifndef IDEXCEPTION_H_
#define IDEXCEPTION_H_

using namespace std;
#include <exception>
class idException : public exception {

    virtual const char* what() const throw()
    {
        return "id doesn't exists";
    }

};


#endif /* IDEXCEPTION_H_ */

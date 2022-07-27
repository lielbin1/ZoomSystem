/*
 * invalidDetails.h
 *
 *  Created on: Jan 6, 2021
 *      Author: ise
 */

#ifndef INVALIDDETAILS_H_
#define INVALIDDETAILS_H_
using namespace std;
#include <exception>

class invalidDetails : public exception{
    virtual const char* what() const throw()
    {
        return "Please enter valid details";
    }
};




#endif /* INVALIDDETAILS_H_ */

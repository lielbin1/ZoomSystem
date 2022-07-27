/*
 * studentPermissions.h
 *
 *  Created on: Jan 6, 2021
 *      Author: ise
 */

#ifndef STUDENTPERMISSIONS_H_
#define STUDENTPERMISSIONS_H_


using namespace std;
#include <exception>
class studenPermissions : public exception {

    virtual const char* what() const throw()
    {
        return "this student don't have permission";
    }

};


#endif /* STUDENTPERMISSIONS_H_ */

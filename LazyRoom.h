/*
 * LazyRoom.h
 *
 *  Created on: Dec 29, 2020
 *      Author: ise
 */

#ifndef LAZYROOM_H_
#define LAZYROOM_H_

#include "Room.h"
#include<iostream>
class LazyRoom: public Room{
public:
	LazyRoom(int id);

	virtual~LazyRoom();
	virtual bool addLazyStudentToRoom(Student*);
	virtual bool addWorkerStudentToRoom(Student*);
	virtual bool addResponsibleStudentToRoom(Student*);


};





#endif /* LAZYROOM_H_ */

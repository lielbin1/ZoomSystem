/*
 * DiligentRoom.h
 *
 *  Created on: Dec 29, 2020
 *      Author: ise
 */

#ifndef WORKERROOM_H_
#define WORKERROOM_H_
#include "Room.h"
#include<iostream>
class WorkerRoom: public Room{
public:
	WorkerRoom(int id);

	virtual~WorkerRoom();
	virtual bool addLazyStudentToRoom(Student*);
	virtual bool addWorkerStudentToRoom(Student*);
	virtual bool addResponsibleStudentToRoom(Student*);


};

#endif /* WORKERROOM_H_ */

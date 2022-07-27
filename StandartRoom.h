/*
 * StandartRoom.h
 *
 *  Created on: Dec 29, 2020
 *      Author: ise
 */

#ifndef STANDARTROOM_H_
#define STANDARTROOM_H_

#include "Room.h"
#include<iostream>
class StandartRoom: public Room{
	//Room* RightRoom;
//	Room* LettRoom;


public:
	StandartRoom(int id);

	virtual~StandartRoom();
//	virtual bool addStudentToStandartRoom(Student* s);
//	virtual bool addStudentToLazyRoom(Student* s);
//	virtual bool addStudentToWorkerRoom(Student* s);

	virtual bool addLazyStudentToRoom(Student*);
	virtual bool addWorkerStudentToRoom(Student*);
	virtual bool addResponsibleStudentToRoom(Student*);


};


#endif /* STANDARTROOM_H_ */

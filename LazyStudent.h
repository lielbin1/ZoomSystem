/*
 * LazyStudent.h
 *
 *  Created on: Dec 29, 2020
 *      Author: ise
 */

#ifndef LAZYSTUDENT_H_
#define LAZYSTUDENT_H_

#include "Room.h"
#include "Student.h"

class LazyStudent: public Student{
public:
	LazyStudent();
	LazyStudent(string firstname, string lastname, int id, int avg);
	virtual ~LazyStudent();
	virtual bool addStudentToLazyRoom(Room* room);
	virtual bool addStudentToWorkerRoom(Room* room);
	virtual bool addStudentToStandartRoom(Room* room);
	virtual void sendmessagefromstudent(string message, Room* r);
	void workstudent();
	virtual void Crying();

};


#endif /* LAZYSTUDENT_H_ */

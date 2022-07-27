/*
 * ResponsibleStudent.h
 *
 *  Created on: Dec 30, 2020
 *      Author: ise
 */

#ifndef RESPONSIBLESTUDENT_H_
#define RESPONSIBLESTUDENT_H_
#include "Student.h"
#include "Room.h"

class ResponsibleStudent: public Student{
public:
	ResponsibleStudent();
	ResponsibleStudent(string firstname, string lastname, int id, int avg);
	virtual ~ResponsibleStudent();


	virtual bool addStudentToLazyRoom(Room* room);
	virtual bool addStudentToWorkerRoom(Room* room);
	virtual bool addStudentToStandartRoom(Room* room);
	virtual void sendmessagefromstudent(string message, Room* r);
	virtual void Crying();
	void workstudent();

};





#endif /* RESPONSIBLESTUDENT_H_ */

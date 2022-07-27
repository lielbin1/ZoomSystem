/*
 * DiligentStudent.h
 *
 *  Created on: Dec 29, 2020
 *      Author: ise
 */

#ifndef WORKERSTUDENT_H_
#define WORKERSTUDENT_H_
#include "Student.h"
class Room;
#include <string>
//#include <vector>
//#include <iostream>
//#include"Room.h"
using namespace std;
class WorkerStudent: public Student{
public:
	WorkerStudent();
	WorkerStudent(string firstname, string lastname, int id, int avg):Student(firstname,lastname,id,avg){}
	virtual ~WorkerStudent();
	virtual bool addStudentToLazyRoom(Room* room);
	virtual bool addStudentToWorkerRoom(Room* room);
	virtual bool addStudentToStandartRoom(Room* room);
	virtual void sendmessagefromstudent(string message, Room* r);
	virtual void Crying();
	void workstudent();

};


#endif /* WORKERSTUDENT_H_ */

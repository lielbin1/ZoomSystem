/*
 * Room.h
 *
 *  Created on: Dec 29, 2020
 *      Author: ise
 */

#ifndef ROOM_H_
#define ROOM_H_
#include <vector>
#include "Student.h"
class Student;
#include <string.h>
#include <iostream>
using namespace std;

class Room {

protected:
//	static int numOfRooms;
	int room_id;
	int num_of_room_dad;
	vector<Student*>studentArray;
	bool splitedOrNot;
	vector<Room*>leftright;
public:

	Room(int id);
	virtual ~Room();
	virtual bool removeStudentfromRoom(int id);
	virtual void printRoom();
	virtual void addstudentanyway(Student* s);
	virtual bool getStatusofslip();
	virtual bool addLazyStudentToRoom(Student*)=0;
	virtual bool addWorkerStudentToRoom(Student*)=0;
	virtual bool addResponsibleStudentToRoom(Student*)=0;
	int getid();

	virtual void split(Room* room_right ,Room* room_left ,int type);
	virtual vector<Student*> getStudentVector();
	virtual vector<Room*> getleftrightVector();
	void set_num_of_room_dad(int rid);
	int get_num_of_room_dad();
	//void assignStudentfromroom(Room* r);

};



#endif /* ROOM_H_ */

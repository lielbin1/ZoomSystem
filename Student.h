/*
 * Student.h
 *
 *  Created on: Dec 29, 2020
 *      Author: ise
 */

#ifndef STUDENT_H_
#define STUDENT_H_

#include"Room.h"
class Room;
#include <string>
#include <vector>
#include <iostream>
#include <exception>
#include "idException.h"
#include "invalidDetails.h"
#include "studentPermissions.h"
#include "splitBefore.h"
using namespace std;

class Student {
protected:
	std::string s_firstname;
	std::string s_lastname;
	int s_avg;
	int s_id;
	vector<string>messages;
	int id_room;

public:

	Student(string firstname, string lastname, int id,int avg);
	Student();
	virtual ~Student();
	virtual int getid();
	virtual int getroomid();
	virtual void setroomid(int rid);
	virtual void printStudentDetails();
	virtual void printStudent();
	virtual void Crying()=0;
	virtual bool addStudentToLazyRoom(Room* room)=0;
	virtual bool addStudentToWorkerRoom(Room* room)=0;
	virtual bool addStudentToStandartRoom(Room* room)=0;
	virtual void sendmessagefromstudent(string s, Room* r)=0;
	virtual void newmessage(string message,string firstnameofsender,string lastnameofsender);
	virtual void workstudent()=0;
	void setnewRoomLoby();
};


#endif /* STUDENT_H_ */

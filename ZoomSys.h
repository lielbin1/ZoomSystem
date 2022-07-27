/*
 * ZoomSys.h
 *
 *  Created on: Dec 31, 2020
 *      Author: ise
 */

#ifndef ZOOMSYS_H_
#define ZOOMSYS_H_
#include <iostream>
#include <vector>
//#include <queue>
//#include <algorithm>
#include <string>
#include "Room.h"
#include "Student.h"
#include "LazyStudent.h"
#include "WorkerStudent.h"
#include "WorkerRoom.h"
#include "StandartRoom.h"
#include "LazyRoom.h"
#include <fstream> // for read files
#include "ResponsibleStudent.h"
#include "idException.h"
#include "invalidDetails.h"
#include "studentPermissions.h"
#include "splitBefore.h"

class ZoomSys{
private:


vector<Room*> afterdelete;
vector<Student*> Allstudent;
vector<Room*> AllRoom;
int NumOfCreateRoom;
//int find_room(nt id){
//
//}

public:
	ZoomSys();
	virtual ~ZoomSys();
	ZoomSys(const char* path);
	void addRoomFromFile(string arr[2]);
	void addStudentFromFile(string arr[6]);
	void printStudents();
	bool printStudentDetails();
	bool printRooms();
	void addRoom();
	void addStudent();
	bool find_Student(int id);
	void removeStudent();
	void splitRoom();
	void sendMessage();
	void assignStudent();
	void assignStudentHelpFunc(int sid , int rid);
	Room* getRoom(int id);
	Room* getRoomByID(int id);
	Student* getStudentById(int id);
	void work();
	void removeRoom();
	void removesubroom(Room* r);
	void removeroomfromvector(Room* r);
	void assignStudentfromroom(Room* rFrom, Room* rTo);
	void removeStudentfromsys(int id);



};
#endif /* ZOOMSYS_H_ */

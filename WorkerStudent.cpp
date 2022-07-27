/*
 * WorkerStudent.cpp
 *
 *  Created on: Dec 29, 2020
 *      Author: ise
 */


#include "WorkerStudent.h"


WorkerStudent::WorkerStudent()
{

}
//:Student(firstName,lastName,id,avg){}



WorkerStudent::~WorkerStudent()
{

}

bool WorkerStudent::addStudentToLazyRoom(Room* room){
	return false;
}
bool WorkerStudent::addStudentToWorkerRoom(Room* room){
	if(room!=NULL){
		this->id_room=room->getid();
		return room->addWorkerStudentToRoom(this);
	}

}

bool WorkerStudent::addStudentToStandartRoom(Room* room){
	return false;

}

void WorkerStudent::Crying(){

}
void WorkerStudent::sendmessagefromstudent(string message, Room* r)
{
	try
			{
					throw studenPermissions();

			}
			catch(exception &e)
			{
				cout<<e.what()<<endl;
			}
}


void WorkerStudent::workstudent(){
	cout<<this->s_firstname<<" "<<this->s_lastname<<" is working"<<endl;
}



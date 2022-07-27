/*
 * WorkerRoom.cpp
 *
 *  Created on: Dec 29, 2020
 *      Author: ise
 */

#include "WorkerRoom.h"
WorkerRoom::WorkerRoom(int id):Room(id){

}
WorkerRoom::~WorkerRoom(){

}

bool WorkerRoom::addLazyStudentToRoom(Student* s){}

bool WorkerRoom::addWorkerStudentToRoom(Student* s){
	if(s!=NULL)
	{
		//s->addStudentToWorkerRoom(this);
		studentArray.push_back(s);
		return true;
	}
	return false;
}
bool WorkerRoom::addResponsibleStudentToRoom(Student* s){}


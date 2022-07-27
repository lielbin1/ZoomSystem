/*
 * LazyRoom.cpp
 *
 *  Created on: Dec 29, 2020
 *      Author: ise
 */

#include "LazyRoom.h"
LazyRoom::LazyRoom(int id):Room(id){

}
LazyRoom::~LazyRoom(){

}

bool LazyRoom::addResponsibleStudentToRoom(Student* s){
	if(s!=NULL)
		return false;

}

bool LazyRoom::addLazyStudentToRoom(Student* s){
	if(s!=NULL)
	{
		studentArray.push_back(s);
		return true;
	}
		return false;
}
bool LazyRoom::addWorkerStudentToRoom(Student* s){

if(s!=NULL)
{
	return false;
}

}




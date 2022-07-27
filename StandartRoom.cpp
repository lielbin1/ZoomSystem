/*
 * StandartRoom.cpp
 *
 *  Created on: Dec 29, 2020
 *      Author: ise
 */


#include "StandartRoom.h"


StandartRoom::StandartRoom(int id):Room(id){

}
StandartRoom::~StandartRoom(){

}



bool StandartRoom::addResponsibleStudentToRoom(Student* s){
		if(s!=NULL)
		{
			studentArray.push_back(s);
			return true;
		}
		return false;

}

bool StandartRoom::addLazyStudentToRoom(Student* s){
	if(s!=NULL){
		return false;
	}
}

bool StandartRoom::addWorkerStudentToRoom(Student* s){

	if(s!=NULL)
	{
		return false;
	}
}



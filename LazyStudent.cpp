/*
 * LazyStudent.cpp
 *
 *  Created on: Dec 29, 2020
 *      Author: ise
 */




#include "LazyStudent.h"



LazyStudent::LazyStudent(string firstname, string lastname , int id, int avg):Student(firstname,lastname,id,avg){}

LazyStudent::~LazyStudent(){}



bool LazyStudent::addStudentToLazyRoom(Room* room){
	if(room!=NULL){
		this->id_room=room->getid();
		return room->addLazyStudentToRoom(this);
	}

}


bool LazyStudent::addStudentToWorkerRoom(Room* room){
	return false;
}

bool LazyStudent::addStudentToStandartRoom(Room* room){
	return false;
}
void LazyStudent::Crying(){
	cout<<this->s_firstname<<" "<<this->s_lastname<<" is crying"<<endl;

}
void LazyStudent::sendmessagefromstudent(string message, Room* r){
	try
			{
				throw studenPermissions();

			}
			catch(exception &e)
			{
				cout<<e.what()<<endl;
			}

}


void LazyStudent::workstudent(){

}

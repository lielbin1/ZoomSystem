/*
 * ResponsibleStudent.cpp
 *
 *  Created on: Dec 30, 2020
 *      Author: ise
 */
#include "Student.h"
#include <iostream>
using namespace std;
#include "ResponsibleStudent.h"

//:Student(firstname,lastname,id,avg){}

ResponsibleStudent::ResponsibleStudent(string firstname, string lastname , int id, int avg):Student(firstname,lastname,id,avg){}

ResponsibleStudent::~ResponsibleStudent(){}

bool ResponsibleStudent::addStudentToLazyRoom(Room* room){
	return false;
}
void ResponsibleStudent::Crying(){

}

bool ResponsibleStudent::addStudentToWorkerRoom(Room* room){
	return false;

}


bool ResponsibleStudent::addStudentToStandartRoom(Room* room){
	return false;

}

void ResponsibleStudent::sendmessagefromstudent(string message, Room* r){
	if(r==NULL)
	{
		return;
	}
	vector<Student*> t;
	t=r->getStudentVector();
	vector<Student*>::iterator it;
	for (it = t.begin(); it!=t.end(); it++)
	{
		(*it)->newmessage(message,this->s_firstname,this->s_lastname);
	}

}
void ResponsibleStudent::workstudent(){

}


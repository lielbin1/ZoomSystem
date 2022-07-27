/*
 * Student.cpp
 *
 *  Created on: Dec 29, 2020
 *      Author: ise
 */

#include <iostream>
#include <iomanip>
#include "Room.h"
#include <string>
#include "Student.h"

Student::Student(){}


Student::Student(string firstname, string lastname, int id,int avg)
{
	this->s_avg=avg;
	this->s_firstname=firstname;
	this->s_lastname=lastname;
	this->s_id=id;
	this->id_room=-1;
	//this->messages.push_back("kgtfffff fvm");


}

int Student::getid(){
	return this->s_id;
}


Student::~Student() {
	//this->messages.clear();
}//Destractor


void Student::printStudent(){
	cout<<this->s_firstname<<" "<<this->s_lastname<<" "<<this->s_id<<" "<<this->s_avg<<" "<<this->id_room<<"\n";
}

void Student::printStudentDetails()
{
	cout<<this->s_firstname<<" "<<this->s_lastname<<" "<<this->s_id<<" "<<this->s_avg<<" "<<this->id_room<<"\n---Messages---\n";
	vector<string>::iterator it;
	for (it = messages.begin(); it!=messages.end(); ++it){
		cout<<*it<<"\n";
	}
}

//void getmessage()


void Student::newmessage(string message,string firstnameofsender,string lastnameofsender){

	this->messages.push_back(firstnameofsender+" "+lastnameofsender+":"+message);
}


int Student::getroomid(){
	return this->id_room;
}

void Student::setroomid(int rid){
	this->id_room=rid;
}
void Student::setnewRoomLoby(){
	this->id_room=-1;
}



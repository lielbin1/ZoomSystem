/*
 * Room.cpp
 *
 *  Created on: Dec 29, 2020
 *      Author: ise
 */


#include <iostream>
#include <iomanip>
#include "Room.h"
#include <vector>
#include "Student.h"

//int Room::numOfRooms=-1;


Room::~Room(){
//	vector<Student*>::iterator itStu;
//	for(itStu= this->studentArray.begin();itStu!=this->studentArray.end();++itStu)
//	{
//			delete *itStu;
//	}
//	this->studentArray.clear();
//	vector<Room*>::iterator itr;
//	for(itr= this->leftright.begin();itr!=this->leftright.end();++itr)
//	{
//			delete *itr;
//	}
//	this->leftright.clear();


}

Room::Room(int id)
{
	this->room_id=id;
	this->splitedOrNot=false;
	this->num_of_room_dad=-1;

}

void Room::set_num_of_room_dad(int rid){
	this->num_of_room_dad=rid;
}

void Room::printRoom(){
	cout<<"room id:"<<this->room_id<< ", students:"<<this->studentArray.size()<<endl;

}
int Room::get_num_of_room_dad(){
	return this->num_of_room_dad;
}



bool Room::removeStudentfromRoom(int id){
	int index=-1;
	//Student* s;
	vector<Student*>::iterator it;

	for(it = studentArray.begin(); it!=studentArray.end(); ++it){
		index++;
				if((*it)->getid()==id){
					//(*it)->Crying();

					studentArray.erase(studentArray.begin()+index);
					break;
				}
	}

	return true;
}


bool Room::getStatusofslip(){
	return this->splitedOrNot;
}



int Room::getid(){
	return this->room_id;
 }



void Room::split(Room* room_left ,Room* room_right ,int type){


	if (this->splitedOrNot){
			cout<<"This room was split before"<<endl;
	}
	else
	{
		this->leftright.push_back(room_left);
		this->leftright.push_back(room_right);
		this->splitedOrNot=true;


		if (type == 1 )
		{
			//int size=room->studentArray.size()/2;
			int size = this->studentArray.size();
			vector<Student*> vec2;
			for(int i=0; i < size;i++)
			{
				vec2.push_back(this->studentArray[i]);
				//(this->studentArray[i])->setroomid(room_left->room_id);
			}
			int index =-1;
			vector<Student*>::iterator it;   //lazy
				for(it = vec2.begin(); it!=vec2.end(); ++it)
				{
					index++;
					if((*it)->addStudentToWorkerRoom(room_left))
					{
						this->studentArray.erase(this->studentArray.begin()+index);
						index--;

					}

					if((*it)->addStudentToLazyRoom(room_right))
					{
						this->studentArray.erase(this->studentArray.begin()+index);
						index--;
					}

				}

		}
		if (type==2)
		{

			vector<Student*>::iterator it;
			int size=this->studentArray.size();
			int halfsize=this->studentArray.size()/2;
			for(int i = 0; i<halfsize; i++)
			{

			room_left->studentArray.push_back(this->studentArray[i]);
			this->studentArray[i]->setroomid(room_left->room_id);
			//this->studentArray.erase((this->studentArray.begin()+i));

			}

			for(int i = halfsize; i < size; i++)
			{
				room_right->studentArray.push_back(this->studentArray[i]);
				this->studentArray[i]->setroomid(room_right->room_id);
				//this->studentArray.erase((this->studentArray.begin()+i));

			}

			this->studentArray.clear();
		}
	}
}

vector<Student*> Room::getStudentVector(){
//	if(!(this->studentArray)){
//		return NULL;
//	}
	return this->studentArray;
}

vector<Room*> Room::getleftrightVector(){
	return this->leftright;
}

void Room::addstudentanyway(Student* s){
	this->studentArray.push_back(s);
	s->setroomid(this->room_id);
}



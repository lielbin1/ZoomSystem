/*
 * ZoomSys.cpp
 *
 *  Created on: Dec 31, 2020
 *      Author: ise
 */
#include <iostream>
#include <iomanip>
#include "Room.h"
#include <string>
#include"ZoomSys.h"


//using namespace std;




ZoomSys::ZoomSys(){
	NumOfCreateRoom=0;
}



//ZoomSys::~ZoomSys();
ZoomSys::ZoomSys(const char* path){

    string token;
    ifstream inFile;
    inFile.open(path);
   // int t;
    if (!inFile) {
        cerr << "Unable to open file ";
        exit(1);   // call system to stop
    }
//    while(getline(inFile,token)){
//    	t= toke.find
//    }
    string Student[5];
    while (inFile >> token)
    { // still have text in file:

            Student[0] = token;
            for (int i = 1; i < 5; ++i) { // init the students data array with the information
                inFile >> Student[i];
            }
            // call to addStudentFromFile function
            addStudentFromFile(Student);
        }


    inFile.close();
}


void ZoomSys::addStudentFromFile(string arr[5]) {
    string firstName, lastName, S_T;
    int avg,id;
    Student *s;

    // init data from arr when arr holds - firstName,lastName,id,power,Republican/Democrat,Leader/Social
    firstName = arr[0];
    lastName = arr[1];
    id = atoi(arr[2].c_str());
    //id = stoi(arr[2]);
    avg = atoi(arr[3].c_str());
    //power = stoi(arr[3]);
    S_T = arr[4];
    // creating new politician:
    // check if R or D
    if(S_T=="R")
    {/// Responsible student
        s=new ResponsibleStudent(firstName,lastName,id,avg);
        if(s== NULL)
        {
            abort();
        }
    }
    else if(S_T == "W")
    {/// WorkerStudent
        s=new WorkerStudent(firstName,lastName,id,avg);
        if(s==NULL)
        {
            abort();
        }

    }
    else
    {/// Lazy Student
        s=new LazyStudent(firstName,lastName,id,avg);
        if(s== NULL)
        {
            abort();
        }

    }

    Allstudent.push_back(s);

}

void ZoomSys::printStudents(){

	cout<<"First name, Last Name, ID, Avg, Room ID"<<endl;
	vector<Student*>::iterator it;
	for(it = this->Allstudent.begin(); it!=this->Allstudent.end(); ++it)
	{
		(*it)->printStudent();

	}

}

bool ZoomSys::printStudentDetails()
{
	bool check=false;
	int in;
	cout<<"Enter student id:\n";
	cin>>in;
	vector<Student*>::iterator it;
	for(it = this->Allstudent.begin(); it!=this->Allstudent.end(); ++it)
	{
		if((*it)->getid()==in)
		{
			(*it)->printStudentDetails();
			check=true;
			return true;
		}
	}


		try
		{
			if(check==false)
			{
				throw idException();
			}
		}
		catch(exception &e)
		{
			cout<<e.what()<<endl;
		}


}


bool ZoomSys::printRooms(){
	vector<Room*>::iterator it;
	for(it = this->AllRoom.begin(); it!=this->AllRoom.end(); ++it)
		{
			(*it)->printRoom();

		}
}

void ZoomSys::addRoom()
{

	int id=NumOfCreateRoom;
	StandartRoom *r=new StandartRoom(id);
	r->set_num_of_room_dad(-1);
	NumOfCreateRoom++;
	this->AllRoom.push_back(r);
	cout<<"New room created"<<endl;

}
//string firstname, string lastname, int id,int avg

void ZoomSys::addStudent(){
	string firstname,lastname,type;
	int id , avg;
		cout<<"---Create Student---\n";
		cout<<"First name:\n";
				cin>>firstname;
		cout<<"Last name:\n";
				cin>>lastname;
		cout<<"ID:\n";
				cin>>id;

		cout<<"avg:\n";
				cin>>avg;
		cout<<"Worker(W) or Lazy(L) or Responsible(R) Student?\n";
				cin>>type;
				if(find_Student(id)||(avg>100 || avg<0)||(type!="W" && type!="R" &&type!="L"))

				{
					try
					{
						throw invalidDetails();
					}
						catch(exception &e)
					{
						cout<<e.what()<<endl;
					}
				}
				else
				{

				Student *s;
				if(type=="R")
				{/// Responsible student
					s=new ResponsibleStudent(firstname,lastname,id,avg);

				}
				else if(type == "W")
				{/// WorkerStudent
					s=new WorkerStudent(firstname,lastname,id,avg);

				}
				else
				{
					s=new LazyStudent(firstname,lastname,id,avg);


				}
				Allstudent.push_back(s);


				}



}
bool ZoomSys::find_Student(int id){

	vector<Student*>::iterator it;
	for(it = this->Allstudent.begin(); it!=this->Allstudent.end(); ++it){
			if((*it)->getid()==id){
				return true;
			}
	}
	return false;

}


void ZoomSys::splitRoom(){

	int type,id;
	bool exist= false;
	cout<<"---Split Room---\n";
	cout<<"Room id:\n";
	cin>>id;

	vector<Room*>::iterator it;
	for(it = this->AllRoom.begin(); it!=this->AllRoom.end(); ++it)
	{
		if (exist==true){
			break;
		}
		if((*it)->getid()==id)
		{
			exist=true;
			if ((*it)->getStatusofslip()){
				try
					{
					throw splitBefore();
					}
				catch(exception &e)
					{
						cout<<e.what()<<endl;
					}

			}
			else
			{
				cout<<"1.Character split\n";
				cout<<"2.Size split\n";
				cin>>type;
				if (type != 1 && type != 2){
					try
						{
						  throw invalidDetails();
						}
						catch(exception &e)
						{
							cout<<e.what()<<endl;
						}

				}
				if(type ==1){

					Room* r1;
					r1= new WorkerRoom(NumOfCreateRoom);
					r1->set_num_of_room_dad(id);
					NumOfCreateRoom++;
					Room* r2;
					r2= new LazyRoom(NumOfCreateRoom);
					NumOfCreateRoom++;
					r2->set_num_of_room_dad(id);
					(*it)->split(r1, r2,type);
					this->AllRoom.push_back(r1);
					this->AllRoom.push_back(r2);


				}
				else if(type==2){

					Room* r1;
					r1= new StandartRoom(NumOfCreateRoom);
					r1->set_num_of_room_dad(id);
					NumOfCreateRoom++;
					Room* r2;
					r2= new StandartRoom(NumOfCreateRoom);
					NumOfCreateRoom++;
					r2->set_num_of_room_dad(id);
					(*it)->split(r1, r2,type);
					this->AllRoom.push_back(r1);
					this->AllRoom.push_back(r2);

				}

		}

	}

}
	if (exist==false)
	{
		try
			{
			throw idException();
			}

			catch(exception &e)
			{
				cout<<e.what()<<endl;
			}
	}
}

void ZoomSys::sendMessage(){
	int id;
	bool exist= false;
	string message;

	cout<<"Enter the id:\n";
	cin>>id;


	vector<Student*>::iterator it;
		for(it = this->Allstudent.begin(); it!=this->Allstudent.end(); ++it)
		{
			if (exist==true){
				break;
			}
			if((*it)->getid()==id)
			{

				exist=true;
				cout<<"Enter the message:\n";
				cin.ignore();
				getline(cin,message);


				//cin>>message;
				Room* r;
				r=this->getRoomByID((*it)->getroomid());
				(*it)->sendmessagefromstudent(message,r);

				if (this->getStudentById(id)->getroomid()==-1)
									{
									return;
									}
			}
		}
		if (exist==false)
			try
		{
			throw idException();
		}
		catch (exception &e)
		{
			cout<<e.what()<<endl;
		}


}



Room* ZoomSys::getRoom(int id){  //id of student

	vector<Room*>::iterator it;
	for(it = this->AllRoom.begin(); it!=this->AllRoom.end(); ++it)
	{
		if ((*it)->getStudentVector().size()==0)
		{
			continue;
			return NULL;
		}
		else
		{
			vector<Student*> r;
			r=(*it)->getStudentVector();
			vector<Student*>::iterator its;
			for(its=r.begin();  its!=r.end(); ++its)
			{
				if((*its)==NULL){
					return NULL;
				}

				if((*its)->getid()==id)
				{
					return (*it);
				}
			}
		}
	}

	return NULL;
}


Room* ZoomSys::getRoomByID(int id){ //id of room

	if (id==-1)
	{
		return NULL;
	}
	vector<Room*>::iterator it;
	for(it = this->AllRoom.begin(); it!=this->AllRoom.end(); ++it)
	{
//	Room* r;
//	r=;
		if((*it)==NULL)
		{
			continue;
		}
		if((*it)->getid()==id)
		{
			return (*it);
		}




	}
	return NULL;
}

Student* ZoomSys::getStudentById(int id){

	vector<Student*>::iterator it;
	for(it = this->Allstudent.begin(); it!= this->Allstudent.end(); ++it)
	{

			if((*it)->getid()==id)
			{
				return (*it);
			}

	}
	return NULL;

}

void ZoomSys::assignStudentHelpFunc(int sid , int rid){
	if(this->getRoom(sid))
	{

			//cout<<"gfgf";
		this->getRoom(sid)->removeStudentfromRoom(getRoom(sid)->getid());
	}
	if (getRoomByID(rid)&&(getStudentById(sid)))
	{

		getRoomByID(rid)->addstudentanyway(getStudentById(sid));
	}

	else

	{
		try
		{
		throw idException();
		}
		catch(exception &e)
		{
			cout<<e.what()<<endl;
		}
	}

}


void ZoomSys::assignStudent()
{
	int sid ,rid;
	cout<<"---Assign Student---\n";
	cout<<"Enter student id:\n";
	cin>>sid;
	cout<<"Enter room id:\n" ;
	cin>>rid;
	if(this->getStudentById(sid)==NULL||(this->getRoomByID(rid)==NULL)){
		try
		{
		throw idException();
		}
		catch(exception &e)
		{
			cout<<e.what()<<endl;
		}
	}
	else if(getRoom(sid)==getRoomByID(rid)){
		goto end;
	}
	else if (rid==-1)
		{
			this->getStudentById(sid)->setroomid(-1);
			this->getRoom(sid)->removeStudentfromRoom(sid);
		}
	else
	{
	getRoomByID(rid)->addstudentanyway(getStudentById(sid));
	//this->assignStudentHelpFunc(sid, rid);
	}
		end:
		{}


}


void ZoomSys::work(){
	int id;
	cout<<"Enter the room you want to work:"<<endl;
	cin>>id;
	if(this->getRoomByID(id))
	{
	Room* r;
		r=this->getRoomByID(id);
		vector<Student*> t;
		t=r->getStudentVector();
		vector<Student*>::iterator it;
		for(it = t.begin(); it!= t.end(); ++it)
		{
			(*it)->workstudent();
		}
	}
	else
	{
		try
				{
				throw idException();
				}
				catch(exception &e)
				{
					cout<<e.what()<<endl;
				}
	}

}


void ZoomSys::removeStudentfromsys(int id){
	int index=-1;
	Student* s;
	vector<Student*>::iterator it;
	for(it = this->Allstudent.begin(); it!=this->Allstudent.end(); ++it)
	{
		index++;
		if((*it)->getid()==id)
		{
			s=*it;
			this->Allstudent.erase(this->Allstudent.begin()+index);
			break;

		}

	}
	delete s;
}


void ZoomSys::removeStudent()
{
	Student* s;
	int id;
	cout<<"---Remove Student---"<<endl;
	cout<<"Enter the id:"<<endl;
	cin>>id;

		if(!(this->getStudentById(id)))
		{
			try
					{
					throw idException();
					}
					catch(exception &e)
					{
						cout<<e.what()<<endl;
					}
		}
		else
		{

			if(this->getRoom(id))
			{
				Room* r;
				r=this->getRoom(id);
				r->removeStudentfromRoom(id);
				this->removeStudentfromsys(id);
			}
			else
			{
				this->removeStudentfromsys(id);
			}

		//	delete getStudentById(id);
		}
}

void ZoomSys::removeroomfromvector(Room* r){
	if(r==NULL){
		return;
	}
	int index=-1;
	vector<Room*>::iterator it;
	for(it = this->AllRoom.begin(); it!=this->AllRoom.end(); ++it)
	{
		index++;
		if ((*it)->getid()==r->getid())
		{
			vector<Student*> vecs;
			vecs=r->getStudentVector();
			vector<Student*>::iterator its;
			for(its = vecs.begin(); its!=vecs.end(); ++its){
			(*its)->Crying();

			}

		//vector<Room*> afterdelete;

		this->afterdelete.push_back(r);
	//	delete (*it);
		this->AllRoom.erase(this->AllRoom.begin()+index);
		//this->AllRoom.begin()+index=nullptr;
		break;
		}

	}
	//r->getleftrightVector().clear();
}



void ZoomSys::removesubroom(Room* r){

	if (r->getleftrightVector().empty())
	{
		r->getleftrightVector().clear();
		this->assignStudentfromroom(r, this->getRoomByID(r->get_num_of_room_dad()));

		this->removeroomfromvector(r);
		return;
	}

		this->removesubroom((r->getleftrightVector())[0]);
		this->removesubroom((r->getleftrightVector())[1]);

	if(this->getRoomByID(r->get_num_of_room_dad())==NULL)
	{
		vector<Student*> vecs;
		vecs =r->getStudentVector();
		vector<Student*>::iterator it;
		for(it = vecs.begin(); it!=vecs.end(); ++it)
		{
			(*it)->setnewRoomLoby();

		}
	}
	r->getleftrightVector().clear();
	this->assignStudentfromroom(r, this->getRoomByID(r->get_num_of_room_dad()));
	this->removeroomfromvector(r);


}

void ZoomSys::removeRoom(){
	int rid;
 	int index=-1;
	cout<<"---Remove Room---"<<endl;
	cout<<"Enter room id:"<<endl;
	cin>>rid;
	Room* r;
	r=this->getRoomByID(rid);
	if(( r->get_num_of_room_dad()==-1) &&(r->getleftrightVector().empty()))
	{
		vector<Student*> vecs;
		vecs=r->getStudentVector();
		vector<Student*>::iterator its;
		for(its = vecs.begin(); its!=vecs.end(); ++its){
			(*its)->Crying();
			(*its)->setnewRoomLoby();
		}

		this->removeroomfromvector(r);
		vecs.clear();

	}
	else
	{

	vector<Room*>::iterator it;
		for(it = this->AllRoom.begin(); it!=this->AllRoom.end(); ++it)
		{

			index++;
			if((*it)->getid()==rid)
			{
				r=(*it);


				this->removesubroom(r);
				//delete r1;
				break;

			}

		}
		if (index==-1)
		{
			try
					{
					throw idException();
					}
					catch(exception &e)
					{
						cout<<e.what()<<endl;
					}
		}
	}
	//delete


}

void ZoomSys::assignStudentfromroom(Room* rFrom, Room* rTo){
	if(rTo==NULL)
	{
		vector<Student*> vecs;
		vecs =rFrom->getStudentVector();
		vector<Student*>::iterator it;
		for(it = vecs.begin(); it!=vecs.end(); ++it)
			{
				(*it)->setnewRoomLoby();

			}
	}
	else
	{

		vector<Student*> vecs;
		vecs =rFrom->getStudentVector();
		vector<Student*>::iterator it;
		for(it = vecs.begin(); it!=vecs.end(); ++it)
		{
			this->assignStudentHelpFunc((*it)->getid(), rTo->getid());
		}
	}

}

ZoomSys::~ZoomSys(){

	vector<Room*>::iterator itRoo;
		for(itRoo= this->AllRoom.begin();itRoo!=this->AllRoom.end();++itRoo)
			{
				delete *itRoo;
			}
		this->AllRoom.clear();
		vector<Room*>::iterator itdel;
				for(itdel= this->afterdelete.begin();itdel!=this->afterdelete.end();++itdel)
					{
						delete *itdel;
					}
				this->afterdelete.clear();

	vector<Student*>::iterator itStu;
	for(itStu= this->Allstudent.begin();itStu!=this->Allstudent.end();++itStu)
	{
		delete *itStu;
	}
	this->Allstudent.clear();


}



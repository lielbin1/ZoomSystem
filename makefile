output.exe: LazyRoom.o LazyStudent.o main.o ResponsibleStudent.o Room.o StandartRoom.o WorkerRoom.o Student.o WorkerStudent.o ZoomSys.o
	g++ -o output.exe LazyRoom.o LazyStudent.o main.o ResponsibleStudent.o Room.o StandartRoom.o WorkerRoom.o Student.o WorkerStudent.o ZoomSys.o

LazyRoom.o: LazyRoom.cpp 
	g++ -c LazyRoom.cpp

LazyStudent.o: LazyStudent.cpp 
	g++ -c LazyStudent.cpp

main.o: main.cpp
	g++ -c main.cpp
	
ResponsibleStudent.o: ResponsibleStudent.cpp 
	g++ -c ResponsibleStudent.cpp
		
Room.o: Room.cpp 
	g++ -c Room.cpp

StandartRoom.o: StandartRoom.cpp 
	g++ -c StandartRoom.cpp
		
WorkerRoom.o: WorkerRoom.cpp 
	g++ -c WorkerRoom.cpp

Student.o: Student.cpp 
	g++ -c Student.cpp
	
WorkerStudent.o: WorkerStudent.cpp 
	g++ -c WorkerStudent.cpp
	
ZoomSys.o: ZoomSys.cpp 
	g++ -c ZoomSys.cpp
	
clean :
	rm *.o


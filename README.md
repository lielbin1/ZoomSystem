# A system that simulates Zoom video software

The system has rooms and students.
When students can perform actions according to their type.
There are 3 types of students and each type has its own characteristics:
- A diligent student works when the room he belongs to receives a work order.
- A lazy student complains every time he has to change rooms.
- A responsible student is able to send a broadcast message to all students who are in the room with him (compared to other students who cannot send messages at all, only receive).


Architecture:

* **Student** - every student has a first name, last name, thesis, average. In addition, he saves the messages he received during his stay in the system. There are three different types of students:
- A diligent student - every time the room works, he announces that he is working.
- A lazy student - every time his room is cleaned, he complains.
- Responsible student - capable of sending broadcast messages to all members of the room.
There are no 2 students with the same ID number.


* **Room** - each room has an ID number and contains the students in it.
There are three types of rooms in the system:
- Standard room - a room that every student is capable of being.
- Diligent room - The seven creation room holds only diligent students.
- Lazy Room - The seven created room holds only lazy students





Deleting a room - when a room is deleted, all sub-rooms related to it are also deleted.

Print room - a function that prints the details of the room: room ID and number of students


## Functionality that the system supports -
***Initializing the system*** - the system is created with no rooms at all and all the students in the input file are added to it.

***Adding a student to the system***

***Removing a student from the system***

***Adding a student to the room***

***Adding a room to the system***

***Splitting a room*** - there are 2 different types of splitting: 

- **Splitting according to character:** 2 chambers are created (the left chamber is hardworking, and the right is lazy)
The students are transferred to the room according to their character when in this type of split
A responsible student remains in the split room.
- **Splitting according to quantity:** 2 standard rooms are created and the students are divided into rooms
It is done in the order of their addition to the current room, half of the students
Those who joined the room first will move to the left room, and the other half to the right.
For example, if there are 9 students in the room, then after the split there are 4 students
The old ones will belong to the left chamber and the 5 new ones to the right chamber (if there is an island number).
The right room double will be larger.
After this split, no students remain in the room split up

***Deleting a room***

***Work*** - the system receives a room ID from the user and informs all students to work there. After the announcement, every diligent student in the requested room announces that he is working. If the room is not in the system (room ID does not exist) an exception id error will be thrown.

***Sending a message*** - a function that receives from the user a student ID and a message, and if the student is responsible, the student will send the message to all students in the same room.

***Display all rooms***

***Display all Students***

***Display  student details***

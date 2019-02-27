#pragma once
#include "user.h"

class socialNetwork {
	user *sUser;
	vector<user*> uList;
public:
	socialNetwork() { }
	~socialNetwork() { }
	void addUser(string name);
	void deleteUser(string name);
	user* getUser(string name);
	set<unsigned long>searchUserByName(string name);
	set<unsigned long>searchUserByAge(unsigned int age);
	set<unsigned long>searchUserByHobbies(set<string> hobbies);
	set<unsigned long>getFriendsOfUser(user *fuser);
	void addFriend(user *ouser, user *fuser);
	void printAllUsers();

};

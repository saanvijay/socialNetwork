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
	set<unsigned long>serchUserByName(string name);
	set<unsigned long>serchUserByAge(unsigned int age);
	set<unsigned long>serchUserByHobbies(set<string> hobbies);
	set<unsigned long>getFriendsOfUser(user *fuser);
	void addFriend(user *ouser, user *fuser);
	void printAllUsers();

};

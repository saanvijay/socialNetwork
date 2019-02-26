#pragma once
#include "user.h"

class socialNetwork {
	user *sUser;
	vector<user*> uList;
public:
	socialNetwork() { }
	~socialNetwork() { }
	void addUser(user *nUser);
	void deleteUser(user *oUser);
	set<long long int>serchUserByName(string name);
	set<long long int>serchUserByAge(unsigned int age);
	set<long long int>serchUserByHobbies(set<string> hobbies);
	set<long long int>getFriendsOfUser(user *fuser);
	void addFriend(user *ouser, user *fuser);
	void printAllUsers();

};

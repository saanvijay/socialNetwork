#pragma once
#include "user.h"

class socialNetwork {
	user *sUser;
	vector<user*> uList;
public:
	socialNetwork() { }
	~socialNetwork() { }
	socialNetwork(const socialNetwork &) = delete;
	socialNetwork& operator=(const socialNetwork &) = delete;
	socialNetwork(socialNetwork &&) = delete;
	socialNetwork& operator=(socialNetwork &&) = delete;
	void addUser(string name);
	void deleteUser(string name);
	user* getUser(string name);
	user* getUser(unsigned long id);
	set<unsigned long>searchUserByName(string name);
	set<unsigned long>searchUserByAge(unsigned int age);
	set<unsigned long>searchUserByHobbies(set<string> hobbies);
	set<unsigned long>getFriendsOfUser(user *fuser);
	set<user*>getFriendsOfUser(set<unsigned long>);
	void addFriend(user *ouser, user *fuser);
	void printAllUsers();
	void notify(user*);
};

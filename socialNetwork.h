#pragma once
#include "user.h"

class socialNetwork {
	shared_ptr<user> sUser;
	vector<shared_ptr<user>> uList;
public:
	socialNetwork() { }
	~socialNetwork() { }
	socialNetwork(const socialNetwork &) = delete;
	socialNetwork& operator=(const socialNetwork &) = delete;
	socialNetwork(socialNetwork &&) = delete;
	socialNetwork& operator=(socialNetwork &&) = delete;
	void addUser(string name);
	void deleteUser(string name);

	shared_ptr<user> getUser(string name);
	shared_ptr<user> getUser(unsigned long id);
	set<unsigned long>searchUserByName(string name);
	set<unsigned long>searchUserByAge(unsigned int age);
	set<unsigned long>searchUserByHobbies(set<string> hobbies);
	set<unsigned long>getFriendsOfUser(shared_ptr<user> fuser);
	void addFriend(shared_ptr<user> ouser, shared_ptr<user> fuser);

	void printAllUsers();
	void notify(shared_ptr<user>);
};

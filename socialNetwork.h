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
<<<<<<< HEAD
	shared_ptr<user> getUser(string name);
	set<unsigned long>searchUserByName(string name);
	set<unsigned long>searchUserByAge(unsigned int age);
	set<unsigned long>searchUserByHobbies(set<string> hobbies);
	set<unsigned long>getFriendsOfUser(shared_ptr<user> fuser);
	void addFriend(shared_ptr<user> ouser, shared_ptr<user> fuser);
=======
	user* getUser(string name);
	user* getUser(unsigned long id);
	set<unsigned long>searchUserByName(string name);
	set<unsigned long>searchUserByAge(unsigned int age);
	set<unsigned long>searchUserByHobbies(set<string> hobbies);
	set<unsigned long>getFriendsOfUser(user *fuser);
	set<user*>getFriendsOfUser(set<unsigned long>);
	void addFriend(user *ouser, user *fuser);
>>>>>>> 88ac488b2a980bcd2e7fa7a851cee7e31278af1b
	void printAllUsers();
	void notify(user*);
};

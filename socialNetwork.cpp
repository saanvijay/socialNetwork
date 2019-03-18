#include "socialNetwork.h"
#include <algorithm> // std::remove will not work unless you declare algorithm header
#include <memory>
#include <iostream>
using namespace std;

shared_ptr<user> socialNetwork::getUser(string name) {
	for (auto &l : uList) {
		if (l->getUserName() == name) return l;
	}
}

shared_ptr<user> socialNetwork::getUser(unsigned long id) {
	for (auto &l : uList) {
		if (l->getUserId() == id) return l;
	}
}

void socialNetwork::addUser(string name) {

	if (name == "") {
		cout << "Application can't create user profile for empty string" << endl;
		return;
	}

	auto auser = make_shared<user>();
	auser->setUserName(name);

	string gender;
	cout << "Enter Gender for " << name << endl;
	getline(cin, gender);
	auser->setUserGender (gender);

	int age;
	cout << "Enter age for " << name << endl;
	cin >> age;
	auser->setUserAge (age);

	int nheight;
	cout << "Enter height for " << name << endl;
	cin >> nheight;
	auser->setUserHeight(nheight);

	vector<string> nhobbies;
	
	string h;
	while(1) {
		static int i=0;
		h="";

		if(i) cin.get();
		cout << "Enter hobbies for " << name << endl;
		getline(cin,h);
		nhobbies.push_back(h);
		i++;

		cout << "More hobbies for " << name <<" (y/n)" << endl;
		char c;
		cin >> c;
		if (c == 'y' || c == 'Y') continue;
		else break;
	}
	auser->setUserHobbies(nhobbies);
	uList.push_back(auser);
}


void socialNetwork::deleteUser(string name) {
	uList.erase(std::remove(uList.begin(), uList.end(), getUser(name)), uList.end());
}

void socialNetwork::printAllUsers() {
	// If no users in the network, just exit
	if (uList.empty()) {
		cout << "No users in the network" << endl;
		return;
	}

	cout << endl << "User Details" << endl;
	cout << "-------------------------------" << endl;
	for (auto &l : uList) {
		cout << "UserId   : " << l->getUserId()  << endl;
		cout << "Name     : " << l->getUserName()  << endl;
		cout << "Gender   : " << l->getUserGender()  << endl;
		cout << "Age      : " << l->getUserAge() << endl;
		cout << "Height   : " << l->getUserHeight() << endl;
		cout << "myFeed   : " << l->getUserFeed() << endl;
		cout << "FFeed    : " << l->getFriendsFeed() << endl;
		
		auto uh = l->getUserHobbies();
		if (!uh.empty()) cout << "Hobbies  : ";
		for (auto &h : uh){
			cout << h <<" " ;
			
		}
		cout <<endl<<endl;
	}		
}

set<unsigned long>socialNetwork::searchUserByName(string name) {
	set<unsigned long> ids;
	for (auto &l : uList) {
		if (l->getUserName() == name) { ids.insert(l->getUserId());}
	}
	return ids;

}

set<unsigned long>socialNetwork::searchUserByAge(unsigned int age) {
	set<unsigned long> ids;
	for (auto &l : uList) {
		if (l->getUserAge() == age) { ids.insert(l->getUserId());}
	}
	return ids;
}
set<unsigned long>socialNetwork::searchUserByHobbies(set<string> hobbies) {
	set<unsigned long> ids;
	for (auto &l : uList) {
		for(auto &h : l->getUserHobbies()) {
			for (auto &hv :hobbies) {
				if (hv == h) ids.insert(l->getUserId());
			}
		}
	}
return ids;
}


set <unsigned long>socialNetwork::getFriendsOfUser(shared_ptr<user> fuser)	 {
	return fuser->getFriendsList();
}

set<shared_ptr<user>>socialNetwork::getFriendsOfUser(set <unsigned long> fUser)	 {
	set <shared_ptr<user>> uList;
	for (auto &userid : fUser) {
		uList.insert(getUser(userid));
	}
	return uList;
}

void socialNetwork::addFriend(shared_ptr<user> ouser, shared_ptr<user> fuser) {	
	ouser->getFriendsList().insert(fuser->getUserId());
}


void socialNetwork::notify(shared_ptr<user> sUser) {
		auto userIdList = sUser->getFriendsListId();
		auto userList = getFriendsOfUser(userIdList);
		for (auto &singleUserId : userIdList) {
			auto eachFriend = getUser(singleUserId);
			eachFriend->setFriendsFeed(sUser->getUserFeed());
		}
}

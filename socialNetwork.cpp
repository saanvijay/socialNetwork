#include "socialNetwork.h"
#include <algorithm> // std::remove will not work unless you declare algorithm header
#include <memory>
#include <iostream>
using namespace std;

user* socialNetwork::getUser(string name) {
	for (auto &l : uList) {
		if (l->getUserName() == name) return l;
	}
}

void socialNetwork::addUser(string name) {

	if (name == "") {
		cout << "Application can't create user profile for empty string" << endl;
		return;
	}

	user *auser = new user;
	auser->setUserName(name);

	string gender;
	cout << "Enter Gender for " << name << endl;
	cin >> gender;
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
	
	while(1) {
		string h;
		char c;
		cout << "Enter hobbies for " << name << endl;
		cin >> h;
		nhobbies.push_back(h);
		cout << "More hobbies for " << name <<" (y/n)" << endl;
		cin >> c;
		if (c == 'n' || c == 'N') break;
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
		auto uh = l->getUserHobbies();
		if (!uh.empty()) cout << "Hobbies  : ";
		for (auto &h : uh){
			cout << h <<" " ;
			
		}
		cout <<endl<<endl;
	}		
}

set<unsigned long>socialNetwork::serchUserByName(string name) {
	set<unsigned long> ids;
	for (auto &l : uList) {
		if (l->getUserName() == name) { ids.insert(l->getUserId());}
	}
	return ids;

}

set<unsigned long>socialNetwork::serchUserByAge(unsigned int age) {
	set<unsigned long> ids;
	for (auto &l : uList) {
		if (l->getUserAge() == age) { ids.insert(l->getUserId());}
	}
	return ids;
}
set<unsigned long>socialNetwork::serchUserByHobbies(set<string> hobbies) {
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

set <unsigned long>socialNetwork::getFriendsOfUser(user *fuser)	 {
	return fuser->getFriendsList();
	}

void socialNetwork::addFriend(user *ouser, user *fuser) {	
	ouser->getFriendsList().insert(fuser->getUserId());
}
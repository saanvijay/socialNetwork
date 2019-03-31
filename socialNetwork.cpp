#include "socialNetwork.h"
#include <algorithm> // std::remove will not work unless you declare algorithm header
#include <memory>
#include <iostream>
using namespace std;

shared_ptr<user> socialNetwork::getUser(string name) {
	for (auto &usr : uList) {
		if (usr->getUserName() == name) return usr;
	}
}

shared_ptr<user> socialNetwork::getUser(unsigned long id) {
	for (auto &usr : uList) {
		if (usr->getUserId() == id) return usr;
	}
}

void socialNetwork::addUser(string name) {
	static int i=0;
	if(i) cin.get();

	if (name == "") {
		cout << "Application can't create user profile for empty string" << endl;
		return;
	}

	auto auser = make_shared<user>();
	auser->setUserName(name);

	string gender;
	cout << "Enter Gender for " << name << endl;
	getline(cin, gender);

	int age;
	cout << "Enter age for " << name << endl;
	cin >> age;


	cin.get();

	string feed;
	cout << "Enter feed for " << name << endl;
	getline(cin, feed);

	int nheight;
	cout << "Enter height for " << name << endl;
	cin >> nheight;

	vector<string> nhobbies;
	
	while(1) {
		static int i=0;
		string h="";

		cin.get();

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
	auser->setUserGender (gender);
	auser->setUserAge (age);
	auser->setUserHeight(nheight);
	auser->setUserHobbies(nhobbies);
	auser->setUserFeed(feed);
	notify(auser);
	uList.push_back(auser);
	i++;
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
	for (auto &usr : uList) {
		cout << "UserId   : " << usr->getUserId()  << endl;
		cout << "Name     : " << usr->getUserName()  << endl;
		cout << "Gender   : " << usr->getUserGender()  << endl;
		cout << "Age      : " << usr->getUserAge() << endl;
		cout << "Height   : " << usr->getUserHeight() << endl;
		cout << "myFeed   : " << usr->getUserFeed() << endl;
		cout << "FFeed    : " << usr->getFriendsFeed() << endl;
		
		auto uh = usr->getUserHobbies();
		if (!uh.empty()) cout << "Hobbies  : ";
		for (auto &h : uh){
			cout << h <<" " ;
			
		}
		cout <<endl<<endl;
	}		
}

set<unsigned long>socialNetwork::searchUserByName(string name) {
	set<unsigned long> ids;
	for (auto &usr : uList) {
		if (usr->getUserName() == name) { ids.insert(usr->getUserId());}
	}
	return ids;

}

set<unsigned long>socialNetwork::searchUserByAge(unsigned int age) {
	set<unsigned long> ids;
	for (auto &usr : uList) {
		if (usr->getUserAge() == age) { ids.insert(usr->getUserId());}
	}
	return ids;
}
set<unsigned long>socialNetwork::searchUserByHobbies(set<string> hobbies) {
	set<unsigned long> ids;
	for (auto &usr : uList) {
		for(auto &h : usr->getUserHobbies()) {
			for (auto &hv :hobbies) {
				if (hv == h) ids.insert(usr->getUserId());
			}
		}
	}
return ids;
}


set<shared_ptr<user>>socialNetwork::getFriendsOfUser(shared_ptr<user> fuser)	 {
	return fuser->getFriendsList();
}

/*set<shared_ptr<user>>socialNetwork::getFriendsOfUser(set <unsigned long> fUser)	 {
	set <shared_ptr<user>> uList;
	for (auto &userid : fUser) {
		uList.insert(getUser(userid));
	}
	return uList;
}*/

void socialNetwork::addFriend(shared_ptr<user> ouser, shared_ptr<user> fuser) {	
	ouser->getFriendsList().insert(fuser);
}


void socialNetwork::notify(shared_ptr<user> sUser) {
		auto userIdList = sUser->getFriendsListId();
		auto userList = getFriendsOfUser(sUser);
		for (auto &singleUser : userIdList) {
			auto eachFriend = getUser(singleUser);
			eachFriend->setFriendsFeed(sUser->getUserFeed());
		}
}

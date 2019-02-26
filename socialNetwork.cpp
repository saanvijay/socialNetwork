#include "socialNetwork.h"
#include <algorithm> // std::remove will not work unless you declare algorithm header

class user;
long long int user::_userId = 0;

void socialNetwork::addUser(user *auser) {

	string aname;
	cout << "Enter user name" << endl;
	cin >> aname;
	if (aname == "") { cout << "User name can't be empty" << endl; return;}
	auser->setUserName(aname);

	int age;
	cout << "Enter user age" << endl;
	cin >> age;
	auser->setUserAge (age);

	int nheight;
	cout << "Enter user height" << endl;
	cin >> nheight;
	auser->setUserHeight(nheight);

	vector<string> nhobbies;
	
	while(1) {
		string h;
		char c;
		cout << "Enter user hobbies" << endl;
		cin >> h;
		nhobbies.push_back(h);
		cout << "More hobbies (y/n)" << endl;
		cin >> c;
		if (c == 'n' || c == 'N') break;
	}
	auser->setUserHobbies(nhobbies);
	uList.push_back(auser);
}


void socialNetwork::deleteUser(user *auser) {
	uList.erase(std::remove(uList.begin(), uList.end(), auser), uList.end());
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

set<long long int>socialNetwork::serchUserByName(string name) {
	set<long long int> ids;
	for (auto &l : uList) {
		if (l->getUserName() == name) { ids.insert(l->getUserId());}
	}
	return ids;

}

set<long long int>socialNetwork::serchUserByAge(unsigned int age) {
	set<long long int> ids;
	for (auto &l : uList) {
		if (l->getUserAge() == age) { ids.insert(l->getUserId());}
	}
	return ids;
}

set <long long int>socialNetwork::getFriendsOfUser(user *fuser)	 {
	return fuser->getFriendsList();
	}

void socialNetwork::addFriend(user *ouser, user *fuser) {
		
	ouser->getFriendsList().insert(fuser->getUserId());
}




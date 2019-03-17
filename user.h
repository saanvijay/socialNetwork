#pragma once
#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <memory>
using namespace std;

class user {
	unsigned long _userId = 0;
	string _name;
	int _age;
	int _height;
	string _gender;
	vector<string> _hobbies;
	set<decltype(_userId)> _fList;
	set<shared_ptr<user>> _fLists;
	string _myFeed;
	string _myFriendsFeed;

public:
	user() { 
		auto id = [] () { static unsigned long i=0; i++; return i;};
		_userId = id(); 
		}
	user(const user& rhs) {
		_userId = rhs._userId;
		_name = rhs._name;
		_age = rhs._age;
		_gender = rhs._gender;
		_height = rhs._height;
		_hobbies = rhs._hobbies;
		_fList = rhs._fList;
		_myFeed = rhs._myFeed;
		_myFriendsFeed = rhs._myFriendsFeed;
	}
	user& operator =(const user& rhs) {
		if (this != &rhs) {
			_userId = rhs._userId;
			_name = rhs._name;
			_age = rhs._age;
			_gender = rhs._gender;
			_height = rhs._height;
			_hobbies = rhs._hobbies;
			_fList = rhs._fList;
			_myFeed = rhs._myFeed;
			_myFriendsFeed = rhs._myFriendsFeed;
		}
		return *this;
	}
	user(user &&)= delete;
	user& operator=(user &&) = delete;

	void setUserName(string aname) { _name = aname;}
	void setFriendsFeed(string feed) { _myFriendsFeed = feed; }
	void setUserFeed(string feed) { _myFeed = feed;}
	void setUserGender(string agender) { _gender = agender;}
	void setUserAge (auto nage) { _age = nage; }
	void setUserHeight(auto nheight) { _height = nheight; }
	void setUserHobbies(vector<string> &uhobbies) { _hobbies = uhobbies ; }
	
	string getUserFeed() { return _myFeed;}
	string getFriendsFeed() { return _myFriendsFeed; }
	string getUserName() { return _name;}
	string getUserGender() { return _gender;}
	auto getUserAge () { return _age; }
	auto getUserHeight() { return _height; }
	auto getUserHobbies() { return _hobbies; }
	decltype(_userId) getUserId() { return _userId; }
	set<decltype(_userId)> getFriendsListId() { return _fList; }
	auto getFriendsList() { return _fLists; }
};

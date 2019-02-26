#pragma once
#include <iostream>
#include <string>
#include <set>
#include <list>
#include <vector>
using namespace std;

class user {
	static long long int _userId;
	string _name;
	int _age;
	int _height;
	vector<string> _hobbies;
	set<decltype(_userId)> _fList;
public:
	user() { _userId++;}
	user(const user& rhs) {
		_userId = rhs._userId;
		_name = rhs._name;
		_age = rhs._age;
		_height = rhs._height;
		_hobbies = rhs._hobbies;
		_fList = rhs._fList;
	}
	user& operator =(const user& rhs) {
		if (this != &rhs) {
			_userId = rhs._userId;
			_name = rhs._name;
			_age = rhs._age;
			_height = rhs._height;
			_hobbies = rhs._hobbies;
			_fList = rhs._fList;
		}
		return *this;
	}
	user(user &&)= delete;
	user& operator=(user &&) = delete;

	void setUserName(string aname) { _name = aname;}
	void setUserAge (auto nage) { _age = nage; }
	void setUserHeight(auto nheight) { _height = nheight; }
	void setUserHobbies(vector<string> &uhobbies) { _hobbies = uhobbies ; }

	string getUserName() { return _name;}
	auto getUserAge () { return _age; }
	auto getUserHeight() { return _height; }
	auto getUserHobbies() { return _hobbies; }
	decltype(_userId) getUserId() { return _userId; }
	set<decltype(_userId)> getFriendsList() { return _fList; }
};



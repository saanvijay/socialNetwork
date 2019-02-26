#include <iostream>
using namespace std;

#include "socialNetwork.h"



int main() {

	socialNetwork *s = new socialNetwork;

	user *newUser = new user;
	s->addUser(newUser);

	user *newUser1 = new user;
	s->addUser(newUser1);

	s->printAllUsers();

	auto nlist = s->serchUserByName("vijay");
	for (auto &l : nlist) cout <<" user ids name" << l <<endl;

	auto alist = s->serchUserByAge(23);
	for (auto &l : alist) cout <<" user ids age" << l <<endl;


	s->deleteUser(newUser);
	s->printAllUsers();

	s->deleteUser(newUser1);
	s->printAllUsers();

	delete(s);
	
return 0;
}

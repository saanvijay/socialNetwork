#include <iostream>
using namespace std;

#include "socialNetwork.h"



int main() {

	socialNetwork *s = new socialNetwork;

	
	s->addUser("vijay");
	s->addUser("prakash");

	s->printAllUsers();

	auto nlist = s->serchUserByName("vijay");
	for (auto &l : nlist) cout <<"UserId's for Name search : " << l <<endl;

	auto alist = s->serchUserByAge(23);
	for (auto &l : alist) cout <<"UserId's for Age search : " << l <<endl;

	auto hlist = s->serchUserByHobbies({"swimming"});
	for (auto &l : hlist) cout <<"UserId's for Hobbies search : " << l <<endl;

	s->deleteUser("vijay");
	s->printAllUsers();

	s->deleteUser("prakash");
	s->printAllUsers();

	delete(s);
	
return 0;
}

#include <iostream>
#include <memory>
using namespace std;

#include "socialNetwork.h"



int main() {

	auto s = make_unique<socialNetwork>();

	s->addUser("vijay");
	s->addUser("prakash");

	s->printAllUsers();

	auto nlist = s->searchUserByName("vijay");
	for (auto &l : nlist) cout <<"UserId's for Name search : " << l <<endl;

	auto alist = s->searchUserByAge(23);
	for (auto &l : alist) cout <<"UserId's for Age search : " << l <<endl;

	auto hlist = s->searchUserByHobbies({"swimming"});
	for (auto &l : hlist) cout <<"UserId's for Hobbies search : " << l <<endl;

	s->deleteUser("vijay");
	s->printAllUsers();

	s->deleteUser("prakash");
	s->printAllUsers();
	
return 0;
}

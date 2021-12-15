#ifndef SYSTEM_H
#define SYSTEM_H
#include<vector>
#include<string>
#include<iostream>
#include "post.h"
#include "user.h"
using std::vector;
using std::string;
class System
{
private:
	string name;
	User* currentUser;
	vector<Post*> posts;
	vector<User*> users;
public:
	System(string);
	~System();
	bool signUpUser(string,string);
	bool signInUser(int,string);
	void signOutUser();
	bool addPost(string,int,string,int);
	bool processFollow(string ,string,int,int);
	bool processUnFollow(string,string,int,int);
	void final_output();
	int getIdFromUserName(string);
	User* getUserFromId(int);
	Post* getPostFromId(int);
	User* getCurrentUser();
	User getUserObjectFromId(int);
	Post getPostObjectFromId(int);
};
#endif
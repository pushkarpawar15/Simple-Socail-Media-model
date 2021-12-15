#include "user.h"
#include <iostream>
using namespace std;
User::User(string name,string password)//construtor
{
	this->name = name;
	this->password = password;
	id = count++;
}

//get methods
int User::getId()
{
	return id;
}
string User::getName()
{
	return name;
}
int User::getNumberOfFollowers()
{
	return followings.size();
}
int User::getNumberOfPosts()
{
	return posts.size();
}


void User::addFollowing(User* f)//adds user to followings list
{
	followings.push_back(f);
}
int User::count = 1; //static int to keep track of ids


void User::addPost(Post* p)//adding post of posts list
{
	posts.push_back(p);
}
bool User::removeFollower(User* u) //method for unfollow
{
	int i=0;
	while (followings.size())
	{
		if(followings[i]==u) break;
		i++;
		if(i>=followings.size()) return false;
	}
	if(followings.size()) followings.erase(followings.begin()+i);
	else return false;
	return true;
}
bool User::validatePassword(string s) //return true if password matches for that user
{
	if(s.compare(password)) return false;
	else return true;
}
std::ostream & operator << (std::ostream& x,User user) //overloading << 
{
	x << "User Id: " << user.getId() << ", User Name: " << user.getName() << ", Number of Posts: " << user.getNumberOfPosts() << ", Following Count: " << user.getNumberOfFollowers() <<"\n";
	return x;
}
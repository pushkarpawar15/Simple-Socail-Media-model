#include<iostream>
#include"system.h"
using namespace std;
System::System(string n) //constructor
{
	name = n;
}
System::~System() //destructor
{
	posts.clear();
	users.clear();
}

bool System::signUpUser(string name,string password) //method to add user in users list
{
	for (int i = 0; i < users.size(); i++)
	{
		if(!users[i]->getName().compare(name))
		{
			return false;
		}
	}
	
	User* user = new User(name,password);
	users.push_back(user);
	return true;
}

//method to add post , return false if user does not exits (checked by validationId)
bool System::addPost(string postUsername,int yearOfPost,string contentOfPost,int validationId)
{
	for (int i = 0; i < users.size(); i++) //getting required user for the list
	{
		if(users[i]->getId()==validationId)
		{
			Post* post = new Post(users[i]->getId(),contentOfPost,yearOfPost);
			posts.push_back(post);
			users[i]->addPost(post);
			return true;
		}
	}
	return false;
}
//method for FOLLOW query
bool System::processFollow(string following,string followed,int followingValidationId,int followedValidationId)
{
	bool flag1 = false,flag2 = false;
	int followingpos=0,followedpos=0; //stores position of required User objects from users list

	//For loops for getting the above positions
	for (int i = 0; i < users.size(); i++)
	{
		if(users[i]->getId()==followingValidationId) //checking if user exists in the list
		{
			followingpos = i;
			flag1 = true;
			break;
		}
	}
	for (int i = 0; i < users.size(); i++)
	{
		if(users[i]->getId()==followedValidationId) //checking if user exists in the list
		{
			followedpos = i;
			flag2 = true;
			break;
		}
	}

	//checking if both users exists and performing follow operation
	if((flag1==true) && (flag2==true))
	{
		users[followingpos]->addFollowing(users[followedpos]);
		return true;
	}
	return false; //if user not exists


}

//Similar to processFollow ,just calling removefollower instead of addfollower method
bool System::processUnFollow(string username,string userUnFollow,int userValidationId,int userUnfollowValidationId)
{
	bool flag1 = false,flag2 = false;
	int usernamepos=0,unfollowpos=0;
	for (int i = 0; i < users.size(); i++)
	{
		if(users[i]->getId()==userValidationId)
		{
			usernamepos = i;
			flag1 = true;
			break;
		}
	}
	for (int i = 0; i < users.size(); i++)
	{
		if(users[i]->getId()==userUnfollowValidationId)
		{
			unfollowpos = i;
			flag2 = true;
			break;
		}
	}
	if((flag1==true) && (flag2==true))
	{
		return users[usernamepos]->removeFollower(users[unfollowpos]);
	}
	return false;


}

//Function to getId correspoinding to username
int System::getIdFromUserName(string user)
{
	for(int i=0;i<users.size();i++)
	{
		if(users[i]->getName()==user) return users[i]->getId();
	}
	return -1;
}

bool System::signInUser(int userId,string password)
{
	bool flag = false;
	User* user;
	for (int i = 0; i < users.size(); i++) //loop to get user corresponding to id.
	{
		if(users[i]->getId()==userId)
		{
			user = users[i];
			flag = true;
			break;
		}
	}
	if(user->validatePassword(password))
	{
		currentUser = user;
		return true;
	}else return false;	
}

void System::signOutUser()
{
	currentUser = NULL;
}

//getters
User* System::getUserFromId(int id)
{
	for (int i = 0; i < users.size(); i++)
	{
		if(users[i]->getId() == id) return users[i];
	}
	return NULL;
}
Post* System::getPostFromId(int id)
{
	for (int i = 0; i < posts.size(); i++)
	{
		if(posts[i]->getId()==id) return posts[i];
	}
	return NULL;
}
User* System::getCurrentUser()
{
	return currentUser;
}

User System::getUserObjectFromId(int id)
{
	return *(this->getUserFromId(id));
}
Post System::getPostObjectFromId(int id)
{
	return *(this->getPostFromId(id));
}
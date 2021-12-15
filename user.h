#ifndef USER_H
#define USER_H
#include<vector>
#include<string>
#include "post.h"
using std::vector;
using std::string;
class User
{
private:
	int id;
	string password;
	static int count;
	string name;
	vector<User*> followings;
	vector<Post*> posts;
public:
	User(string name,string password);
	int getId();
	void addPost(Post*);
	void addFollowing(User*);
	bool removeFollower(User*);
	void printAllFollowing();
	void printAllPosts();
	bool validatePassword(string s);
	int getNumberOfFollowers();
	int getNumberOfPosts();
	string getName();
	friend std::ostream & operator << (std::ostream& ,User );
};
#endif
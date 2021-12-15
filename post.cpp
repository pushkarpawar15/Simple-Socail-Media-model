#include"post.h"
#include<iostream>
int Post::count = 1;
Post::Post(int pui,string con,int yop)//constructor
{
	postUserId = pui;
	content = con;
	yearOfPost = yop;
	id = count++;
}
//get methods
int Post::getYearOfPosting()
{
	return yearOfPost;
}
int Post::getId()
{
	return id;
}
int Post::getUserId()
{
	return postUserId;
}
string Post::getContent()
{
	return content;
}
std::ostream & operator <<(std::ostream& x,Post post) //overloading <<
{
	x << "Post Id: " << post.getId() <<", User Id: " << post.getUserId() <<", Year: "<<post.getYearOfPosting() <<", Post Content:"<<post.getContent()<<"\n";
	return x;
}
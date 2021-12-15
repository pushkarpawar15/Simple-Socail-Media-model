#ifndef POST_H
#define POST_H
#include<string>
using std::string;
class Post
{
private:
	int id;
	static int count;
	int postUserId;
	string content;
	int yearOfPost;
public:
	Post(int pui,string con,int yop);
	int getYearOfPosting();
	int getId();
	int getUserId();
	string getContent();
	friend std::ostream & operator <<(std::ostream& ,Post );
};
#endif
#include<iostream>
#include"system.h"
using namespace std;
int main()
{
	string s,a,b,y,z;
	cin >> s;//input
	while(s.compare("CREATE"))//checking for valid input
	{
		if(!(s.compare("EXIT"))) return 0;
		cin >> s;
		cout <<"Invalid Input" << endl;
	}
	cin >> a;
	System *sys = new System(a);//creating system object
	cout << a << endl;
	int id;
	while (true)//Taking inputs until EXIT
	{
		cin >> s;
		if(!(s.compare("SIGNUP")))
		{
			cin >> y >> z;
			bool val = sys->signUpUser(y,z);//creates user with password
			if(!val) cout <<"Access Denied"<<endl;
		}
		else if(!(s.compare("SIGNIN")))
		{
			bool val;
			cin >> y;
			cin >> z;
			if(sys->getIdFromUserName(y)>=0) val = sys->signInUser(sys->getIdFromUserName(y),z); //checks if user exists and signs him in.
			else val = false;
			if(!val) cout <<"Access Denied"<<endl;
		}
		else if(!(s.compare("SIGNOUT")))
		{
			sys->signOutUser();
		}
		else if(!(s.compare("PRINTUSER")))
		{
			cin >> id;
			if(sys->getUserFromId(id)) cout << sys->getUserObjectFromId(id);
			else cout << "Invalid Input" << endl;
		}
		else if(!(s.compare("PRINTPOST")))
		{
			cin >> id;
			if(sys->getPostFromId(id)) cout << sys->getPostObjectFromId(id);
			else cout << "Invalid Input" << endl;
		}
		else if(!(s.compare("FOLLOW")))//input for follow 
		{
			cin >> y;
			bool val;
			if(sys->getCurrentUser()) val = sys->processFollow(sys->getCurrentUser()->getName(),y,sys->getCurrentUser()->getId(),sys->getIdFromUserName(y));//calling method to follow
			else val = true;
			if(!val) cout <<"Invalid Input"<<endl;
		}
		else if(!(s.compare("UNFOLLOW"))) //UNFOLLOW query
		{
			cin >> y;
			bool val;
			if(!sys->getCurrentUser())
			{
				cout <<"Access Denied" <<endl;
				continue;
			}
			if(sys->getIdFromUserName(y)) val = sys->processUnFollow(sys->getCurrentUser()->getName(),y,sys->getCurrentUser()->getId(),sys->getIdFromUserName(y));//calling method to unfollow
			else val = true;
			if(!val) cout <<"Invalid Input"<<endl;
		}
		else if(!(s.compare("POST"))) //Post query
		{
			bool flag = true;
			if(sys->getCurrentUser()) a = sys->getCurrentUser()->getName();
			else
			{
				cout << "Access Denied" << endl;
				getline(cin,z);
				continue;
			}
			int yr;
			string hello;
			cin >> yr;
			getline(cin,b);
			bool val = sys->addPost(a,yr,b,sys->getIdFromUserName(a));//calling post method in system
			if(val == false) cout << "Invalid Input\n"; //Output on invalid input or user does not exists
		}
		else if(!(s.compare("EXIT")))
		{
			delete sys;
			break;
		}
		else
		{
			getline(cin,s);
			cout << "Invalid Input" << endl; //output for invalid queries
		}
	}

}
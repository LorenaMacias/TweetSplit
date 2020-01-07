#ifndef TWITTER_HPP
#define TWITTER_HPP

#include <iostream>
#include <string>
using namespace std;

class Tweet{
	public: 
		string username, message;
		int charLength;

		Tweet(string user, string msg){
			username = user;
			message = msg;
			charLength = message.length();
		}
		
		//default tweet
		Tweet(){
			username = "";
			message = "";
			charLength = 0;
		}

		//getters and setters
		void setUsername(string u){
			username = u;
		}	
		string getUsername(){
			return username;
		}
		virtual void setMessage(string m){
			message = m;
			charLength = message.length();
		}
		virtual string getMessage(){
			return this->message;
		}
		int getCharLength(){
			charLength = message.length();
			return charLength; 
		}
		virtual void display(){
			cout << "@" << username << ": " << message << endl;
		}
};

// Insert code here for the MultiTweet class that inherits from Tweet
class MultiTweet : public Tweet{
	private: 
		string *subMessage;
		int size;
		void addThingy();
		string last = "";
	public: 
		MultiTweet(string u, string m) : Tweet(u, m){
			size = 0;
			subMessage = new string[100];
			splitTweets();
		}
		int getSize(){
			return size;
		}
		virtual void setMessage(string m){
			message = m;
		}
		virtual string getMessage(){
		       return message;
		}
		virtual void display();
		void splitTweets();
		
};
// Insert code here for the TweetStream class
class TweetStream{
	private:
		string userName, message;
		int size;
		Tweet *tweets[100]; 
	public:
		void setUsername(string n){
			userName = n;
		}
		string getUsername(){
			return userName;
		}
		int getSize(){
			return size;
		}
		TweetStream(string u){
			userName = u;
			size = 0;
		}
		void addMessage(string message);
		void display();
 };
#endif

#include <iostream>
#include <string>
#include "twitter.hpp"

using namespace std;

int main()
{
  string username;
  string message;
  cout << "Please enter your username: ";
  cin >> username;
  cin.ignore();
  cout << "Please input your message: ";
  getline(cin, message);
  // Insert code here to create a TweetStream object that receives as parameters the data from the user 
  TweetStream t(username);
  // Insert code here to add the user's message to the TweetStream
  t.addMessage(message);
  // Insert code here to display tweets in the TweetStream object
  t.display();
  return 0;
}

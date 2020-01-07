#include "twitter.hpp"

// Insert code here to implement MultiTweet functions
// splitTweets and display
void MultiTweet :: splitTweets(){
//makes 1st value of array be the entire message if its <= 280
       		int i = 0; 
       		int splitHere;
       		string backup = message;
	
       		while (message.length() > 280) {

	   		 //if the character at 273 is a space, then it'll AFTER split here
            		char dis = message.at(273);
            			if (int(dis) == 32) {
                			splitHere = 274; //after the split 
           			}
            			//looks for nearest space
            			else {
				//check which puncutation or space is the nearest
				int a = message.rfind(" ", 273);
				int b = message.rfind(".", 273);
				int c = message.rfind("!", 273);
				int d = message.rfind("?", 273);
				int e = message.rfind("-", 273);
				int f = message.rfind(",", 273);
				int g = message.rfind(";", 273);	
				if (a > b && a > c && a > d && a > e && a>f && a>g)
					splitHere = a+1;
				else if (b > a && b > c && b > d && b > e && b > f && b>g)
					splitHere = b+1;
				else if (c > a && c > b && c > d && c > e && c>f && c >g)
					splitHere = c+1;
				else if (d > a && d >b && d >c && d > e && d>f && d>g)
					splitHere = d+1;
				else if ( e > a && e > b && e > c && e > d && e>f && e>g)
					splitHere = e+1;
				else if (f > a && f > b && f > c && f > d && f > e && f > g)
					splitHere = f+1;
				else if (g>a && g>b && g>c && g>d && g>e && g>f)
					splitHere = g+1;
				else if (a == b && a ==c && a==d && e == a && a==f && a==g)//this checks if there 
					splitHere = 274;         //are no spaces/punctuation
        		
				}//end of mini else

           		 //assign the "clean" messages to array
			          string temp = message.substr(0, splitHere);
            		subMessage[i] = temp;
            		

            		//get remaining part of message
                	message = message.substr(splitHere);
                	i++; //increment i for next # on array
     
   		}//end of while  
		      //assign leftover message to array
		     
       		subMessage[i] = message;
        	i++; 
        	size = i; //size of array
        	setMessage(backup);
	        addThingy();

}

void MultiTweet :: display(){
	for(int x = 0; x < size; x++){
		cout << "@" << username << ": " << subMessage[x] << endl;
	}
}

void MultiTweet :: addThingy(){
	for(int i = 0; i < size; i++){
		string n = subMessage[i] + " (" + std::to_string(i+1) + "/" + std::to_string(size) + ")";
		subMessage[i] = "";
		subMessage[i] = n;
	}
}

// Insert code here to implement TweetStrem functions
// addMessage and display
void TweetStream :: addMessage(string message){
	if(message.length() <= 280){
		//tweets = new Tweet[0];
		//Tweet t(userName, message);
		tweets[size] = new Tweet(userName, message);
		size++;
	}
	else{
		//tweets = new MultiTweet[0];
		//MultiTweet m(userName, message);
		tweets[size] = new MultiTweet(userName, message);
		size++;
	}
}

void TweetStream :: display(){
	for(int i =0; i<size; i++){
		tweets[i]->display();
	}
	

}

/*
125. Valid Palindrone 


A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters and numbers.

Given a string s, return true if it is a palindrome, or false otherwise.



Example 1:

Input: s = "A man, a plan, a canal: Panama"
Output: true
Explanation: "amanaplanacanalpanama" is a palindrome.
Example 2:

Input: s = "race a car"
Output: false
Explanation: "raceacar" is not a palindrome.



steps
1.We can use a two pointer method in order to solve this solution
2.In order to change upper case letters to lowercase and to check if an element is alphanumeric
meaning that it is either a letter or a number we can use the cctype header 
	the two main functions for this solution are
	tolower - method that makes an uppercase value lowercase
	isalnum - is alphanumeric, boolean that gives true or false on whether it is alphanumeric or not

3.All we have to do is create a while loop sliding both pointers i and j towards each other until they meet
	//if i and j are equal to each other all the way til they meet its a palindrone
	//if not then it is not a palindrone

*/

#include <iostream>
#include <cctype>



class Solution {
public:
	bool isPalindrome(std::string &s);


};

//We can pass a reference of string s to save space and speed up the program
bool Solution::isPalindrome(std::string &s) {

	//First we should create both pointers which will be at the beginning and end
	//of the string 

	//Starts at the first element
	int i = 0;

	//Gives us the value of the very last element within the string
	int j = s.length() - 1;

	//We need to create a while loop that will iterate through the string
	//until i and j meet 

	while (i < j) {


		//We want to create a while loop that will advance i, while checking each element
		//Within this check, we are checking for if it is alphanumeric,
		//If it is alphanumeric then we want to compare this value with the element at j so we 
		//simply advance to j, however if the element is not alphanumeric, we want to incremenet
		//the pointer to the next element
		//We want to know if it is not alphanumeric so we can use  ! to reverse it
		while (i < j && !(std::isalnum(s[i]))) {
			i++;
		}

		//Same thing with j but decrementing
		while (i < j && !(std::isalnum(s[j]))) {
			j--;
		}

		//At this point, i and j are both holding onto an alphanumeric value,
		//the next step is to make sure both values are lowercased with the 
		//tolower method from cctype

		s[i] = std::tolower(s[i]);
		s[j] = std::tolower(s[j]);

		//Now we can create an if statement, and check if these values 
		//Are equal, if they are then we can continue with the while loop
		//But if they arent equal then we can return false b/c its not a palindrome

		//If they are equal to each other  then we want to increment i and
		//Decrement j and continue with the while loop
		if (s[i] == s[j]) {
			i++;
			j--;
		}
		else if (s[i] != s[j]) {
			return false;

		}
	}

	//If we exit the while loop having all of the same values then its a palindrome and
	//we can return true
	return true;


}

int main() {

	Solution solution;

	std::string s = "race a car";

	std::cout << std::boolalpha << solution.isPalindrome(s);

	


	//Time complexity = O(n)
	//Space complexity = O(1)

	return 0;
}
// Adam Smith
// 2449898
// AC21008

#include<iostream>
#include "HashNode.h"

// Default Constructor for the HashNode class. Sets the key and value to empty strings

HashNode::HashNode(){

	key = "";
	value = "";

}

// Parameterised constructor for the HashNode class. Sets the key and value to the given values (k and v)

HashNode::HashNode(string k, string v){

	key = k;
	value = v;

}

// Returns the value of key

string HashNode::getKey() {

	return key;

}

// Sets the value of value to v

void HashNode::setValue(string v){

	value = v;

}

// Returns the value of value

string HashNode::getValue() {

	return value;

}

// Overloading of the output operator for a HashNode. prints the key and value seperated by a : with no newline

ostream& operator<<(ostream &output, const HashNode &hn) {

	output << hn.key << ":" << hn.value;
	return output;

}

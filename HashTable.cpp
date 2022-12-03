// Adam Smith
// 2449898
// AC21008

#include "HashTable.h"
#include<iostream>
#include<math.h>
using namespace std;

const int PRIME_NUM = 31;

HashTable::HashTable() {
    tablesize = 10;
    table = new HashNode[10];
}

HashTable::HashTable(int size) {
    tablesize = size;
    table = new HashNode[size];
}

HashTable::~HashTable() {
    delete [] table;
}

// function that computes a hash value based on the key. 
int HashTable::hashFunction(string k){

    // creates an int hashcode, which stores the value of the
    int hashcode = 0;

    // for loop, which loops through the string k
    for ( int i = 0; i < k.length(); i++ ) {

        // creates an int letter, and sets it to the ASCII value of the letter
        int letter = int(k[i]);

        // creates an int power, and sets it to the value of PRIME_NUM (31) to the power of i
        int power = pow(PRIME_NUM, i);

        // produces the remainder when power is divided by the tablesize (modulo)
        power %= tablesize;

        // sets hashcode to the value of letter times the value of power
        hashcode += letter * power;

    }

    // creates an int functionresult, and sets it to the value of the remainder when hashcode is divided by tablesize (modulo)
    int functionresult = hashcode % tablesize;

    // returns the functionresult
    return functionresult;

}

// function that inserts the hashnodes into the table
bool HashTable::insert(string k, string v){

    HashNode temp(k, v);
    int hashindex = hashFunction(k);

    // while loop, which uses linear probing (with a step size of 1) to find the next available empty bucket
    while ( table[hashindex].getKey() != k && table[hashindex].getKey() != "" ) {
        hashindex++;
        hashindex %= tablesize;

        // prevents an endless loop
        if (hashindex > tablesize) {
            return false;

        }
    }

    // if an empty bucket is found, insert the key and value
    if (table[hashindex].getKey() == "") {

        table[hashindex] = temp;
        return true;

    }

    else {

        return false;

    }

}

// function that searches for an item in the table with a given key value k
int HashTable::search(string k) {

    int hashindex = hashFunction(k);

    // probes through the table, looking for the right position
    while (table[hashindex].getKey() != "" && table[hashindex].getValue() != "" && table[hashindex].getKey() != k) {

        hashindex++;

        // prevents an endless loop
        if (hashindex > tablesize) {

            return -1;

        }

    }

    // if the item is not found, returns value of -1
    if ( table[hashindex].getKey() == "" && table[hashindex].getValue() == "") {

        return -1;

    }

    // if item is found, returns the hashindex that it was found at
    else {

        return hashindex;

    }

}

// function that updates an existing item in the table
bool HashTable::update(string k, string v) {

    if (search(k) == -1) {

        return false;

    }else {

        table[search(k)].setValue(v);

        return true;

    }

}

// function that uses the search function to look for an item in the table, and returns its value
string HashTable::lookup(string k) {

    if (search(k) == -1) {

        return "";

    }else {

        return table[search(k)].getValue();

    }

}

// overloading of the output operator for the HashTable. prints the array index and the HashNode, followed by a newline
ostream& operator<<(ostream &output, const HashTable &ht) {

    for (int i = 0; i < ht.tablesize; i++) {

        output << i << ":" << ht.table[i] << endl;

    }

    return output;

}

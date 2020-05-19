#include <iostream>
#include <cstring>
#include <fstream>
#include <cmath>
#include <cstdlib>
#include "Node.h"
#include "RBT.h"

using namespace std;

void strupper(char* str);
int strToInt(char* str);
void Insert(RBT*);
void Read(RBT*);
void PrintTree(RBT*);
void Search(RBT*);
void RemoveNode(RBT*);

int main()
{
  RBT* rbt = new RBT();
  //New red-black tree
  char input[80];
  //User input
  bool running = true;
  //Program running
  while (running == true){//While program is running
    cout<<"Do you want to add a single number, read in a series of numbers from a file, print out a visual representation of the tree, search the tree for a number, delete a number from the tree, or quit?"<<endl;
    //Ask user if they want to add a single number, read in a series of numbers from a file, print out a visual representation of the tree, search the tree for a number, delete a number from the tree, or quit
    cin.getline(input, sizeof(input));
    //Take in user's input
    strupper(input);
    //Make it uppercase
    if (strcmp(input, "ADD") == 0){//If they said ADD
      Insert(rbt);
      //Call insert
    }
    else if (strcmp(input, "READ") == 0){//If they said READ
      Read(rbt);
      //Call read
    }
    else if (strcmp(input, "PRINT") == 0){//If they said PRINT
      PrintTree(rbt);
      //Call print
    }
    else if (strcmp(input, "SEARCH") == 0){//If they said SEARCH
      Search(rbt);
      //Call search
    }
    else if (strcmp(input, "DELETE") == 0){//If they said DELETE
      RemoveNode(rbt);
      //Call delete
    }
    else if (strcmp(input, "QUIT") == 0){//If they said QUIT
      running = false;
      //Stop the program
    }
    else{//Anything else
      cout<<"That's an invalid option"<<endl;
      //Tell the user that's an invalid option
    }
  }
  delete rbt;
  //Delete the red-black tree
}

void strupper(char* str){//Make input uppercase
  int len = strlen(str);
  //Length of user's input
  for (int i = 0; i < len; i++){//For loop looping through user's input
    str[i] = toupper(str[i]);
    //Make each letter uppercase
  }
}

int strToInt(char* str){//Str to int function
  int num = 0;
  //Int num
  for (int i = 0; i < strlen(str); i++){//Loop through length of str
    if (!isdigit(str[i])){//If it's not a digit
      continue;
      //Continue
    }
    num *= 10;
    //Num now equals num*10
    num += str[i] - '0';
    //Add str[i] - 0 to num
  }
  return num;
  //Return num
}

void Insert(RBT* rbt){//Insert
  int key;
  //Int key
  cout<<"What number do you want to add to the tree?"<<endl;
  //Ask the user what number they want to add to the tree
  cin>>key;
  //Take in their input
  cin.clear();
  cin.ignore(999, '\n');
  rbt->Insert(key);
  //Call Insert passing in the key
}

void Read(RBT* rbt){//Read
  char fileName[80];
  //File name
  char line[100];
  cout<<"Enter a file name"<<endl;
  //Ask the user for a file name
  cin.getline(fileName, sizeof(fileName));
  //Get user's input
  ifstream fileStream;
  fileStream.open(fileName);
  //Try and open the file
  if (fileStream){//If it worked
    fileStream.getline(line, sizeof(line));
    //Get the numbers from the file
  }
  else{//If it didn't work
    cout<<"Couldn't find that file"<<endl;
    //Tell the user the file couldn't be found
    return;
    //Return
  }
  fileStream.close();
  //Close the file
  char* f = new char[strlen(line)+1]();
  //f is new char strlen of line + 1
  int ind = 0;
  //New int shortened index
  for (int i = 0; i < strlen(line); i++){//For loop looping through length of line
    if (line[i] == ' '){//If line[i] is a space
      if (strlen(f) > 0){//If length of f is greater than 0
        rbt->Insert(strToInt(f));
        //Call public Insert function with strToInt function with f
      }
      f = new char[strlen(line)+1]();
      //f is new char of length line +1
      ind = 0;
      //Set ind to 0
    }
    else{//Anything else
      if (isdigit(line[i])){//If line[i] is a digit
        f[ind++] = line[i];
        //f[ind++] now equals line[i]
      }
    }
  }
  return;
  //Return
}

void PrintTree(RBT* rbt){//Print tree
  rbt->PrintTree();
  //Call PrintTree
}

void Search(RBT* rbt){//Search
  int key;
  //Int key
  cout<<"What number do you want to search the tree for?"<<endl;
  //Ask the user what number they want to search the tree for
  cin>>key;
  //Take in the user's input
  cin.clear();
  cin.ignore(999, '\n');
  rbt->Search(key);
  //Call Search with the key
}

void RemoveNode(RBT* rbt){//Remove node
  int key;
  //Int key
  cout<<"What number do you want to remove from the tree?"<<endl;
  //Ask the user what number they want to remove from the tree
  cin>>key;
  //Take in the user's input
  cin.clear();
  cin.ignore(999, '\n');
  rbt->RemoveNode(key);
  //Call RemoveNode with the key
}

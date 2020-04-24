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
  char input[80];
  bool running = true;
  while (running == true){
    cout<<"Do you want to add a single number, read in a series of numbers from a file, print out a visual representation of the tree, search the tree for a number, delete a number from the tree, or quit?"<<endl;
    cin.getline(input, sizeof(input));
    strupper(input);
    if (strcmp(input, "ADD") == 0){
      Insert(rbt);
    }
    else if (strcmp(input, "READ") == 0){
      Read(rbt*);
    }
    else if (strcmp(input, "PRINT") == 0){
      PrintTree(rbt);
    }
    else if (strcmp(input, "SEARCH") == 0){
      Search(rbt);
    }
    else if (strcmp(input, "DELETE") == 0){
      RemoveNode(rbt);
    }
    else if (strcmp(input, "QUIT") == 0){
      running = false;
    }
    else{
      cout<<"That's an invalid option"<<endl;
    }
  }
  delete rbt;
}

void strupper(char* str){
  int len = strlen(str);
  for (int i = 0; i < len; i++){
    str[i] = toupper(str[i]);
  }
}

int strToInt(char* str){
  int num = 0;
  for (int i = 0; i < strlen(str); i++){
    if (!isdigit(str[i])){
      continue;
    }
    num *= 10;
    num += str[i] - '0';
  }
  return num;
}

void Insert(RBT* rbt){
  int key;
  cout<<"What number do you want to add to the tree?"<<endl;
  cin>>key;
  cin.clear();
  cin.ignore(999, '\n');
  rbt->Insert(key);
}

void Read(RBT* rbt){
  char fileName[80];
  char line[100];
  cout<<"Enter a file name"<<endl;
  cin.getline(fileName, sizeof(fileName));
  ifstream fileStream;
  fileStream.open(fileName);
  if (fileStream){
    fileStream.getline(line, sizeof(line));
  }
  else{
    cout<<"Couldn't find that file"<<endl;
    return;
  }
  fileStream.close();
  char* f = new char[strlen(line)+1]();
  int ind = 0;
  for (int i = 0; i < strlen(line); i++){
    if (line[i] == ' '){
      if (strlen(f) > 0){
        rbt->Insert(strToInt(f));
        f = new char[strlen(line)+1]();
        ind = 0;
      }
      else{
        if (isdigit(line[i])){
          f[ind++] = line[i];
        }
      }
    }
  }
  return;
}

void PrintTree(RBT* rbt){
  rbt->PrintTree();
}

void Search(RBT* rbt){
  
}

void RemoveNode(RBT* rbt){
  
}

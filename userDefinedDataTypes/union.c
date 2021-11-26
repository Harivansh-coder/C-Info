/*
  Unions are not nuch different from Structures
  one of the major differences except the union keyword in syntax is
  memory behaviour of Unions.

  union provides memory to a single attribute at a time.
*/
#include<stdio.h>
#include<string.h>
int main(int argc, char const *argv[]) {

  // union definition
  union user{
    char name[20];
    int age;
    char email[20];
  };

  // Initializing a user

  union user user1;

  // accessing the attributes of user and setting values

  strcpy(user1.name, "Example");
  user1.age = 69;
  strcpy(user1.email, "example@gmail.com");


  // printing the values
  printf("user1 name %s\n",user1.name);
  printf("user1 age %i\n",user1.age);
  printf("user1 email %s\n",user1.email);
  printf("\n\n");


  // printing all vaues
  strcpy(user1.name, "Example");
  printf("user1 name %s\n",user1.name);

  user1.age = 69;
  printf("user1 age %i\n",user1.age);

  strcpy(user1.email, "example@gmail.com");
  printf("user1 email %s\n",user1.email);


  return 0;
}

/*

Output

user1 name example@gmail.com
user1 age 1835104357
user1 email example@gmail.com


user1 name Example
user1 age 69
user1 email example@gmail.com


*/

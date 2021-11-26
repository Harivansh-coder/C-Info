/*
    Structures in C are user defined data types (as it is defined by users according to there needs)
    It is defined using struct keyword below is an eg.

    Advandage of Structures is, it can hold multiple data-types under a single name.
    For people with OOPS background can understand it as a class with out method and
    all members are public by default.
*/

#include<stdio.h>
#include<string.h>
int main(int argc, char const *argv[]) {

  // Structure definition type1
  struct user{
    char name[20];
    int age;
    char email[20];
  };

  // Initializing a user

  struct user user1;

  // accessing the attributes of user and setting values

  strcpy(user1.name, "Example");
  user1.age = 69;
  strcpy(user1.email, "example@gmail.com");


  // printing the values
  printf("user1 name %s\n",user1.name);
  printf("user1 age %i\n",user1.age);
  printf("user1 email %s\n",user1.email);
  printf("\n\n\n");



  // Structure definition type2
  struct {
    char manufacturer[20];
    int price;
  } phone1; // declaring a phones

  strcpy(phone1.manufacturer, "Company");
  phone1.price = 1000;


  // printing the values
  printf("phone1 name %s\n",phone1.manufacturer);
  printf("phone1 price %i\n",phone1.price);



  return 0;
}

/*

Output

  user1 name Example
  user1 age 69
  user1 email example@gmail.com



  phone1 name Company
  phone1 price 1000


*/

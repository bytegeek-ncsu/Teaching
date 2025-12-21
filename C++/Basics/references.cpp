#include <iostream>
#include <string>
#include <vector>

/**
 * What is a reference. 
 * Reference is nothing but a alias of a variable. It just refers same memory location.
 * You cannot make the reference to refer a different memory. that means you cannot change the address
 * but you can change the content it refers to. 
 */

using namespace std; //It is not good practice to use namespace like this :)

int main(){

    int age{48};
    string name{"Shak"};

    int &ageRefer = age;
    string &nameRef = name;

    cout<<"------------------ References----"<<endl;
    cout<<ageRefer<<endl;
    cout<<nameRef<<endl;
    cout<<"------------------ Variables----"<<endl;
    cout<<age<<endl;
    cout<<name<<endl;
    
    // if change the reference the acutal vairable values will be changed since
    //both refers the same location

    age = 52;
    nameRef = "Sambasivam";

    cout<<"------------------ References----"<<endl;
    cout<<ageRefer<<endl;
    cout<<nameRef<<endl;
    cout<<"------------------ Variables----"<<endl;
    cout<<age<<endl;
    cout<<name<<endl;

    vector<string> names{"one", "two", "Three"};
    //The interesting concept here is each time
    //the name varaible is copied as a value in
    // the name variable. 

    for(auto name:names)
        cout<<name<<endl;
//Lets prove the comment is correct;

    for(auto name:names)
        name="Rishi";

    for(auto name:names)
        cout<<name<<endl; //Here is printing the one two three instead of Rishi three time.
    
    //But if use name variable as a reference then it will change values actually placed in the vector

    for(auto &name:names)
        name = "Rishi";

    for(auto const &name:names)
        cout<<name<<endl; //Here we go it is changed to Rishi. The other interesting aspect
    //We constant reference so that they cannot change while just reading the vector like this.

    /**
     *  You have to be careful while using references. You cannot return a refence of 
     * a local vairable inside the function. Why? after fucntion call the local varialbes
     * will be cleaned up in the stack, so this reference vaiable will be refering some 
     * garbage in the memory.
     * 
     */

     /**
      * Since we are discussing references lets briefly discuss about l-value and r-value
      * l-values are anyting which is addressable i.e means it is refering some part of memory location
      * where we can access.
      * 
      * int age{50}; age is l-value
      * 
      * Where as r-value in a simple we can say any value which is not an l-value is r-value
      * 
      * pretty vague. But kind of easy to chew. Technically we can say literal, on the RHS of exp, or intermeidate represention of some 
      * expression: Like this
      * 
      * int y = a+b+200; (a+b+200) is a r-value
      * return value of the function. Should be careful here. What kind of return value it is.
      * 
      * so in the context of references the references we used in this program are refering l-values.
      * Some specific memory location. so
      * 
      * if int &num = 100; //error: since 100 is not addressable. This thing will change later. Let's wait for that.
      * 
      * so simple function concept.
      * 
      * int add(int &a, int &b){
      *     return a+b;
      * 
      * }
      * 
      * in this case:
      * int x{10}, y{10};
      * int z = add(x+y); // This is OK because x and y are l-values
      * 
      * where as
      * 
      * int z= add(5+10); //Error because 5+10 are r-values. pretry confusing.
      * 
      * actually you can think like we are trying to this: int &a = 5; which is illegal
      * 
      */
     
  


    return 0;
}
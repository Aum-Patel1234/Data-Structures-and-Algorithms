#include <iostream>
#include <vector>
#include "export.cpp"
using namespace std;

int global_variable = 10;

void print_vec(vector<int> vec){
    for(int num:vec){
        // cout<<vec.at(i)<<"\t";
        cout<<num<<"\t";
    }
    cout<<endl;
}

int main(){
    int global_variable = 20;
    cout<<"This variable has a block scope variable - "<<global_variable<<endl;
    cout<<"This variable has a global scope variable - (using ::) "<<::global_variable<<endl;

    vector<int> vec;
    vec.push_back(6);
    vec.push_back(8);
    vec.push_back(4);

    print_vec(vec);

    cout<<endl<<endl<<"Size of the vector - "<<vec.size()<<"\nCapacity of the vector - "<<vec.capacity()<<endl;       // important size is 3 whereas capacity is 4
    vec.push_back(10);

    vec.emplace_back(11);       

    cout<<"Capacity - "<<vec.capacity()<<endl;        // it has been doubled 

    print_vec(vec);    	
    vec.pop_back();
    print_vec(vec);    	

    // to print at particular index
    cout<<(bool)(vec[2] == vec.at(2))<<endl;

    //more functions
    cout<<"Front element - "<<vec.front()<<endl;
    cout<<"End element - "<<vec.back()<<endl;

    // different ways to initialize the vector
    vector<int> vec1 = {1,2,3,4};
    print_vec(vec1);
    vector<int> vec2(10,-1);         // first argument is size and other is the value to be with 
    print_vec(vec2);
    vector<int> vec3(vec1);
    print_vec(vec3);

    // some differet vector 
    // 1. erase
    // 2. insert
    // 3. clear
    // 4. empty
    cout<<endl<<endl;
    print_vec(vec);
    vec.erase(vec.begin());     // vec.begin() is an iterator
    print_vec(vec);

    print_vec(vec2);
    vec2.erase(vec2.begin() , vec2.begin() + 3);
    print_vec(vec2);

    vec.clear();
    cout<<"Size - "<<vec.size();
    cout<<endl<<"Capacity - "<<vec.capacity()<<endl<<endl;        // the capacity is unaffecterd

    // itreators
    cout<<"Iterator - "<<endl;
    //      -1              -1      -1      -1      -1      -1      -1          some garbage value
    //       ^                                                                         ^     
    // vec.begin()                                                                  vec.end()
    vector<int>::iterator it;
    for(auto it = vec2.begin();it != vec2.end();it++){       
        cout<<*it<<"\t";
    }
    // In C++, the auto keyword is used for type inference, meaning that the compiler automatically deduces the type of the variable based on the expression used to initialize it. This is particularly useful in complex or verbose type declarations, making code more concise and easier to read.
    cout<<endl<<endl;

    // reverse itreators
    cout<<"Reverse Iterator - "<<endl;
    //        some garbage value      -1              -1      -1      -1      -1      -1        -1     
    //       ^                                                                                  ^     
    // vec.rend()                                                                       vec.rbegin()
    vector<int>::reverse_iterator it_reverse;
    for(auto it_reverse = vec2.rbegin();it_reverse != vec2.rend();it_reverse++){       
        cout<<*it_reverse<<"\t";
    }
    // In C++, the auto keyword is used for type inference, meaning that the compiler automatically deduces the type of the variable based on the expression used to initialize it. This is particularly useful in complex or verbose type declarations, making code more concise and easier to read.
    cout<<endl;

    return 0;
}

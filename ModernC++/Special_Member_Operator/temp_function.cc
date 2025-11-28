#include<iostream>

template <class T> T max(T a, T b){
    if(a>b)
        return a;
    else    
        return b;

}

int main(){

    std::cout<<max(11,8)<<std::endl;
    std::cout<<max('B','c')<<std::endl;
    std::cout<<max(11.8,.8)<<std::endl;

    //std::cout<<max(11.8, 11)<std:endl;
    //For the above we need some kind of specialiaztion
    std::cout<<max<double>(11.8, 11)<<std::endl; //Here both the arguments will be converted double
    std::cout<<max<int>(11.8, 11)<<std::endl; //Here arguments will converted to int
    


    return 0;
}
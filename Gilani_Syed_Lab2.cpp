#include <iostream>
#include <random>
using namespace std;


float powLinear(float x, int y){
    if (y == 0){
        return 1;
    }

    else if (y%2==0){
        return powLinear(x,y/2) * powLinear(x,y/2);
    }
    else {
        if (y>0){
            return x*powLinear(x,y/2)*powLinear(x,y/2);
        }
        else {
        return (powLinear(x,y/2)*powLinear(x,y/2))/x;
          }
    }


}

float powLgN (float x, int y){
    if(y==0){
        return 1;
    }
    float temp = powLgN(x,y/2);

    if(y%2==0){
        return temp*temp;
    }

    else {
        if (y>0){
            return x*temp*temp;
        }
        else {
        return (temp*temp)/x;
        }
    }
}



int main() {
    float x = 4;
    int y = -2;

   

    std::cout<<"Linear time pow(x,y) = ";
    std::cout<<powLinear(x,y)<<endl;
    std::cout<<"lg n time pow(x,y) = ";
    std::cout<<powLgN(x,y)<<endl;


    return 0;
  
}
#include <stdio.h>
#include <math.h>
#include <vector>
#include <ctime>
#include <string>
#include <iostream>

using namespace std;


long multiply3(string num, string num2){

if (stoi(num) == 0 || stoi(num2)==0){
    return 0;
}

if (num.size()==1 && num2.size()==1){

    return stoi(num)*stoi(num2);
}


while (num.size() % 2 != 0){
    num.insert(0,"0");
}

while (num2.size() % 2 != 0){
    num2.insert(0,"0");
}

while (num.size() < num2.size()){
    num.insert(0, "0");
}
       
    while (num2.size() < num.size()){
    num2.insert(0, "0");
    }

int len1 = num.size(); 
int len2 = num2.size(); 


int x = stoi(num);
int y = stoi(num2);


int half = len1/2;
int a = x/(pow(10,half));
int b = x%((int)pow(10,half));
int c = y/(pow(10,half));
int d= y% ((int)pow(10,half));


int e = multiply3(to_string(a),to_string(c));
int f = multiply3(to_string(b),to_string(d));
int g = multiply3(to_string(a+b), to_string(c+d)) - e - f;


    return ((pow(10,len1)*e)+f+(pow(10,half)*g));


}


string multiply4(string num, string num2){
    int len_num = num.size();
    int len_num2 = num2.size();

    if (len_num == 0 || len_num2 ==0){
        return "0";
    }

    vector<int>result (len_num+len_num2,0);

    int i_num = 0;
    int i_num2=0;

    for (int i =len_num-1; i>=0;i--){
        int carry=0;
        int len_num = num[i] - '0';
        i_num2 = 0;
    

    for (int j = len_num2-1; j>=0; j--){
        int len_num2 = num2[j] - '0';
        int sum = len_num*len_num2 + result[i_num+i_num2]+ carry;
        carry = sum/10;
        result[i_num+i_num2] = sum%10;
        i_num2++;

    }

    if (carry>0){
        result[i_num+i_num2] += carry;
        i_num++;
    }
    }

    int i = result.size() -1;
    while (i >= 0 && result[i] == 0){
        i--;
    }

    if (i == -1){
        return "0";
    }

    string answer = "";
    while (i>=0 ){
        answer += std::to_string(result[i--]);
    }

    return answer;

}



int main(){
    
auto startTime1 = std::chrono::steady_clock::now();
string one = multiply4("1234","4321");
auto endTime1 = std::chrono::steady_clock::now();
auto totalTime1 = endTime1-startTime1;
auto startTime2 = std::chrono::steady_clock::now();
long two = multiply3("1234","4321");
auto endTime2 = std::chrono::steady_clock::now();
auto totalTime2 = endTime2-startTime2;


auto startTime3 = std::chrono::steady_clock::now();
string three = multiply4("110","220");
auto endTime3 = std::chrono::steady_clock::now();
auto totalTime3 = endTime3-startTime3;
auto startTime4 = std::chrono::steady_clock::now();
long four = multiply3("110","220");
auto endTime4 = std::chrono::steady_clock::now();
auto totalTime4 = endTime4-startTime4;


auto startTime5 = std::chrono::steady_clock::now();
string five = multiply4("14589","912");
auto endTime5 = std::chrono::steady_clock::now();
auto totalTime5 = endTime5-startTime5;
auto startTime6 = std::chrono::steady_clock::now();
long six = multiply3("14589","912");
auto endTime6 = std::chrono::steady_clock::now();
auto totalTime6 = endTime6-startTime6;


auto startTime7 = std::chrono::steady_clock::now();
string seven = multiply4("7777777", "88888888");
auto endTime7 = std::chrono::steady_clock::now();
auto totalTime7 = endTime7-startTime7;
auto startTime8 = std::chrono::steady_clock::now();
long eight = multiply3("7777777", "88888888");
auto endTime8 = std::chrono::steady_clock::now();
auto totalTime8 = endTime8-startTime8;


    std::cout<<one;
    std::cout<<", ";
    std::cout << std::chrono::duration <double, std::milli> (totalTime1).count() << " ms taken to run. (Multiply4)" << std::endl;

    std::cout<<two;
    std::cout<<", ";
    std::cout << std::chrono::duration <double, std::milli> (totalTime2).count() << " ms taken to run. (Multiply3)" << std::endl;


    std::cout<<three;
    std::cout<<", ";
    std::cout << std::chrono::duration <double, std::milli> (totalTime3).count() << " ms taken to run. (Multiply4)" << std::endl;


    std::cout<<three;
    std::cout<<", ";
    std::cout << std::chrono::duration <double, std::milli> (totalTime4).count() << " ms taken to run. (Multiply3)" << std::endl;


    std::cout<<five;
    std::cout<<", ";
    std::cout << std::chrono::duration <double, std::milli> (totalTime5).count() << " ms taken to run. (Multiply4)" << std::endl;


    std::cout<<six;
    std::cout<<", ";
    std::cout << std::chrono::duration <double, std::milli> (totalTime6).count() << " ms taken to run. (Multiply3)" << std::endl;


    std::cout<<seven;
    std::cout<<", ";
    std::cout << std::chrono::duration <double, std::milli> (totalTime7).count() << " ms taken to run. (Multiply4)" << std::endl;


    std::cout<<eight;
    std::cout<<", ";
    std::cout << std::chrono::duration <double, std::milli> (totalTime8).count() << " ms taken to run. (Multiply3)" << std::endl;










}

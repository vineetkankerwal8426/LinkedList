#include<iostream>
using namespace std;

//happy number - A happy number is a number defined by the following process:
//         Starting with any positive integer, replace the number by the sum of the squares of its digits. ex -19 = 1^2+9^2;
//         Repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1.
//         Those numbers for which this process ends in 1 are happy.



// this problem is solve with the same approach of fast and slow pointer in linked list
// if the number will never be 1 then it will go to infinite loop but it will be in a cycle , the square of number starts repeating at a point
// so that's why we can use cycle detecting approach using fast and slow pointers;
int square(int n){// do square of each digits
        int ans =0;
        while(n>0){
            int r = n%10;
            ans += (r*r);
            n=n/10;
        }   
        return ans;
    }
bool isHappy(int n) {
        int f = n; //fast pointer
        int s = n; // slow pointer
        do{
            s = square(s);
            f = square(square(f));
            if(s==1){ // if slow pointer will equals to 1 then it will be a happy number;
                return true;
            }
        }while(f!=s);
        return false;// else f becomes equals to s and it means their exists a cycle and return false;
    }
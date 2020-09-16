#include <iostream>
#include <cmath>
#include <sstream>

using namespace std;

int main() {
  string s;

  
  int *numbers;
  cin>>s;
  numbers=new int[s.length()];

  for(int i=0;i<s.length();i++){
      if(isdigit(s[i])){
        numbers[i]= (int)s[i]-'0';
      }
      else{
        if(s[i]=='I'){
          numbers[i]=1;
        }
        else if(s[i]=='V'){
          numbers[i]=5;
        }
        else if(s[i]=='X'){
          numbers[i]=10;
        }
        else if(s[i]=='L'){
          numbers[i]=50;
        }
        else if(s[i]=='C'){
          numbers[i]=100;
        }
        else if(s[i]=='D'){
          numbers[i]=500;
        }
        else{
          numbers[i]=1000;
        }
      }
  }
  
  int sum=0;
  for(int i=1;i<s.length();i+=2){
    if(i+2<s.length()){
      if(numbers[i]<numbers[i+2]){
        sum-=numbers[i-1]*numbers[i];
      }
      else{
        sum+=numbers[i-1]*numbers[i];
      }
    }

    else{
      sum+=numbers[i-1]*numbers[i];
    }
  }
  
  cout<<sum<<endl;
}

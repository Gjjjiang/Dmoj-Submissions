#include <iostream>
#include <string>
using namespace std;

int main() {
  string input;
  long long int sum;
  long long int digit;
  //string output;
  bool yes_double;
  for(int i=0;i<5;i++){
    //output="";
    for(int j=0;j<5;j++){
      sum=0;
  
      cin>>input;
      yes_double=true;
      for(int itr=input.length()-1;itr>=0;itr--){
        if(yes_double){

          digit=(int)input[itr]-(int)'0';
          digit*=2;
          sum+= (digit/10) + (digit%10);
          yes_double=false;
        }
        else{
          digit=(int)input[itr]-(int)'0';
          sum+=digit;
          yes_double=true;
        }
      }
      
      if(sum%10==0)cout<<"0";
      else cout<<((sum/10)+1)*10-sum;
    }
    cout<<endl;
  }
}

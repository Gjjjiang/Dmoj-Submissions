#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
  vector<long long int> factor, power;
  factor.push_back(1);
  power.push_back(0);

  long long int a, b, counter = 0,n=0;

  cin>>a>>b;

  long long int temp = a;

  for(long long int i=2;temp>1;){
    if(temp%i==0){
      
      temp/=i;
      if(factor[factor.size()-1]!=i){   
        factor.push_back(i);
        counter++;
      }
      else counter++;
    }
    if(temp%i!=0){
      if(counter>0){
        power.push_back(counter);
      }
      counter = 0;
      i++;
    }
  }

  for (long long int i=1;i<factor.size();i++){
    counter=0;
    for(long long int exponent=1; b/pow(factor[i],exponent)!=0;exponent++){
      counter+=b/pow(factor[i],exponent);
    }
    counter/=power[i];
    if(n==0)n=counter;
    else if (counter<n)n=counter;
  }
  cout<<n<<endl;
}

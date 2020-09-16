#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
 
using namespace std;
 
 
int main() {
  long long int n,water_t;
 
  long long int max_tasty=0, min_tasty=0;
 
  vector<long long int> t;
 
  cin>>n>>water_t;
 
  long long int input;
  for(int i=0;i<n;i++){
    cin>>input;
     t.push_back(input);
  }
 
 
  sort(t.begin(),t.end());

  long long int start=t[t.begin()-t.begin()];
 
  long long int *max_order, *temp_order;

  temp_order=new long long int [n];
  max_order=new long long int [n];
 
  long long int temp = 0;
 
  for (int i=0;i<(int)t.size()/2+1;i++){
   max_order[2*i]=t[i];
   temp_order[2*i]=t[t.end()-t.begin()-i-1];
   if(2*i+1<n) {
     max_order[2*i+1]=t[t.end()-t.begin()-i-1];
    
     temp_order[2*i+1]=t[i];
   }
  
  }

  if(abs(max_order[0]-water_t)<=abs(max_order[n-1]-water_t)){
    reverse(max_order, max_order+n);
  }



  max_tasty+=abs(water_t-max_order[0]);


  for(int i=0;i<(int)t.size()-1;i++){
  
    if(abs(max_order[i]-max_order[i+1])<abs(max_order[i+1]-water_t)){
      max_tasty+= abs(max_order[i+1]-water_t);
      
    }
    else {
      max_tasty+= abs(max_order[i]-max_order[i+1]);
    }
    
    if(abs(temp_order[i]-temp_order[i+1])<abs(temp_order[i+1]-water_t)){
      temp+= abs(temp_order[i+1]-water_t);
    }
    else{
      temp+= abs(temp_order[i]-temp_order[i+1]);
    }
    
  }



  if(abs(temp_order[0]-water_t)>abs(temp_order[n-1]-water_t)){
    temp+=abs(temp_order[0]-water_t);
  }
  else temp+=abs(temp_order[n-1]-water_t);

  if(temp>max_tasty)max_tasty=temp;
  
  //min
  t.push_back(water_t);

  sort(t.begin(),t.end());

  int a=find(t.begin(),t.end(),water_t)-t.begin();

  for(int i = a;i>=1;i--){
    min_tasty+=abs(t[i]-t[i-1]);
  }
  
  for(int i = a; i<(int)t.size()-1;i++){
    min_tasty+=abs(t[i+1]-t[i]);
  }

 cout<<min_tasty<<" "<<max_tasty<<endl;
 
}

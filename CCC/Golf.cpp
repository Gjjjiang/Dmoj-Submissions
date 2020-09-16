#include <iostream>
#include <algorithm>
using namespace std;



int main() {
  int distance, n, *club;
  int *swings;
  cin>>distance>>n;
  
  club=new int [n];
  swings=new int[distance+1];
  int smallest = distance+1;

  for(int i=0;i<n;i++){
    cin>>club[i];
    if(club[i]<smallest)smallest=club[i];
    swings[club[i]]=1;
  }
  int least_swing;

  for(int i=smallest;i<distance+1;i++){
    least_swing =2147483640;
    if(swings[i]!=1){
      for(int counter=0;counter<n;counter++){
      
        if(i-club[counter]>0){
          if(swings[i-club[counter]]<least_swing && swings[i-club[counter]]!=0){
            least_swing=swings[i-club[counter]];
          }
        }
      }
      if(least_swing!=0&&least_swing!=2147483640)swings[i]=least_swing+1;
    }
  }
  if(swings[distance]>0){
    cout<<"Roberta wins in "<<swings[distance] <<" strokes."<<endl;
  }
  else cout<<"Roberta acknowledges defeat."<<endl;

}

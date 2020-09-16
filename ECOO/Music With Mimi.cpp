#include <bits/stdc++.h>

using namespace std;

int main() {
  string input;

 
  int n;

  cin>>n;
  cin.ignore();
  for(int i=0;i<n;i++){
     int notes[4];
     int distance[3];
      int counter=0;
      int start=0,location=0;
      getline(cin,input);
      input+=" ";
      //cout<<input;
      while(input.find(" ",start)!=string::npos){
        location=input.find(" ",start);

        if(input.substr(start,location-start)=="C"){
          notes[counter]=0;
        }
        else if(input.substr(start,location-start)=="C#"){
          notes[counter]=1;
        }

        else if(input.substr(start,location-start)=="D"){
          notes[counter]=2;
        }
        else if(input.substr(start,location-start)=="D#"){
          notes[counter]=3;
        }
        else if(input.substr(start,location-start)=="E"){
          notes[counter]=4;
        }
        else if(input.substr(start,location-start)=="F"){
          notes[counter]=5;
        }
        else if(input.substr(start,location-start)=="F#"){
          notes[counter]=6;
        }
        else if(input.substr(start,location-start)=="G"){
          notes[counter]=7;
        }
        else if(input.substr(start,location-start)=="G#"){
          notes[counter]=8;
        }
        else if(input.substr(start,location-start)=="A"){
          notes[counter]=9;
        }
        else if(input.substr(start,location-start)=="A#"){
          notes[counter]=10;
        }
        else if(input.substr(start,location-start)=="B"){
          notes[counter]=11;
        }
        counter++;
        start=location+1;
      }
      
      for(int counter=0;counter+1<4;counter++){
        if(notes[counter]>notes[counter+1]){
          distance[counter]=notes[counter+1]-notes[counter]+12;
        }
        else{
          distance[counter]=notes[counter+1]-notes[counter];
        }
      }

      if(distance[0]==4){
        if(distance[1]==3&&distance[2]==3)cout<<"root"<<endl;
        else cout<<"invalid"<<endl;
      }
      else if(distance[0]==3){
        if(distance[1]==3&&distance[2]==2)cout<<"first"<<endl;
        else if (distance[1]==2&&distance[2]==4)cout<<"second"<<endl;
        else cout<<"invalid"<<endl;

      }
      else if(distance[0]==2){
        if(distance[1]==4&&distance[2]==3)cout<<"third"<<endl;
        else cout<<"invalid"<<endl;
      }
      else{
        cout<<"invalid"<<endl;
      }


  }

}

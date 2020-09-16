#include <iostream>
#include <algorithm>

using namespace std;

void quickSort(int*, int*, int, int);

int main() {
  int *a,*b;
  int n,start;
  int planets=1;
  
  int max_fuel=0;
  cin>>n>>start;
  n--;
  a=new int[n];
  b=new int[n];

  int in_a,in_b;
  int temp=0;
  for(int i=0;i<n+1;i++){
    cin>>in_a>>in_b;

    if(i==start-1){
      max_fuel+=in_a;
      temp++;
    }
    else{
      a[i-temp]=in_a;
      b[i-temp]=in_b;
    }
  }
  
  quickSort(b, a, 0, n-1);

  for(int i=0;i<n && b[i]<=max_fuel;i++){
    if(b[i]<=max_fuel && a[i]-b[i]>=0){
      max_fuel+=a[i]-b[i];
      planets++;
    }
  }  
  cout<<max_fuel<<endl;
  cout<<planets<<endl;

}

void swap(int *a, int *b) {
	long int t = *a;
	*a = *b;
	*b = t;
}

void quickSort(int arr[], int arr2[], int min, int max) {
	if (min < max) {
		//split
		long int pivot = arr[max];
		long int selected_element = min - 1;
		for ( long int ptr = min; ptr < max; ptr++) {
			if (arr[ptr] < pivot) {
				selected_element++;
				swap(&arr[ptr], &arr[selected_element]);
				swap(&arr2[ptr], &arr2[selected_element]);
			}
		}
		swap(&arr[max], &arr[selected_element + 1]);
		swap(&arr2[max], &arr2[selected_element + 1]);
		selected_element++;
		//sort
		quickSort(arr, arr2 ,min, selected_element - 1);
		quickSort(arr, arr2,selected_element + 1, max);
	}

}

#include <iostream>
#include <algorithm>
#include <cmath>
#include <iomanip>
using namespace std;

void quickSort(long long int*, long long int*, long long int, long long int);

int main() {
  long int n;
  long long int *x,*t;
  cin>>n;
  t = new long long int[n];
  x = new long long int[n];

  for(int i=0;i<n;i++){
    cin>>t[i]>>x[i];
  }
  
  quickSort(t, x, 0, n-1);

  double max = 0;
  for(int i=1;i<n;i++){
    if((double)abs(x[i]-x[i-1])/ (double)abs(t[i]-t[i-1])>max){
      max=(double)abs(x[i]-x[i-1])/ (double)abs(t[i]-t[i-1]);
    }
  }

  cout<<fixed<<setprecision(10)<<max<<endl;
}

void swap(long long int *a, long long int *b) {
	long long int t = *a;
	*a = *b;
	*b = t;
}

void quickSort(long long int arr[], long long int arr2[], long long int min, long long int max) {
	if (min < max) {
		//split
		long long int pivot = arr[max];
		long long int selected_element = min - 1;
		for ( long long int ptr = min; ptr < max; ptr++) {
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

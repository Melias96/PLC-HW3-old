#include <iostream>
#include <ctime>
using namespace std;

void sarray(){
  std::clock_t starttime, endtime;
  int arr[9000];
  starttime = clock();
  cout<<"Static Array \n";
  for(int i=0; i<9000; i++) {
    arr[i] = i;
  }
  endtime = clock();
  cout<<"Total time taken = "<< (endtime - starttime);
}
void sdynamic_array(){
  std::clock_t starttime, endtime;
  int N= 9000;
  int *arr = (int *) alloca(sizeof(int) * N);
  starttime = clock();
  cout<<"Stack Dynamic Array \n";
  for(int i=0; i<9000; i++) {
    arr[i] = i;
  }
  endtime = clock();
  cout<<"Total time taken = "<< (endtime - starttime);
}
void hdynamic_array(){
  std::clock_t starttime, endtime;
  int *arr = new int[9000];
  starttime = clock();
  cout<<"Heap Dynamic Array \n";
  for(int i=0; i<9000; i++) {
    arr[i] = i;
  }
  endtime = clock();
  cout<<"Total time taken = "<< (endtime - starttime);
}
int main(){
  sarray();
  cout<<"\n\n";
  sdynamic_array();
  cout<<"\n\n";
  hdynamic_array();
  cout<<"\n";
  return 0;
}

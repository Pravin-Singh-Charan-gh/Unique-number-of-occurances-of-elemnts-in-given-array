#include <iostream>
#include <vector>
#include <iterator>
using namespace std;

bool checknum(vector<int>v,int num){
    for(int i:v)
    if(i==num)return 1;
    return 0;
}

bool check_distinct(vector<int>v2){
    vector<int>::iterator ptr,pur;
    for(ptr=v2.begin();ptr<v2.end();ptr++)
    for(pur=ptr+1;pur<v2.end();pur++)
    if(*ptr==*pur)return false;
    return true;
}

bool check_no_occ(int arr[],int n){
    vector<int>v1,v2;
    for(int i=0;i<n;i++){
        if(checknum(v1,arr[i]))
        continue;
        v1.push_back(arr[i]);
        int occ=0;
        for(int j=i; j<n; j++)
        if(arr[i]==arr[j])
        occ++;
        v2.push_back(occ);
    }
    return check_distinct(v2);
}

int main(){    
    // int arr[100];
    // for(int i=0;i<100;i++){
    int arr[]={1,2,2,3,3,3,4,4,4};
    //arr[i]=i*10;
    for(int i=0;i<sizeof(arr)/sizeof(arr[0]);i++)
    cout<<arr[i]<<" ";
    cout<<endl<<endl;
    cout<<check_no_occ(arr,sizeof(arr)/sizeof(arr[0]));
}

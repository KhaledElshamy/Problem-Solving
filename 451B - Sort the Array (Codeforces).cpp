#include <bits/stdc++.h>
using namespace std;
int main() {
	int n,flag=0,flag1=0,index1,index2,l;
	cin>>n;
	int a[n],b[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
		b[i]=a[i];
	}
	sort(a,a+n);
	if(n==1){
			cout<<"yes"<<endl;
			cout<<"1"<<" "<<"1"<<endl;
			return 0;
		}
	int start=0,end=n-1;
	while(true){
		if(a[start]==b[start])start++;
		if(a[end]==b[end])end--;
		if(a[start]!=b[start]&&a[end]!=b[end]){
			if(!flag1){
				index1=start;
				index2=end;
				flag1=1;
			}
			for(l=end;l>=index1;){
				if(a[start]==b[l]){
					start++;
					l--;
				}
				else {
					flag=1;
					break;
				}
			}
		}
		if(flag||l==index1-1)break;
		if(start==n-1&&!flag1)break;
	}
	if(!flag&&flag1){
		cout<<"yes"<<endl;
		cout<<index1+1<<" "<<index2+1<<endl;
	}
	else if(!flag&&!flag1){
		cout<<"yes"<<endl;
		cout<<"1"<<" "<<"1"<<endl;
	}
	else cout<<"no"<<endl;
	return 0;
}

# include<cstdio>

using namespace std;
long long int ans, x;


int main(){
	scanf("%lld", &x);
	ans = ((1+x)*x)/2;
	printf("%lld", ans);
	
	return 0;
}
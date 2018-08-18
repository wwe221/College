#include <iostream>
#include <stdio.h>
using namespace std;
/*회문만들기 문제의 경우 greedy 알고리즘을 이용하기 위해 시작점의 위치에서 이미 회문인 문자들은 제외한뒤 가장 가까운것들중 회문이 아닌것들을 먼저 바꾸는 형식으로 구현했다.
이미 회문인 문자들을 제외하기위해 check 변수와 p변수를 활용했다.
char 끼리 연산을 하게 되면 ASCII코드로 연산이 이루어지는데 알파뱃순으로 ASCII코드에 저장되 있기 때문에 두 문자에 - 연산한것에 절댓값을 취하게 되면 한문자에서 나머지 문자로 바꾸기 위한 비용이 나오게 된다.*/

int n , m;//총 문자 갯수,시작점
char input[500];//인풋을 저장하는 배열
int output = 0;//아웃풋
int check =0;//Greedy 하게 풀어나가기 위한 변수.
int p;//회문을 비교하기 위한 적잘한 가운대 값을 저장.

int minimum(int a,int b){//둘중 작은것을 리턴하는 함수
	if(a>b)
		return b;
	else
		return a;
}
int positive(int a){//인풋이 음수면 양수로 바꾸는 함수
	if(a<0)
		a=-a;
	return a;
}
void Greedy(){ //check에서 부터 p까지 
	int sub=0;
	for(int i = check; i <= p; i++ ) //문자를 바꾸고, 비용을 계산한다.
  {
    sub= positive(input[i] - input[n-1-i]);//두 문자의 차를 절대값으로 환산한다.
    output += minimum(sub,26 - sub);//위에서 계산한 값과 알파벳순에서 뒤로 센 값중 최소값을 구한다음 output에 더한다.
  }
  if(check < p)/*만약 check가 p 보다 작으면 보다 왼쪽에 위치한것이라고 보고 시작점과 check의 차이와 p의 차이중 최소값을 더하고 둘의 차를 또 더해준다. 아니라면 둘중 최소만 더해준다.
이는 커서를 옆으로 움직이는 연산 즉 >or<를 했을때 일어나는 비용을 계산하기 위함이다.*/
    output += minimum(positive(m - check), positive(m - p)) + (p- check);
  else if (check == p)
	  output += positive(m - p);
  else
	  output += minimum(positive(m - check), positive(m - p));
}
void main(){	

	cin>>n>>m; //입력
	m--;
	for(int i=0;i<n;i++){
		cin>>input[i];} //입력	
	p = n/2 - 1;

	if(n/2 <= m)//시작점이 가운대와 같거나 크면
		m = n - m-1;//시작점을 옮긴다.
  
	while(check < n/2 && input[check] == input[n-1-check])	//처음 문자가 회문인지 체크를 하고,맞으면 다음으로 넘어간다.좀더 greedy 하게 순서를 잡기 위해 사용된다.
		check++;
	while(p >=0 && input[p] == input[n-1-p] )	//회문인지 체크를 하기위한 적절한 중심점을 찾는다.
		p--;
	//
	
	Greedy();
	cout<<output<<endl;
	cin>>n;	
}
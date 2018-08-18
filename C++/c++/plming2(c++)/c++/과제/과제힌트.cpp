#include<iostream>
#include <string>
using namespace std;

// 한명의 학생에 대한 정보를 보관할 구조체
struct Student {
    int sNo;                 // 학번
    string name;             // 이름  
    int kor, eng, math;      // 국어, 영어, 수학 점수  
    float ave;               // 평균   
}; 
const int MAX_STUDENTS = 100;
Student students [ MAX_STUDENTS];

int   NumOfStd = 0;  // 현재까지 입력된 학생 수
void AddStudent (){
    if (MAX_STUDENTS == NumOfStd) {
        cout << "더 이상 입력 불가\n";
        return;
    }
    
    // 학생번호를 자동으로 입력
    students[NumOfStd].sNo = NumOfStd + 1;

    cout << "이름, 국어, 영어, 수학 점수를 입력하세요\n";
    cin >> students[NumOfStd].name >> students[NumOfStd].kor 
        >> students[NumOfStd].eng >> students[NumOfStd].math;

    // 입력 받은 학생 수를 증가
    ++NumOfStd;

    return;}

void ShowAll(){
	for(int i=0;i<NumOfStd;++i){
		cout<<students[i].sNo<<"\n"<<students[i].name<<"\n"<<students[i].kor<<"\n"<<students[i].eng<<"\n"<<students[i].math<<"\n"<<students[i].ave;}
	return ;}

void ModifyStudent ()
{   
  string strName;
  cout << "성적을 수정할 학생의 이름을 입력 입력하세요\n";
  cin >> strName;
  
	for(int i=0;i<NumOfStd;i++) 
  {	
	  if(strName==students[i].name){
	cout << "국어, 영어, 수학 점수를 입력하세요\n";
	cin >> students[i].kor >> students[i].eng >> students[i].math;
	return;}}
	cout<<strName<<"은(는) 수강학생 명단에 존재하지 않습니다\n";
}

int main()
{   
    while(1) {
        //메뉴 보여 주기
        cout << "----------- 메뉴 ----------\n";
        cout << "1. 학생 성적 추가\n";
        cout << "2. 전체 성적 보기\n";
        cout << "3. 학생 성적 수정\n";
        cout << "4. 프로그램 종료\n";
		cout <<"-----------------------------\n";
        int select;
        cin >> select; 
        
        // 선택된 값에 따라서 처리
        switch (select) {
		case 1:
            cout << "학생 성적 추가 선택\n";
            AddStudent();  
	     break;
        case 2:
	     cout << "전체 성적 보기 선택\n";
            ShowAll();
	     break;
        case 13:
	     cout << "학생 성적 수정\n";
            ModifyStudent ();
	     break;
		case 4:
    	     cout << "프로그램 종료 합니다.\n";
	     return 0; //브레이크하면 처음부터 다시 시작.
	 default:
  	     cout << "잘못된 선택\n";
	     break;
     }
	}}
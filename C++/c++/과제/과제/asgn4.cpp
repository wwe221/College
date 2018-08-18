#include<iostream>
#include <string>
#include<fstream>
using namespace std;

// 한명의 학생에 대한 정보를 보관할 구조체
struct Student {
	int sNo;
    string name;             // 이름
	string maj;				//학과
    int snumb, asgn, mid, fin;      // 과제, 중간, 기말 점수  
    int sum ;               // 총점  
};
const int MAX_STUDENTS = 100;
Student students [ MAX_STUDENTS];

int   NumOfStd = 0;  // 현재까지 입력된 학생 수
void regStudent (){ //학생등록
    if (MAX_STUDENTS == NumOfStd) {
        cout << "더 이상 입력 불가\n";
        return;
    }
    string str1, str2 , str3;
	ifstream fin;
	fin.open("c://student.txt");
	while (!fin.eof()){
		fin >> students[NumOfStd].name >> students[NumOfStd].snumb>> students[NumOfStd]. maj;
		cout <<students[NumOfStd].name<<"\t"<<students[NumOfStd].snumb<<"\t"<<	students[NumOfStd]. maj<<endl;

	// 학생번호를 자동으로 입력
		students[NumOfStd].sNo = NumOfStd + 1;
    // 입력 받은 학생 수를 증가
		++NumOfStd;}

    return;}
void AddStudent (){ //학생 추가
    if (MAX_STUDENTS == NumOfStd) {
        cout << "더 이상 입력 불가\n";
        return;
    }
    
    // 학생번호를 자동으로 입력
    students[NumOfStd].sNo = NumOfStd + 1;

    cout << "이름,학번,학과를 입력하시오";
    cin >> students[NumOfStd].name >> students[NumOfStd].snumb>> students[NumOfStd].maj;

    // 입력 받은 학생 수를 증가
    ++NumOfStd;

    return;}

void ShowAll(){ //정보 출력
	cout<<"이름\t학번\t학과\n";
	for(int i=0;i<NumOfStd;++i){
		cout<<students[i].name<<"\t"<<students[i].snumb<<"\t"<<students[i].maj<<endl;}
	return ;}

void regGrade() //성적 등록
{	string strName;
  cout << "성적을 입력할 학생의 이름을 입력 입력하세요\n";
  cin >> strName;
  
	for(int i=0;i<NumOfStd;i++) 
  {	
	  if(strName==students[i].name){
	cout << "과제, 중간, 기말 점수를 입력하세요\n";
	cin >> students[i].asgn >> students[i].mid >> students[i].fin;
	return;}}
	cout<<strName<<"은(는) 수강학생 명단에 존재하지 않습니다\n";
}

void ModifyStudent () //성적 수정.
{   
  string strName;
  cout << "성적을 수정할 학생의 이름을 입력 입력하세요\n";
  cin >> strName;
  
	for(int i=0;i<NumOfStd;i++) 
  {	
	  if(strName==students[i].name){
	cout << "과제, 중간, 기말 점수를 입력하세요\n";
	cin >> students[i].asgn >> students[i].mid >> students[i].fin;
	return;}}
	cout<<strName<<"은(는) 수강학생 명단에 존재하지 않습니다\n";
}
void ShowAll2(){ //전체 수강생 성적 출력
	cout<<"이름\t학번\t학과\t과제\t중간\t기말\t총점\n";
	for(int i=0;i<NumOfStd;++i){
		cout<<students[i].name<<"\t"<<students[i].snumb<<"\t"<<students[i].maj<<"\t"<<students[i].asgn<<"\t"<<students[i].mid<<"\t"<<students[i].fin;}
	return ;}
void indStuShow(){//개별학생출력
	string strName;
	cout<<"정보를 조회할 학생이름을 입력하시오\n";
	cin>>strName;
	for(int i=0;i<NumOfStd;i++) 
  {	
	  if(strName==students[i].name){
	cout<<"이름\t학번\t학과\t과제\t중간\t기말\t총점\n";
	cout<<students[i].sNo<<"\t"<<students[i].name<<"\t"<<students[i].maj<<"\t"<<students[i].asgn<<"\t"<<students[i].mid<<"\t"<<students[i].fin;
	return;}}
	cout<<strName<<"은(는) 수강학생 명단에 존재하지 않습니다\n";
}
void searchSum(){//총점이상 찾기
	int sum;
	cout<<"점수를 입력하세요\n";
	cin >>sum;
	for(int i=0;i<NumOfStd;i++) 
  {	
	  if(sum<=students[i].sum){
		cout<<"이름\t학번\t학과\t과제\t중간\t기말\t총점\n";
		cout<<students[i].sNo<<"\t"<<students[i].name<<"\t"<<students[i].maj<<"\t"<<students[i].asgn<<"\t"<<students[i].mid<<"\t"<<students[i].fin; 
	return;}}
	cout<<sum<<"점을 넘는 수강학생은 존재하지 않습니다\n";}
int main()
{   
    while(1) {
        //메뉴 보여 주기
        cout << "----------- 메뉴 ----------\n";
        cout << "	학생관리\n";
		cout << "	1. 학생 등록\n";
        cout << "	2. 학생 추가\n";
		cout << "	3. 학생 삭제\n";
		cout << "	4. 출력\n";
		cout << "	성적관리\n";
		cout << "	5. 성적 입력\n";
        cout << "	6. 성적 수정\n";
        cout << "	화면출력\n";
		cout << "	7. 전체 수강 학생 성적 출력\n";
		cout << "	8. 개별 학생 정보 출력\n";
		cout << "	9. 총점 이상 학생 검색\n";
		cout << "	10. 총점/이름/학번 순 정렬\n";
		cout << "	파일 출력\n";
		cout << "	11.전체 수강 학생 성적 출력\n";
		cout << "	12. 전체 수강 학생 정렬후 출력\n";
		cout << "	13.프로그램 종료\n";
		cout <<"-----------------------------\n";
        char select;
        cin >> select; 
        
        // 선택된 값에 따라서 처리
        switch (select) {
		case '1':
            cout << "학생 정보 등록 선택\n";
            regStudent();
			break;
		case '2':
			cout <<"학생 추가 선택\n";
			AddStudent();
		break;
		case '3':
			cout<<"학생 삭제 선택\n";
				break;
        case '4':
	     cout << "학생 정보 보기 선택\n";
            ShowAll();
	     break;
		case '5':
			cout << " 학생 성적 입력\n";
			regGrade();
			break;
		case '6':
	     cout << "학생 성적 수정\n";
            ModifyStudent ();
	     break;
		case '7':
			cout <<"전체 수강학생 성적 출력\n";
			ShowAll2();
			break;
		case '8':
			cout <<"개별 학생 정보 출력\n";
			indStuShow();
			break;
		case '9':
			cout <"총점 이상 학생 검색\n";
			break;
		case "10":
			cout <<"총점/이름/학번 순 정렬\n";
			break;
		case "11":
			cout <<" 전체 수강 학생 성적 출력\n";
			break;
		case "12":
			cout <<"전체 수강 학생 정렬후 출력\n";
			break;
		case "13":
    	     cout << "프로그램 종료 합니다.\n";
	     return 0; //브레이크하면 처음부터 다시 시작.
	 default:
  	     cout << "잘못된 선택\n";
	     break;
     }
	}}
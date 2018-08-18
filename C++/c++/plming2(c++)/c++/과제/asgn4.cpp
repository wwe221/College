#include<iostream>
#include <string>
#include<fstream>
using namespace std;

// �Ѹ��� �л��� ���� ������ ������ ����ü
struct Student {
	int sNo;
    string name;             // �̸�
	string maj;				//�а�
	int snumb, asgn, mid, fin;      // ����, �߰�, �⸻ ����  
    float sum ;               // ����  
};
const int MAX_STUDENTS = 100;
Student students [ MAX_STUDENTS];

int   NumOfStd = 0;  // ������� �Էµ� �л� ��
void regStudent (){ //�л����
    if (MAX_STUDENTS == NumOfStd) {
        cout << "�� �̻� �Է� �Ұ�\n";
        return;
    }
    string str1, str2 , str3;
	ifstream fin;
	fin.open("c://student.txt");
	while (!fin.eof()){
		fin >> students[NumOfStd].name >> students[NumOfStd].snumb>> students[NumOfStd]. maj;
		cout <<students[NumOfStd].name<<"\t"<<students[NumOfStd].snumb<<"\t"<<	students[NumOfStd]. maj<<endl;

	// �л���ȣ�� �ڵ����� �Է�
		students[NumOfStd].sNo = NumOfStd + 1;
    // �Է� ���� �л� ���� ����
		++NumOfStd;}

    return;}
void AddStudent (){ //�л� �߰�
    if (MAX_STUDENTS == NumOfStd) {
        cout << "�� �̻� �Է� �Ұ�\n";
        return;
    }
    
    // �л���ȣ�� �ڵ����� �Է�
    students[NumOfStd].sNo = NumOfStd + 1;

    cout << "�̸�,�й�,�а��� �Է��Ͻÿ�";
    cin >> students[NumOfStd].name >> students[NumOfStd].snumb>> students[NumOfStd].maj;

    // �Է� ���� �л� ���� ����
    ++NumOfStd;

    return;}
void delStu(){//�л� ����
	string strName;
	cout<<"������ �л��� �̸��� �Է��Ͻÿ�.\n";;
	cin >> strName;

	for(int i=0;i<NumOfStd;i++) 
  {	
	  if(strName==students[i].name){
		  students[i].name = students[NumOfStd-1].name;
		  students[i].snumb = students[NumOfStd-1].snumb;
		  students[i].maj = students[NumOfStd-1].maj;
		  students[i].asgn = students[NumOfStd-1].asgn;
		  students[i].mid = students[NumOfStd-1].mid;
		  students[i].fin = students[NumOfStd-1].fin;
		  students[i].sum = students[NumOfStd-1].sum;
		  cout<<"���������� �����Ǿ����ϴ�.\n";
			 NumOfStd--;
	  return ;}
	cout<<strName<<"��(��) �����л� ��ܿ� �������� �ʽ��ϴ�\n";}
}
void ShowAll(){ //���� ���
	cout<<"�̸�\t�й�\t�а�\n";
	for(int i=0;i<NumOfStd;++i){
		cout<<students[i].name<<"\t"<<students[i].snumb<<"\t"<<students[i].maj<<endl;}
	return ;}

void regGrade() //���� ���
{	string strName;
  cout << "������ �Է��� �л��� �̸��� �Է� �Է��ϼ���\n";
  cin >> strName;
  
	for(int i=0;i<NumOfStd;i++) 
  {	
	  if(strName==students[i].name){
	cout << "����, �߰�, �⸻ ������ �Է��ϼ���\n";
	cin >> students[i].asgn >> students[i].mid >> students[i].fin;
	students[i].sum = (students[i].asgn * 0.3) + (students[i].mid*0.3) + (students[i].fin*0.4);
	return;}}
	cout<<strName<<"��(��) �����л� ��ܿ� �������� �ʽ��ϴ�\n";
}

void ModifyStudent () //���� ����.
{   
  string strName;
  cout << "������ ������ �л��� �̸��� �Է� �Է��ϼ���\n";
  cin >> strName;
  
	for(int i=0;i<NumOfStd;i++) 
  {	
	  if(strName==students[i].name){
	cout << "����, �߰�, �⸻ ������ �Է��ϼ���\n";
	cin >> students[i].asgn >> students[i].mid >> students[i].fin;
	students[i].sum = (students[i].asgn * 0.3) + (students[i].mid*0.3) + (students[i].fin*0.4);
	return;}}
	cout<<strName<<"��(��) �����л� ��ܿ� �������� �ʽ��ϴ�\n";
}
void ShowAll2(){ //��ü ������ ���� ���
	cout<<"�̸�\t�й�\t�а�\t\t����\t�߰�\t�⸻\t����\n";
	for(int i=0;i<NumOfStd;++i){
		cout<<students[i].name<<"\t"<<students[i].snumb<<"\t"<<students[i].maj<<"\t"<<students[i].asgn<<"\t"<<students[i].mid<<"\t"<<students[i].fin<<"\t"<<students[i].sum <<"\n";}
	return ;}
void indStuShow(){//�����л����
	string strName;
	cout<<"������ ��ȸ�� �л��̸��� �Է��Ͻÿ�\n";
	cin>>strName;
	for(int i=0;i<NumOfStd;i++) 
  {	
	  if(strName==students[i].name){
	cout<<"�̸�\t�й�\t�а�\t\t����\t�߰�\t�⸻\t����\n";
	cout<<students[i].name<<"\t"<<students[i].snumb<<"\t"<<students[i].maj<<"\t"<<students[i].asgn<<"\t"<<students[i].mid<<"\t"<<students[i].fin<<"\n";
	return;}}
	cout<<strName<<"��(��) �����л� ��ܿ� �������� �ʽ��ϴ�\n";
}
void searchSum(){//�����̻� ã��
	int sum;
	cout<<"������ �Է��ϼ���\n";
	cin >>sum;
	while(int a=0<NumOfStd){
		for(int i=0;i<NumOfStd;i++) 
  {	
	  if(sum<=students[i].sum){
		cout<<"�̸�\t�й�\t�а�\t\t����\t�߰�\t�⸻\t����\n";
		cout<<students[i].name<<"\t"<<<<students[i].maj<<"\t"<<students[i].asgn<<"\t"<<students[i].mid<<"\t"<<students[i].fin<<"\t"<<students[i].sum<<"\n"; 
		}}a++;return;}
	cout<<sum<<"���� �Ѵ� �����л��� �������� �ʽ��ϴ�\n";}
void searchLine(){//����
	string str;
	cout<<"����/�̸�/�й� �� ����� �����Ͻðڽ��ϱ�?\n";
	cin>>str;
	if(str=="����"){
	int f = 0;
	while(f<NumOfStd){
	int i = 0;
	string a;
	int b = 0;
	int c = 0;
	while(i<NumOfStd-1){
		if(students[i].sum<students[i+1].sum){
			b= students[i].sum;
			students[i].sum=students[i+1].sum;
			students[i+1].sum= b;
			a= students[i].name;
			students[i].name=students[i+1].name;
			students[i+1].name= a;
			b= students[i].snumb;
			students[i].snumb=students[i+1].snumb;
			students[i+1].snumb= b;
			a= students[i].maj;
			students[i].maj=students[i+1].maj;
			students[i+1].maj= a;
			b= students[i].asgn;
			students[i].asgn=students[i+1].asgn;
			students[i+1].asgn= b;
			b= students[i].mid;
			students[i].mid=students[i+1].mid;
			students[i+1].mid= b;
			b= students[i].fin;
			students[i].fin=students[i+1].fin;
			students[i+1].fin= b;}i++;}	f++;}
	cout<<"�̸�\t�й�\t�а�\t\t����\t�߰�\t�⸻\t����\n";
	for(int i=0;i<NumOfStd;++i){
		cout<<students[i].name<<"\t"<<students[i].snumb<<"\t"<<students[i].maj<<"\t"<<students[i].asgn<<"\t"<<students[i].mid<<"\t"<<students[i].fin<<"\t"<<students[i].sum <<"\n";}
	return ;}
	if(str=="�̸�"){
		int f = 0;
	while(f<NumOfStd){
	int i = 0;
	string a;
	int b = 0;
	int c = 0;
	while(i<NumOfStd-1){
		if(students[i].name>students[i+1].name){
			b= students[i].sum;
			students[i].sum=students[i+1].sum;
			students[i+1].sum= b;
			a= students[i].name;
			students[i].name=students[i+1].name;
			students[i+1].name= a;
			b= students[i].snumb;
			students[i].snumb=students[i+1].snumb;
			students[i+1].snumb= b;
			a= students[i].maj;
			students[i].maj=students[i+1].maj;
			students[i+1].maj= a;
			b= students[i].asgn;
			students[i].asgn=students[i+1].asgn;
			students[i+1].asgn= b;
			b= students[i].mid;
			students[i].mid=students[i+1].mid;
			students[i+1].mid= b;
			b= students[i].fin;
			students[i].fin=students[i+1].fin;
			students[i+1].fin= b;}i++;}	f++;}
	cout<<"�̸�\t�й�\t�а�\t\t����\t�߰�\t�⸻\t����\n";
	for(int i=0;i<NumOfStd;++i){
		cout<<students[i].name<<"\t"<<students[i].snumb<<"\t"<<students[i].maj<<"\t"<<students[i].asgn<<"\t"<<students[i].mid<<"\t"<<students[i].fin<<"\t"<<students[i].sum <<"\n";}
	return ;}
	if(str=="�й�"){
		int f = 0;
	while(f<NumOfStd){
	int i = 0;
	string a;
	int b = 0;
	int c = 0;
	while(i<NumOfStd-1){
		if(students[i].snumb>students[i+1].snumb){
			b= students[i].sum;
			students[i].sum=students[i+1].sum;
			students[i+1].sum= b;
			a= students[i].name;
			students[i].name=students[i+1].name;
			students[i+1].name= a;
			b= students[i].snumb;
			students[i].snumb=students[i+1].snumb;
			students[i+1].snumb= b;
			a= students[i].maj;
			students[i].maj=students[i+1].maj;
			students[i+1].maj= a;
			b= students[i].asgn;
			students[i].asgn=students[i+1].asgn;
			students[i+1].asgn= b;
			b= students[i].mid;
			students[i].mid=students[i+1].mid;
			students[i+1].mid= b;
			b= students[i].fin;
			students[i].fin=students[i+1].fin;
			students[i+1].fin= b;}i++;}	f++;}
	cout<<"�̸�\t�й�\t�а�\t\t����\t�߰�\t�⸻\t����\n";
	for(int i=0;i<NumOfStd;++i){
		cout<<students[i].name<<"\t"<<students[i].snumb<<"\t"<<students[i].maj<<"\t"<<students[i].asgn<<"\t"<<students[i].mid<<"\t"<<students[i].fin<<"\t"<<students[i].sum <<"\n";}
	return ;}
}
void save1(){
	cout<<"C����̺� �ȿ� ������ ���� �̸��� �Է��ϼ���\n";
	string q;
	cin>>q;
	ofstream fout;
	fout.open("C:\\"+q+".txt");
	for(int i=0;i<NumOfStd;++i){
		fout<<students[i].name<<"\t"<<students[i].snumb<<"\t"<<students[i].maj<<"\t"<<students[i].asgn<<"\t"<<students[i].mid<<"\t"<<students[i].fin<<"\t"<<students[i].sum <<"\n";}
	fout.close();
	cout<<"������ �Ϸ��Ͽ����ϴ�.\n";}

void save2(){
	string str;
	cout<<"����/�̸�/�й� �� ����� �����Ͻðڽ��ϱ�?\n";
	cin>>str;
	if(str=="����"){
	int f = 0;
	while(f<NumOfStd){
	int i = 0;
	string a;
	int b = 0;
	int c = 0;
	while(i<NumOfStd-1){
		if(students[i].sum<students[i+1].sum){
			b= students[i].sum;
			students[i].sum=students[i+1].sum;
			students[i+1].sum= b;
			a= students[i].name;
			students[i].name=students[i+1].name;
			students[i+1].name= a;
			b= students[i].snumb;
			students[i].snumb=students[i+1].snumb;
			students[i+1].snumb= b;
			a= students[i].maj;
			students[i].maj=students[i+1].maj;
			students[i+1].maj= a;
			b= students[i].asgn;
			students[i].asgn=students[i+1].asgn;
			students[i+1].asgn= b;
			b= students[i].mid;
			students[i].mid=students[i+1].mid;
			students[i+1].mid= b;
			b= students[i].fin;
			students[i].fin=students[i+1].fin;
			students[i+1].fin= b;}i++;}	f++;}
	cout<<"�̸�\t�й�\t�а�\t\t����\t�߰�\t�⸻\t����\n";
	for(int i=0;i<NumOfStd;++i){
		cout<<students[i].name<<"\t"<<students[i].snumb<<"\t"<<students[i].maj<<"\t"<<students[i].asgn<<"\t"<<students[i].mid<<"\t"<<students[i].fin<<"\t"<<students[i].sum <<"\n";}
	}
	if(str=="�̸�"){
		int f = 0;
	while(f<NumOfStd){
	int i = 0;
	string a;
	int b = 0;
	int c = 0;
	while(i<NumOfStd-1){
		if(students[i].name>students[i+1].name){
			b= students[i].sum;
			students[i].sum=students[i+1].sum;
			students[i+1].sum= b;
			a= students[i].name;
			students[i].name=students[i+1].name;
			students[i+1].name= a;
			b= students[i].snumb;
			students[i].snumb=students[i+1].snumb;
			students[i+1].snumb= b;
			a= students[i].maj;
			students[i].maj=students[i+1].maj;
			students[i+1].maj= a;
			b= students[i].asgn;
			students[i].asgn=students[i+1].asgn;
			students[i+1].asgn= b;
			b= students[i].mid;
			students[i].mid=students[i+1].mid;
			students[i+1].mid= b;
			b= students[i].fin;
			students[i].fin=students[i+1].fin;
			students[i+1].fin= b;}i++;}	f++;}
	cout<<"�̸�\t�й�\t�а�\t\t����\t�߰�\t�⸻\t����\n";
	for(int i=0;i<NumOfStd;++i){
		cout<<students[i].name<<"\t"<<students[i].snumb<<"\t"<<students[i].maj<<"\t"<<students[i].asgn<<"\t"<<students[i].mid<<"\t"<<students[i].fin<<"\t"<<students[i].sum <<"\n";}
	}
	if(str=="�й�"){
		int f = 0;
	while(f<NumOfStd){
	int i = 0;
	string a;
	int b = 0;
	int c = 0;
	while(i<NumOfStd-1){
		if(students[i].snumb>students[i+1].snumb){
			b= students[i].sum;
			students[i].sum=students[i+1].sum;
			students[i+1].sum= b;
			a= students[i].name;
			students[i].name=students[i+1].name;
			students[i+1].name= a;
			b= students[i].snumb;
			students[i].snumb=students[i+1].snumb;
			students[i+1].snumb= b;
			a= students[i].maj;
			students[i].maj=students[i+1].maj;
			students[i+1].maj= a;
			b= students[i].asgn;
			students[i].asgn=students[i+1].asgn;
			students[i+1].asgn= b;
			b= students[i].mid;
			students[i].mid=students[i+1].mid;
			students[i+1].mid= b;
			b= students[i].fin;
			students[i].fin=students[i+1].fin;
			students[i+1].fin= b;}i++;}	f++;}
	cout<<"�̸�\t�й�\t�а�\t\t����\t�߰�\t�⸻\t����\n";
	for(int i=0;i<NumOfStd;++i){
		cout<<students[i].name<<"\t"<<students[i].snumb<<"\t"<<students[i].maj<<"\t"<<students[i].asgn<<"\t"<<students[i].mid<<"\t"<<students[i].fin<<"\t"<<students[i].sum <<"\n";}
	}
	cout<<"C����̺� �ȿ� ������ ���� �̸��� �Է��ϼ���\n";
	string q;
	cin>>q;
	ofstream fout;
	fout.open("C:\\"+q+".txt");
	for(int i=0;i<NumOfStd;++i){
		fout<<students[i].name<<"\t"<<students[i].snumb<<"\t"<<students[i].maj<<"\t"<<students[i].asgn<<"\t"<<students[i].mid<<"\t"<<students[i].fin<<"\t"<<students[i].sum <<"\n";}
	fout.close();
	cout<<"������ �Ϸ��Ͽ����ϴ�.\n";}

int main()
{   
    while(1) {
        //�޴� ���� �ֱ�
        cout << "----------- �޴� ----------\n";
        cout << "	�л�����\n";
		cout << "	1. �л� ���\n";
        cout << "	2. �л� �߰�\n";
		cout << "	3. �л� ����\n";
		cout << "	4. ���\n";
		cout << "	��������\n";
		cout << "	5. ���� �Է�\n";
        cout << "	6. ���� ����\n";
        cout << "	ȭ�����\n";
		cout << "	7. ��ü ���� �л� ���� ���\n";
		cout << "	8. ���� �л� ���� ���\n";
		cout << "	9. ���� �̻� �л� �˻�\n";
		cout << "	a. ����/�̸�/�й� �� ����\n";
		cout << "	���� ���\n";
		cout << "	b.��ü ���� �л� ���� ���\n";
		cout << "	c. ��ü ���� �л� ������ ���\n";
		cout << "	Q.���α׷� ����\n";
		cout <<"-----------------------------\n";
        char select;
        cin >> select; 
        
        // ���õ� ���� ���� ó��
        switch (select) {
		case '1':
            cout << "�л� ���� ��� ����\n";
            regStudent();
			break;
		case '2':
			cout <<"�л� �߰� ����\n";
			AddStudent();
		break;
		case '3':
			cout<<"�л� ���� ����\n";
			delStu();
				break;
        case '4':
	     cout << "�л� ���� ���� ����\n";
            ShowAll();
	     break;
		case '5':
			cout << " �л� ���� �Է�\n";
			regGrade();
			break;
		case '6':
	     cout << "�л� ���� ����\n";
            ModifyStudent ();
	     break;
		case '7':
			cout <<"��ü �����л� ���� ���\n";
			ShowAll2();
			break;
		case '8':
			cout <<"���� �л� ���� ���\n";
			indStuShow();
			break;
		case '9':
			cout <<"���� �̻� �л� �˻�\n";
			searchSum();
			break;
		case 'a':
			cout <<"����/�̸�/�й� �� ����\n";
			searchLine();
			break;
		case 'b':
			cout <<" ��ü ���� �л� ���� ���\n";
			save1();
			break;
		case 'c':
			cout <<"��ü ���� �л� ������ ���\n";
			save2();
			break;
		case 'Q':
    	     cout << "���α׷� ���� �մϴ�.\n";
	     return 0; //�극��ũ�ϸ� ó������ �ٽ� ����.
	 default:
  	     cout << "�߸��� ����\n";
	     break;
     }
	}}
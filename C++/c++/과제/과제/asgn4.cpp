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
    int sum ;               // ����  
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
	return;}}
	cout<<strName<<"��(��) �����л� ��ܿ� �������� �ʽ��ϴ�\n";
}
void ShowAll2(){ //��ü ������ ���� ���
	cout<<"�̸�\t�й�\t�а�\t����\t�߰�\t�⸻\t����\n";
	for(int i=0;i<NumOfStd;++i){
		cout<<students[i].name<<"\t"<<students[i].snumb<<"\t"<<students[i].maj<<"\t"<<students[i].asgn<<"\t"<<students[i].mid<<"\t"<<students[i].fin;}
	return ;}
void indStuShow(){//�����л����
	string strName;
	cout<<"������ ��ȸ�� �л��̸��� �Է��Ͻÿ�\n";
	cin>>strName;
	for(int i=0;i<NumOfStd;i++) 
  {	
	  if(strName==students[i].name){
	cout<<"�̸�\t�й�\t�а�\t����\t�߰�\t�⸻\t����\n";
	cout<<students[i].sNo<<"\t"<<students[i].name<<"\t"<<students[i].maj<<"\t"<<students[i].asgn<<"\t"<<students[i].mid<<"\t"<<students[i].fin;
	return;}}
	cout<<strName<<"��(��) �����л� ��ܿ� �������� �ʽ��ϴ�\n";
}
void searchSum(){//�����̻� ã��
	int sum;
	cout<<"������ �Է��ϼ���\n";
	cin >>sum;
	for(int i=0;i<NumOfStd;i++) 
  {	
	  if(sum<=students[i].sum){
		cout<<"�̸�\t�й�\t�а�\t����\t�߰�\t�⸻\t����\n";
		cout<<students[i].sNo<<"\t"<<students[i].name<<"\t"<<students[i].maj<<"\t"<<students[i].asgn<<"\t"<<students[i].mid<<"\t"<<students[i].fin; 
	return;}}
	cout<<sum<<"���� �Ѵ� �����л��� �������� �ʽ��ϴ�\n";}
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
		cout << "	10. ����/�̸�/�й� �� ����\n";
		cout << "	���� ���\n";
		cout << "	11.��ü ���� �л� ���� ���\n";
		cout << "	12. ��ü ���� �л� ������ ���\n";
		cout << "	13.���α׷� ����\n";
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
			cout <"���� �̻� �л� �˻�\n";
			break;
		case "10":
			cout <<"����/�̸�/�й� �� ����\n";
			break;
		case "11":
			cout <<" ��ü ���� �л� ���� ���\n";
			break;
		case "12":
			cout <<"��ü ���� �л� ������ ���\n";
			break;
		case "13":
    	     cout << "���α׷� ���� �մϴ�.\n";
	     return 0; //�극��ũ�ϸ� ó������ �ٽ� ����.
	 default:
  	     cout << "�߸��� ����\n";
	     break;
     }
	}}
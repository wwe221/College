#include<iostream>
#include <string>
using namespace std;

// �Ѹ��� �л��� ���� ������ ������ ����ü
struct Student {
    int sNo;                 // �й�
    string name;             // �̸�  
    int kor, eng, math;      // ����, ����, ���� ����  
    float ave;               // ���   
}; 
const int MAX_STUDENTS = 100;
Student students [ MAX_STUDENTS];

int   NumOfStd = 0;  // ������� �Էµ� �л� ��
void AddStudent (){
    if (MAX_STUDENTS == NumOfStd) {
        cout << "�� �̻� �Է� �Ұ�\n";
        return;
    }
    
    // �л���ȣ�� �ڵ����� �Է�
    students[NumOfStd].sNo = NumOfStd + 1;

    cout << "�̸�, ����, ����, ���� ������ �Է��ϼ���\n";
    cin >> students[NumOfStd].name >> students[NumOfStd].kor 
        >> students[NumOfStd].eng >> students[NumOfStd].math;

    // �Է� ���� �л� ���� ����
    ++NumOfStd;

    return;}

void ShowAll(){
	for(int i=0;i<NumOfStd;++i){
		cout<<students[i].sNo<<"\n"<<students[i].name<<"\n"<<students[i].kor<<"\n"<<students[i].eng<<"\n"<<students[i].math<<"\n"<<students[i].ave;}
	return ;}

void ModifyStudent ()
{   
  string strName;
  cout << "������ ������ �л��� �̸��� �Է� �Է��ϼ���\n";
  cin >> strName;
  
	for(int i=0;i<NumOfStd;i++) 
  {	
	  if(strName==students[i].name){
	cout << "����, ����, ���� ������ �Է��ϼ���\n";
	cin >> students[i].kor >> students[i].eng >> students[i].math;
	return;}}
	cout<<strName<<"��(��) �����л� ��ܿ� �������� �ʽ��ϴ�\n";
}

int main()
{   
    while(1) {
        //�޴� ���� �ֱ�
        cout << "----------- �޴� ----------\n";
        cout << "1. �л� ���� �߰�\n";
        cout << "2. ��ü ���� ����\n";
        cout << "3. �л� ���� ����\n";
        cout << "4. ���α׷� ����\n";
		cout <<"-----------------------------\n";
        int select;
        cin >> select; 
        
        // ���õ� ���� ���� ó��
        switch (select) {
		case 1:
            cout << "�л� ���� �߰� ����\n";
            AddStudent();  
	     break;
        case 2:
	     cout << "��ü ���� ���� ����\n";
            ShowAll();
	     break;
        case 13:
	     cout << "�л� ���� ����\n";
            ModifyStudent ();
	     break;
		case 4:
    	     cout << "���α׷� ���� �մϴ�.\n";
	     return 0; //�극��ũ�ϸ� ó������ �ٽ� ����.
	 default:
  	     cout << "�߸��� ����\n";
	     break;
     }
	}}
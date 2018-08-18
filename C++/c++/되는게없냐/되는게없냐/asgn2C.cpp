#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

struct StudentInfo {
    int    stdnumber;
    double grade; 
};
int main() {

    const int arraySize = 30;
    StudentInfo stdInfo[arraySize]; 
    StudentInfo* pInfo[arraySize];

    srand((unsigned)time(0));

    for (int i=0; i<arraySize; ++i) {
        pInfo[i] = &stdInfo[i];    }

    for (int i=0; i<arraySize; ++i) {
        pInfo[i]->grade = rand()%5 + ((double)rand()/(2*RAND_MAX));
        pInfo[i]->stdnumber = rand();
    }

    cout << "Before Sorting: " << endl;
    cout << "StudnetNumber" << "\t" << "Grade" << endl;

    for (int i=0; i<arraySize; ++i) {
        cout << pInfo[i]->stdnumber <<  "\t\t" << pInfo[i]->grade << endl;
    }
	
	int f = 0 ;
	while(f<arraySize){
	int n = 0;
	double b = 0;
	while(n<arraySize-1){
		if(pInfo[n]->grade<pInfo[n+1]->grade)
		{
			b= pInfo[n]->grade;
			pInfo[n]->grade=pInfo[n+1]->grade;
			pInfo[n+1]->grade= b;

			b= pInfo[n]->stdnumber;
			pInfo[n]->stdnumber=pInfo[n+1]->stdnumber;
			pInfo[n+1]->stdnumber= b;		
			
		}
		n++;}
		f++;}

	cout << "After Sorting: " << endl;
    cout << "StudnetNumber" << "\t" << "Grade" << endl;

    for (int i=0; i<arraySize; ++i) {
        cout << pInfo[i]->stdnumber <<  "\t\t" <<pInfo[i]->grade << endl;
    }
	
    return 0;
}
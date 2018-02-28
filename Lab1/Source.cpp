#include <iostream>
#include <cstdlib>
#include <iomanip>

using namespace std;

void main() {
	srand(time(NULL));
	int N, tCome, tIntService1, tTotalCome = 0, tTotalStartService1 = 0, tTotalEndService1 = 0, tWait = 0, tStay = 0, sumWait1 = 0, sumStay = 0, sumWait2 = 0, sumStay2 = 0;
	int tIntService2, tTotalCome2 = 0, tTotalStartService2 = 0, tTotalEndService2 = 0, tStay2 = 0, tWait2 = 0;
	cout << "Input tasks number:";
	cin >> N;
	cout << setw(13) << "Iteration |" << setw(8) << " Tic |" << setw(8) << "Tis |" << setw(8) << "Tc |" << setw(8) << "Tss |" << setw(8) << "Tes |" << setw(15) << "Waiting 1st |" << setw(13) << " Stay 1st |" << setw(8) << "Tis2 |" << setw(8) << "Tss2 |" << setw(8) << "Tes2 |" << setw(15) << "Waiting 2nd |" << setw(11) << " Stay 2nd" << endl;
	for (int i = 0; i < N; i++) {
		//first computer

		tCome = rand() % 9 + 1;
		tIntService1 = rand() % 5 + 1;
		tTotalCome += tCome;
		if (tTotalCome > tTotalEndService1) tTotalStartService1 = tTotalCome; 
		else tTotalStartService1 = tTotalEndService1;
		tWait = tTotalStartService1 - tTotalCome;
		if (tTotalCome >= tTotalEndService1) tStay = tTotalCome - tTotalEndService1; else tStay = 0;
		tTotalEndService1 = tTotalStartService1 + tIntService1;
		sumStay += tStay;
		sumWait1 += tWait;

		//second cumputer
		tIntService2 = rand() % 5 + 1;
		if (tTotalEndService1 > tTotalEndService2) tTotalStartService2 = tTotalEndService1;
		else tTotalStartService2 = tTotalEndService2;
		tWait2 = tTotalStartService2 - tTotalEndService1;
		if (tTotalEndService1 >= tTotalEndService2) tStay2 = tTotalEndService1 - tTotalEndService2; else tStay2 = 0;
		tTotalEndService2 = tTotalStartService2 + tIntService2;
		sumStay2 += tStay2;
		sumWait2 += tWait2;
		
		cout << setw(12) << i << "|" << setw(7) << tCome << "|" << setw(7) << tIntService1 << "|" << setw(7) << tTotalCome << "|" << setw(7) << tTotalStartService1 << "|" << setw(7) << tTotalEndService1 << "|" << setw(14) << tWait << "|" << setw(12) << tStay << "|" << setw(7) << tIntService2 << "|" << setw(7) << tTotalStartService2 << "|" << setw(7) << tTotalEndService2 << "|" << setw(14) << tWait2 << "|" << setw(10) << tStay2 << endl;

	}

	cout << "Waiting time in queue - " << sumWait1 << endl;
	cout << "Downtime of the first computer - " << sumStay << endl;
	cout << "Waiting time before second computer - " << sumWait2 << endl;
	cout << "Downtime of the second computer - " << sumStay2 << endl;
	system("pause");
}
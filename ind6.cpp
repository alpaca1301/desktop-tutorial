#include <iostream>
#include <iomanip>
#include <cstring>
#include <stdlib.h>
using namespace std;
int main()
{
	setlocale(LC_ALL, "rus");
	bool minus = false, 
		is8Digit;
	bool abc = false;
	char ch;
	double chislo = 0.0, ves;
	const int Len = 11;
	char InputString[Len]{'\0'};
	char OutputString[Len]{'\0'};
	short int cifra, i;
	i=0;
	cin.get(ch);
	//cout << ch;
	switch (ch) {
		case '+':
		case '-': minus = ch=='-';
			InputString[i++]=ch;
			cin.get(ch); cin.get(ch); 
			break;
		default:
			cin.get(ch);
	}
	strcat(InputString, "0.");
	i=i+2;
	ves = 1.0/8.0;
	cin.get(ch);
	if (ch>='0'&& ch<='7') {
		is8Digit = ch>='0'&& ch<='7';
		abc = true;}
	else{
		abc = false;
		cout << "������� ������� �����";
		return 0;
}
	if (abc==true) {
		while (is8Digit) {
			InputString[i++]=ch;
				if (ch>='0' && ch<='7') {
					cifra=ch-48;
					chislo = chislo + cifra*ves;
			}
			ves = ves/8.0;
			cin.get(ch);
			if (ch=='8' || ch=='9'||ch>='a'){
				cout<<ch<<" uzhas ";
				abc = false;
				cout << "������� ������� �����";
				return 0;}
			is8Digit = (ch>='0'&&ch<='7');
}
		if (minus) chislo = -chislo; 
		cout << "\n���������"
				"\n\t�� ����� ������ � 8� ��: " << InputString << "\n\t�� ������ ����� � 10� ��: " << fixed << chislo;
		if (chislo >= 1.0){
			cout << "����� >= 1.0?!:" << chislo;
			return 0;
	}
	
		char OutputStirng[Len] {};
		i=0;
		cout << "\n\n�������� ��������������: ����� �� 10� �� � ������ � 8� ��";
		cout << "\n\t�� ����� �����: " << chislo;
		if (chislo<0) {
			OutputString[i++]='-';
			chislo = -chislo;
	}
		strcat(OutputString, "0.");
		i=i+2;
		short int countCifr=1;
		do {
			cifra = chislo*8;
			if (cifra<=7)
				OutputString[i++]=cifra+48;
			chislo = chislo*8 - cifra;
			countCifr++;	
	} 	while (chislo!=0 && countCifr<10);
		OutputStirng[i]=0;
		cout << "\n\t�� ������ ������ � 8 ��: " << OutputString;
		cout << "\n\n�������� ������ � ���������� ���������? " << boolalpha << bool (!strcmp(InputString, OutputString));
	return 0;
}}



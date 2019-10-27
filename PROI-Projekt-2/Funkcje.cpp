#include "Funkcje.h"

int wyborMenu()
{
	while (1)
	{
		string ciag;
		int wybor;
		cin >> ciag;
		int i;
		int n = ciag.length();
		for (i = 0; i<n; i++)
			if (!isdigit(ciag[i])) break;
		if (i == n)
		{
			istringstream iss(ciag);
			iss >> wybor;
			return wybor;
		}
		else cout << "Niepoprawny wybor. Wybierz cyfre z przedzialu <1,6>\n" << endl;
	}
}

void clrscr()
{
	cin.sync();
	/*system("cls");*/
	for(int i=0;i<25;i++)
	cout<<"\n";
}
/*
void clrscr2()
{
printf("\033[2J"); // Czysci ekran
printf("\033[0;0f"); // Ustawia kursor w lewym, gornym rogu
}*/
void get()
{
	cin.ignore(1024, '\n');
	cout << "";
	cin.get();
}

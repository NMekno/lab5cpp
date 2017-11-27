#include <iostream>
#include "Data.h"
#include "Napis.h"
#include "Pracownik.h"
#include "ListaPracownikow.h"
using namespace std;

int main()
{
	// Variables
	char nazwisko[40];
	char imie[40];
	int wybor = 0;
	ListaPracownikow employeeList;
	Pracownik* pracownik_nr1;

	// User console interface

	while (1)
	{
		wybor = 0;
		cout << "-------------- Menu --------------" << endl;
		cout << "(1) add new employee" << endl;
		cout << "(2) delete chosen employee" << endl;
		cout << "(3) print whole employees list" << endl;
		cout << "(4) search employees list" << endl;
		cout << "(5) delete list" << endl;
		cout << "(6) exit" << endl;

		cout << "Choose option: ";	// user chooses
		cin >> wybor;

		switch (wybor)
		{
		case 1:				// (1) add new employee
			cin.clear();
			pracownik_nr1 = new Pracownik;
			pracownik_nr1->Wpisz();
			employeeList.Dodaj(*pracownik_nr1);
			break;
		case 2:				// (2) delete chosen employee
			pracownik_nr1 = new Pracownik;
			pracownik_nr1->Wpisz();
			employeeList.Usun(*pracownik_nr1);
			break;
		case 3:				// (3) print whole employees list
			employeeList.WypiszPracownikow();
			break;
		case 4:				// (4) search employees list
			cout << "Podaj imie:";
			cin >> imie;
			cout << endl << "Podaj nazwisko:";
			cin >> nazwisko;
			employeeList.Szukaj(nazwisko, imie);
			break;
		case 5:				// (5) delete list
			employeeList.~ListaPracownikow();
			break;
		case 6:				// (6) exit
			employeeList.~ListaPracownikow();
			return 0;
			break;
		default:
			break;
		}
	}
	return 0;
}
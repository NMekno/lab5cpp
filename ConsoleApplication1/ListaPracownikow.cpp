#include "ListaPracownikow.h"
#include <iostream>
using namespace std;


ListaPracownikow::ListaPracownikow()
	:m_pPoczatek(NULL)
	,m_nLiczbaPracownikow(0)
{
	
}


ListaPracownikow::~ListaPracownikow()
{
	if (m_nLiczbaPracownikow > 0)
	{
		Pracownik* pomoc = m_pPoczatek;
		Pracownik* nastepny = NULL;
	
		while (pomoc->m_Nastepny != nullptr)
		{
			nastepny = pomoc->m_Nastepny;
			delete pomoc;
			pomoc = nastepny;
		}
		delete nastepny;
	}	
	//ListaPracownikow();
}

void ListaPracownikow::Dodaj(const Pracownik & p)
{
	Pracownik* nowy = new Pracownik;
	bool czy_poczatek = false;
	*nowy = p;
	Pracownik *pomoc = NULL;
	Pracownik *poprzedni = m_pPoczatek;
	Pracownik *poprzedni1 = m_pPoczatek;
	if (m_nLiczbaPracownikow == 0)
	{
		m_pPoczatek = nowy;
		m_nLiczbaPracownikow++;
		czy_poczatek = true;
	}

	else if (m_nLiczbaPracownikow == 1 && !czy_poczatek)
	{
		if (poprzedni->Porownaj(p) == 0)
		{
			cout << "Taki pracownik juz istnieje." << endl;
		}
		else if (poprzedni->Porownaj(p) > 0)
		{
			nowy->m_Nastepny = m_pPoczatek;
			m_pPoczatek = nowy;
			m_nLiczbaPracownikow++;
		}
		else
		{
			m_pPoczatek->m_Nastepny = nowy;
			m_nLiczbaPracownikow++;
		}
	}
	else
	{
		pomoc = m_pPoczatek->m_Nastepny;
		while (pomoc != NULL)
		{
			cout << "Petla";
			if (poprzedni->Porownaj(p) == 0)
			{
				cout << "Taki pracownik juz istnieje." << endl;
				break;
			}
			else if (poprzedni->Porownaj(p) < 0)
			{
				poprzedni1 = poprzedni;
				poprzedni = poprzedni->m_Nastepny;
				pomoc = pomoc->m_Nastepny;
				if (pomoc == NULL)
				{
					poprzedni->m_Nastepny = nowy;
					m_nLiczbaPracownikow++;
					break;
				}
			}
			else if (poprzedni->Porownaj(p) > 0)
			{
				if (poprzedni == m_pPoczatek)
				{
					nowy->m_Nastepny = m_pPoczatek;
					m_pPoczatek = nowy;
					m_nLiczbaPracownikow++;
					break;
				}
				nowy->m_Nastepny = poprzedni;
				poprzedni1->m_Nastepny = nowy;
				m_nLiczbaPracownikow++;
				break;
			}

		}
	}
}
void ListaPracownikow::Usun(const Pracownik & wzorzec)
{
	Pracownik* pomoc = m_pPoczatek;
	Pracownik* poprzedni;
	if (pomoc != NULL)
	{
		if (pomoc->Porownaj(wzorzec) == 0)
		{
			m_pPoczatek = pomoc->m_Nastepny;
			delete pomoc;
			m_nLiczbaPracownikow--;
		}
		else
		{
			while (pomoc->m_Nastepny != NULL)
			{
				poprzedni = pomoc;
				pomoc = pomoc->m_Nastepny;
				if (pomoc->Porownaj(wzorzec) == 0)
				{
					poprzedni->m_Nastepny = pomoc->m_Nastepny;
					delete pomoc;
					m_nLiczbaPracownikow--;
					break;
				}
				else
					cout << "Nie znaleziono pracownika" << endl;
			}
		}
	}
	else
	{
		cout << "Nie znaleziono pracownika" << endl;
	}
	
}
void ListaPracownikow::WypiszPracownikow() const
{
	Pracownik* pomoc = m_pPoczatek;
	if (m_pPoczatek == NULL)
		;
	else {
		while (1)
		{
			pomoc->Wypisz();
			if (pomoc->m_Nastepny == NULL)
				break;
			pomoc = pomoc->m_Nastepny;
		}
	}
	
	
}
const Pracownik* ListaPracownikow::Szukaj(const char* nazwisko, const char* imie)
{
	Pracownik* nowy = m_pPoczatek;
	while (nowy->m_Nastepny != NULL)
	{
		if (nowy->SprawdzNazwisko(nazwisko) == 0 && nowy->SprawdzImie(imie) == 0)
		{
			cout << "Znaleziono pracownika" << endl;
			return nowy;
		}
		nowy = nowy->m_Nastepny;
	}
	if (nowy->SprawdzNazwisko(nazwisko) == 0 && nowy->SprawdzImie(imie) == 0)
	{
		cout << "Znaleziono pracownika" << endl;
		return nowy;
	}
}
#include "Pracownik.h"
using namespace std;


Pracownik::Pracownik()
	:m_Nastepny(nullptr)
{
	
}


Pracownik::~Pracownik()
{
}

const char* Pracownik::Imie() const
{
	return m_Imie.Zwroc();
}

const char* Pracownik::Nazwisko() const
{
	return m_Nazwisko.Zwroc();
}
void Pracownik::Imie(const char* nowe_imie)
{
	m_Imie.Ustaw(nowe_imie);
}
void Pracownik::Nazwisko(const char* nowe_nazwisko)
{
	m_Nazwisko.Ustaw(nowe_nazwisko);
}
void Pracownik::DataUrodzenia(int nowy_dzien, int nowy_miesiac, int nowy_rok)
{
	m_DataUrodzenia.Ustaw(nowy_dzien, nowy_miesiac, nowy_rok);
}
void Pracownik::Wypisz() const
{
	m_Imie.Wypisz();
	cout << "\t";
	m_Nazwisko.Wypisz();
	cout << "\t";
	m_DataUrodzenia.Wypisz();
	cout << endl;
}
void Pracownik::Wpisz() 
{
	cout << "Podaj imie pracownika: ";
	m_Imie.Wpisz();
	cout << "Podaj nazwisko pracownika: ";
	m_Nazwisko.Wpisz();
	cout << "Podaj date urodzin pracownika. \n";
	m_DataUrodzenia.Wpisz();
	m_DataUrodzenia.Koryguj();
}
int Pracownik::SprawdzImie(const char* por_imie) const
{
	return m_Imie.SprawdzNapis(por_imie);
}
int Pracownik::SprawdzNazwisko(const char* por_nazwisko) const
{
	int x;
	x = m_Nazwisko.SprawdzNapis(por_nazwisko);
	cout << x << endl;
	return m_Nazwisko.SprawdzNapis(por_nazwisko);
}
int Pracownik::Porownaj(const Pracownik &wzorzec) const
{
	if (m_Imie.SprawdzNapis(wzorzec.m_Imie.Zwroc()) == 0 
		&& m_Nazwisko.SprawdzNapis(wzorzec.m_Nazwisko.Zwroc()) == 0 
		&& m_DataUrodzenia.Porownaj(wzorzec.m_DataUrodzenia) == 0)
		return 0;
	else if (m_Imie.SprawdzNapis(wzorzec.m_Imie.Zwroc()) < 0 
		|| m_Nazwisko.SprawdzNapis(wzorzec.m_Nazwisko.Zwroc()) < 0 
		|| m_DataUrodzenia.Porownaj(wzorzec.m_DataUrodzenia) < 0)
		return 1;
	else
		return -1;
}
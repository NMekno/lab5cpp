#pragma once
#include"Napis.h"
#include "Data.h"
#include<iostream>


class Pracownik
{
	Napis m_Imie;
	Napis m_Nazwisko;
	Data m_DataUrodzenia;
	static const int id_Pracownika = 1;
public:	
	Pracownik* m_Nastepny;

	Pracownik();
	Pracownik(const Pracownik & wzor);
	~Pracownik();

	const char* Imie() const;
	const char* Nazwisko() const;
	void Imie(const char* nowe_imie);
	void Nazwisko(const char* nowe_nazwisko);
	void DataUrodzenia(int nowy_dzien, int nowy_miesiac, int nowy_rok);
	void Wypisz() const;
	void Wpisz();
	int SprawdzImie(const char* por_imie) const;
	int SprawdzNazwisko(const char* por_nazwisko) const;
	int Porownaj(const Pracownik &wzorzec) const;
	Pracownik & operator=(const Pracownik & wzor);
	bool operator==(const Pracownik & wzor);
	
	friend std::ostream & operator<<(std::ostream & wy,const Pracownik & p);
	friend std::ostream & operator>>(std::ostream & wy, const Pracownik & p);
};



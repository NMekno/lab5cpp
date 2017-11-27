#pragma once
#include"Pracownik.h"
class ListaPracownikow
{

	int m_nLiczbaPracownikow;
public:
	Pracownik* m_pPoczatek;
	ListaPracownikow();
	~ListaPracownikow();

	void Dodaj(const Pracownik & p);
	void Usun(const Pracownik & wzorzec);
	void WypiszPracownikow() const;
	const Pracownik* Szukaj(const char* nazwisko, const char* imie);
};


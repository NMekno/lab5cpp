#pragma once
class Data
{
	int m_nDzien;
	int m_nMiesiac;
	int m_nRok;
public:
	Data();
	~Data();
	void Ustaw(int d, int m, int r);
	int Dzien() const;
	int Miesiac() const;
	int Rok() const;
	void Wypisz() const;
	void Wpisz();
	void Koryguj();
	int Porownaj(const Data & wzor) const;
};


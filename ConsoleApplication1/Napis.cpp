#include "Napis.h"
#include<iostream>
using namespace std;

Napis::Napis()
{
}


Napis::~Napis()
{
}

const char* Napis::Zwroc() const
{
	return m_pszNapis;
}
void Napis::Ustaw(const char* nowy_napis)
{
	int i;
	for (i = 0; nowy_napis[i] != 0; i++)
	{
		m_pszNapis[i] = nowy_napis[i];
	}
	for (i; i < 40; i++)
	{
		m_pszNapis[i] = 0;
	}
}
void Napis::Wypisz() const
{
	for (int i = 0; m_pszNapis[i] != 0; i++)
	{
		cout << m_pszNapis[i];
	}
}
void Napis::Wpisz()
{
	cin >> m_pszNapis;
}
int Napis::SprawdzNapis(const char* por_napis) const
{

	for (int i = 0; m_pszNapis[i] != 0; i++)
	{
		if (m_pszNapis[i] < por_napis[i])
			return 1;
		else if (m_pszNapis[i] > por_napis[i])
			return -1;
		else
			return 0;
	}

	
}

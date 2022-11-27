#ifndef KULLANICI_H
#define KULLANICI_H
#include <string>
#include <iostream>
#include <iomanip>

using namespace std;

class Kullanici
{
public:
	Kullanici(string, string, string, int);

	string GetAdSoyad();
	string GetHesapAdi();
	string GetSifre();
	int GetId();
	
	void SetAdSoyad(string);
	void SetHesapAdi(string);
	void SetSifre(string);
	void SetId(int);
	
	bool SifreDogruMu(string,string);

private:
	string adSoyad;
	string hesapAdi;
	string sifre;
	int KullanicId;
};

#endif // !KULLANICI_H
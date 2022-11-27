#ifndef UYE_H
#define UYE_H
#include "Kullanici.h"
#include "Kitap.h"
#include <iostream>

using namespace std;

class Uye :public Kullanici
{
public:
	Uye(string = "Girilmedi", string = "Girilmedi", string = "temp", int = -1);
	void SetUyetipi(string);
	void SetKitapAlmaSayisi(int);
	void kitapArama(Kitap[]);
	void kitapOduncAlma(Kitap[]);
	void kitapIadeEt(Kitap[]);
	void kitapListele(Kitap[]);
	void uyelikIslemleri();
	int GetKitapAlmaSayisi();
	string GetUyetipi();

private:
	string uyeTipi;
	int kitapAlmaSayisi;
	int alinanKitapSayisi = 0;
};

#endif


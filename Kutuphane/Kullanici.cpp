#include "Kullanici.h"



Kullanici::Kullanici(string ad_Soyad, string hesap_Adi, string girilen_sifre, int girilen_id)
{
	adSoyad = ad_Soyad;
	hesapAdi = hesap_Adi;
	sifre = girilen_sifre;
	KullanicId = girilen_id;
}

string Kullanici::GetAdSoyad() { return adSoyad; }
string Kullanici::GetHesapAdi() { return hesapAdi; }
string Kullanici::GetSifre() { return sifre; }
int Kullanici::GetId() { return KullanicId; }

void Kullanici::SetAdSoyad(string ad_Soyad) { adSoyad = ad_Soyad; }
void Kullanici::SetHesapAdi(string hesap_Adi) { hesapAdi = hesap_Adi; }
void Kullanici::SetSifre(string girilen_sifre) { sifre = girilen_sifre; }
void Kullanici::SetId(int girilen_adi) { KullanicId = girilen_adi; }

bool Kullanici::SifreDogruMu(string hesap_Adi, string girilen_sifre)
{
	

	if (hesap_Adi == hesapAdi && girilen_sifre == sifre)
	{
		cout << "Sifre Kabul Edildi." << endl;
		return true;
	}

	else
	{
		
		cout << "Girilen sifre veya kullanici adi yanlis" << endl;
		return false;
	}
		
}
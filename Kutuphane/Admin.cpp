#include "Admin.h"



Admin::Admin(string adAdmin, string adminKullaniciAdi, string adminSifre, int adminNo):Kullanici(adAdmin,adminKullaniciAdi,adminSifre,adminNo)
{
	uyeSayisi = 0;
}

void Admin::uyeEkle(Uye uy[])
{
	
	string adSoyad;
	string hesapAdi;
	string uyeTipi;
	cout << "Uye bilgilerini girin" << endl;
	cout << "ad-soyad:";
	//getline(cin, adSoyad);
	cin >> adSoyad;
	cout << "Hesap adi:";
	//getline(cin, hesapAdi);
	cin >> hesapAdi;
	cout << "Uye Tipi:";
	//getline(cin, uyeTipi);
	cin >> uyeTipi;
	mevcutUyeSayisi(uy);
	

	for (int i = 0; uy[i].GetAdSoyad() != "Girilmedi"; i++)
	{
		if (uy[i].GetHesapAdi() == hesapAdi)
		{
			cout << "Bu hesap isminde bir uye kayitli. Tekrar deneyin" << endl;
			return;
		}
	}

	if (uyeTipi == "Ogrenci" || uyeTipi == "Personel" || uyeTipi == "OgretimElemani")
	{
		uy[uyeSayisi].SetAdSoyad(adSoyad); 
		uy[uyeSayisi].SetHesapAdi(hesapAdi);
		uy[uyeSayisi].SetId(uyeSayisi); 
		uy[uyeSayisi].SetUyetipi(uyeTipi);
		if (uyeTipi == "Ogrenci")
			uy[uyeSayisi].SetKitapAlmaSayisi(5);
		if (uyeTipi == "Personel")
			uy[uyeSayisi].SetKitapAlmaSayisi(3);
		if (uyeTipi == "OgretimElemani")
			uy[uyeSayisi].SetKitapAlmaSayisi(10);
		uyeSayisi++;
		cout << "Uye basariyla eklendi... " << endl;
	}

	else
	{
		cout << "Uye tipini yanlis girdiniz. Tekrar deneyin" << endl;
	}
}

void Admin::uyeSilme(Uye uy[])
{
	string hesapAdi;
	cout << "Silmek istediginiz hesap adini giriniz:";
	//getline(cin, hesapAdi);
	cin >> hesapAdi;
	int sayac = 0;
	int hesapId;
	for (int i = 0; uy[i].GetAdSoyad() != "Girilmedi"; i++)
	{
		if (uy[i].GetHesapAdi() == hesapAdi)
		{
			hesapId = uy[i].GetId();
			sayac++;
		}
	}
	if (sayac == 0)
	{
		cout << "Boyle bir hesap adi ve kullanici yok" << endl;
		return;
	}


	for (int i = hesapId; uy[i].GetId() != -1; i++)
	{
		uy[i].SetAdSoyad(uy[i + 1].GetAdSoyad());
		uy[i].SetHesapAdi(uy[i + 1].GetHesapAdi());
		uy[i].SetId(uy[i + 1].GetId()-1);
		uy[i].SetSifre(uy[i + 1].GetSifre());
		uy[i].SetUyetipi(uy[i + 1].GetUyetipi());
		uy[i].SetKitapAlmaSayisi(uy[i + 1].GetKitapAlmaSayisi());
		
		
	}
	uyeSayisi--;
	cout << "Uye silindi.." << endl;

}

void Admin::uyeListele(Uye uy[])
{
	cout << setw(6) << left << "ID:" << setw(15) << left << "Ad-Soyad:" << setw(18) << left << "Uye Tipi:" << setw(15) << left << "Hesap Adi:" << setw(5) << left <<
		 "Alabilicegi Kitap Sayisi:" << endl;

	for (int i = 0; uy[i].GetAdSoyad() != "Girilmedi"; i++)
	{
		
		cout << setw(6) << left <<uy[i].GetId() << setw(15) << left << uy[i].GetAdSoyad() << setw(18) << left << uy[i].GetUyetipi() << 
			setw(15) << left << uy[i].GetHesapAdi() << setw(1) << left << uy[i].GetKitapAlmaSayisi() << endl;
	}
}

void Admin::kitapEkle(Kitap ktp[])
{
	string ktpAdi = " ";
	string ktpYazari = " ";
	int kacKitapVar = mevcutKitapSayisi(ktp);
	cout << "Kitap adi:";
	//getline(cin, ktpAdi);
	cin >> ktpAdi;
	cout << "Yazar adi:";
	cin >> ktpYazari;
	//getline(cin, ktpYazari);


	for (int i = 0; ktp[i].GetKitapAdi() != "Girilmedi"; i++)
	{
		if (ktp[i].GetKitapAdi() == ktpAdi && ktp[i].GetKitapYazari() == ktpYazari)
		{
			cout << "Bu isminde bir kitap zaten kayitli. Tekrar deneyin" << endl;
			return;
		}
	}
	ktp[kacKitapVar].SetKitapAdi(ktpAdi);
	ktp[kacKitapVar].SetKitapYazari(ktpYazari);
	ktp[kacKitapVar].SetKitapDurumu("Unhold");
	ktp[kacKitapVar].SetId(kacKitapVar);
	cout << "Kitap Eklendi..." << endl;
}

void Admin::kitapSilme(Kitap ktp[])
{
	int ktpId;
	int kntrl = 0;
	cout << "Silmek istediginiz kitap ID sini giriniz." << endl;
	cin >> ktpId;

	for (int i = 0; ktp[i].GetId() != -2; i++)
	{
		if (ktp[i].GetId() == ktpId)
		{
			kntrl = 1;
			break;
		}
			
		else
			kntrl = 0;
	}

	if (kntrl == 0)
	{
		cout << "Boyle bir kitap ID yok. Tekrar deneyin." << endl;
		return;
	}

	
	for (int i = ktpId ; ktp[i].GetId() != -2; i++)
	{
		if (kntrl == 1)
		{
			ktp[i].SetKitapAdi(ktp[i + 1].GetKitapAdi());
			ktp[i].SetKitapYazari(ktp[i + 1].GetKitapYazari());
			ktp[i].SetBasimYili(ktp[i + 1].GetBasimYili());
			ktp[i].SetKitapDurumu(ktp[i + 1].GetKitapDurumu());
			ktp[i].SetKitabiAlanKisiId(ktp[i + 1].GetKitabiAlanKisiId());
			ktp[i].SetId(ktp[i + 1].GetId()-1);
		}
	}
	cout << "Kitap Silindi..." << endl;
	

}  

void Admin::kitapListele(Kitap ktp[])
{
	cout << setw(5) << left << "ID" << setw(15) << left << "Kitap Adi" << setw(15) << left << "Yazar Adi" << setw(15) << left << "Statu" << endl;
	for (int i = 0; ktp[i].GetKitapAdi() != "Girilmedi"; i++)
	{
		cout << setw(5) << left <<ktp[i].GetId() << setw(15) << left << ktp[i].GetKitapAdi() << setw(15) << left
			 << ktp[i].GetKitapYazari() << setw(15) << left << ktp[i].GetKitapDurumu() << endl;
	}
}

int Admin::mevcutKitapSayisi(Kitap ktp[])
{
	int kitapSayisi = 0;
	for (int i = 0; ktp[i].GetKitapAdi() != "Girilmedi"; i++)
		kitapSayisi++;

	return kitapSayisi;
}

void Admin::mevcutUyeSayisi(Uye uy[])
{
	uyeSayisi = 0;
	for (int i = 0; uy[i].GetAdSoyad() != "Girilmedi"; i++)
	{
		uyeSayisi++;
	}
}
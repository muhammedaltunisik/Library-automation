#include "Uye.h"
#include "Kitap.h"
#include "Admin.h"
#include <iostream>

using namespace std;


int uyeIDBul(Uye[], string);

int main()
{
	
	Admin admin; //Admin sinifinin yapici fonksiyonu kullaci adini "admin" ve sifreyi de "1234" olarak ilk basta atamasini yapar
	Uye uy[100];
	Kitap ktp[100];

	ktp[0].SetKitapAdi("C++"); ktp[0].SetKitapYazari("J.Adams"); ktp[0].SetKitapDurumu("Unhold"); ktp[0].SetId(0);
	ktp[1].SetKitapAdi("C"); ktp[1].SetKitapYazari("S.David"); ktp[1].SetKitapDurumu("Unhold"); ktp[1].SetId(1);
	ktp[2].SetKitapAdi("Python"); ktp[2].SetKitapYazari("S.Aslan"); ktp[2].SetKitapDurumu("Unhold"); ktp[2].SetId(2);
	ktp[3].SetKitapAdi("C++"); ktp[3].SetKitapYazari("S.David"); ktp[3].SetKitapDurumu("Unhold"); ktp[3].SetId(3);
	ktp[4].SetKitapAdi("C#"); ktp[4].SetKitapYazari("S.David"); ktp[4].SetKitapDurumu("Unhold"); ktp[4].SetId(4);
	ktp[5].SetKitapAdi(".Net"); ktp[5].SetKitapYazari("M.James"); ktp[5].SetKitapDurumu("Unhold"); ktp[5].SetId(5);


	uy[0].SetAdSoyad("Ayse Tekin"); uy[0].SetHesapAdi("AyseT"); uy[0].SetUyetipi("Ogrenci"); uy[0].SetId(0); uy[0].SetKitapAlmaSayisi(5);
	uy[1].SetAdSoyad("Aysel Sayin"); uy[1].SetHesapAdi("AyselS"); uy[1].SetUyetipi("Personel"); uy[1].SetId(1); uy[1].SetKitapAlmaSayisi(3);
	uy[2].SetAdSoyad("Ali Aslan"); uy[2].SetHesapAdi("AliA"); uy[2].SetUyetipi("OgretimElemani"); uy[2].SetId(2); uy[2].SetKitapAlmaSayisi(10);
	uy[3].SetAdSoyad("Ali Turk"); uy[3].SetHesapAdi("aTurk"); uy[3].SetUyetipi("Ogrenci"); uy[3].SetId(3); uy[3].SetKitapAlmaSayisi(5);
	uy[4].SetAdSoyad("Muhammed Altunisik"); uy[4].SetHesapAdi("mami5253"); uy[4].SetUyetipi("Ogrenci"); uy[4].SetId(4); uy[4].SetKitapAlmaSayisi(5);

	

	string hesap_Adi;
	string girilen_sifre;
	int hesapID = 0;
	int islem = 0;
	int dongu1 = 1, dongu2 = 1;
	

	while (dongu1)
	{ 
		cout << "\tAna Menu\n\n";
		cout << "1 Admin Girisi \n2 Uye Girisi \n3 Cikis" << endl;
		cout << "\tSeciminizi Girin:";
		cin >> islem;
		cout << endl;
		switch (islem)
		{
		case 1:
			cout << "Admin Kullanici Adi:";
			cin >> hesap_Adi;
			cout << "Sifre:";
			cin >> girilen_sifre;
			if (admin.SifreDogruMu(hesap_Adi, girilen_sifre))
			{
				dongu2 = 1;
				while (dongu2)
				{
					cout << "\n\tAdmin MENUSU\n" << endl;
					cout << "1 Kitap Ekle \n2 Kitap Sil \n3 Kitaplari Listele \n4 Uye Ekle \n5 Uyeleri Listele \n6 Uyeleri Sil \n7 Cikis" << endl;
					cout << "\tSeciminizi Girin:";
					cin >> islem;
					switch (islem)
					{
					case 1:
						admin.kitapEkle(ktp);
						break;
					case 2:
						admin.kitapSilme(ktp);
						break;
					case 3:
						admin.kitapListele(ktp);
						break;
					case 4:
						admin.uyeEkle(uy);
						break;
					case 5:
						admin.uyeListele(uy);
						break;
					case 6:
						admin.uyeSilme(uy);
						break;
					case 7:
						dongu2 = 0;
						break;
					default:
						cout << "Yanlis secim yaptiniz. Tekrar Deneyin" << endl;
						break;
					}

				}
			}
			break; // Case 1 sonu


		case 2:
			cout << "Uye Kullanici Adi:";
			cin >> hesap_Adi;
			cout << "Sifre:";
			cin >> girilen_sifre;
			hesapID = uyeIDBul(uy, hesap_Adi);
			if (uy[hesapID].SifreDogruMu(hesap_Adi, girilen_sifre))
			{
				dongu2 = 1;
				while (dongu2)
				{
					cout << "\n\tUYE MENUSU\n" << endl;
					cout << "1 Kitap Ara \n2 Kitap Odunc Al \n3 Kitaplari Iade Et \n4 Kitaplari Listele \n5 Uyelik Islemleri \n6 Cikis" << endl;
					cout << "\tSeciminizi Girin:";
					cin >> islem;
					switch (islem)
					{
					case 1:
						uy[hesapID].kitapArama(ktp);
						break;
					case 2:
						uy[hesapID].kitapOduncAlma(ktp);
						break;
					case 3:
						uy[hesapID].kitapIadeEt(ktp);
						break;
					case 4:
						uy[hesapID].kitapListele(ktp);
						break;
					case 5:
						uy[hesapID].uyelikIslemleri();
						break;
					case 6:
						dongu2 = 0;
						break;
					default:
						cout << "Yanlis secim yaptiniz. Tekrar Deneyin" << endl;
						break;
					}

				}

			}
			break; // Case 2 sonu


		case 3:
			cout << "Programdan Cikiliyor..." << endl;
			dongu1 = 0;
			break; //Case 3 Sonu

		default:
			cout << "Yanlis secim yaptiniz. Tekrar Deneyin" << endl;
			break;
		}
	} //En dis While sonu
	
}

int uyeIDBul(Uye uy[], string hesap_Adi)
{
	for (int i = 0; uy[i].GetAdSoyad() != "Girilmedi"; i++)
	{
		if (hesap_Adi == uy[i].GetHesapAdi())
		{
			return uy[i].GetId();
		}
			
	}
	return 0;
}


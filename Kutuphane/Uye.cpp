#include "Uye.h"



Uye::Uye(string uyeAdSoyad, string uyeKullaniciAdi, string uyeSifre, int uyeId) :Kullanici(uyeAdSoyad, uyeKullaniciAdi, uyeSifre, uyeId)
{

}

void Uye::SetUyetipi(string uyeTip) { uyeTipi = uyeTip; }

void Uye::SetKitapAlmaSayisi(int kptSayisi) { kitapAlmaSayisi = kptSayisi; }

void Uye::kitapArama(Kitap ktp[])
{
	string ktpAdi;
	string ktpYazari;
	cout << "Kitap Adini Girin:";
	cin >> ktpAdi;
	cout << "Yazar Adi Girin:";
	cin >> ktpYazari;
	int bilgilendirmeSayisi = 1;
	for (int i = 0; ktp[i].GetKitapAdi() != "Girilmedi" ; i++)
	{
		if (ktp[i].GetKitapAdi() == ktpAdi && ktp[i].GetKitapYazari() == ktpYazari)
		{
			if (bilgilendirmeSayisi == 1)
				cout << "\nAradiginiz kitap bulundu. Kitap Bilgileri:\n";
			bilgilendirmeSayisi++;
			cout << ktp[i].GetId() << " " << ktp[i].GetKitapYazari() << " " << ktp[i].GetKitapAdi() << " " << ktp[i].GetKitapDurumu();
			break;
		}
		else if (ktp[i].GetKitapAdi() == ktpAdi && ktpYazari == "*")
		{
			if (bilgilendirmeSayisi == 1)
				cout << "\nAradiginiz kitap bulundu. Kitap Bilgileri:\n";
			bilgilendirmeSayisi++;
			cout << ktp[i].GetId() << " " << ktp[i].GetKitapYazari() << " " << ktp[i].GetKitapAdi() << " " << ktp[i].GetKitapDurumu() << endl;
			continue;
		}
	}
	if (bilgilendirmeSayisi == 1)
		cout << "Aradiginiz kitap bulunamadi.." << endl;
}

void Uye::kitapOduncAlma(Kitap ktp[])
{
	int ktpId = 0;
	cout << "Kitap ID:";
	cin >> ktpId;
	if (ktp[ktpId].GetKitapDurumu() == "Unhold")
	{
		if (alinanKitapSayisi < GetKitapAlmaSayisi())
		{
			alinanKitapSayisi++;
			cout << "Kitapi aldiniz. Odunc Aldiginiz toplam kitap sayisi:" << alinanKitapSayisi << endl;
			ktp[ktpId].SetKitapDurumu("Hold");
			ktp[ktpId].SetKitabiAlanKisiId(GetId()); //Protected da degistirdim. Hata çýkarsa bak
		}
		else
			cout << "Daha fazla kitap alamazsiniz!" << endl;
		
	}
	else
	{
		cout << "Secilen kitap alinamaz" << endl;
	}
}

void Uye::kitapIadeEt(Kitap ktp[])
{
	int ktpId = 0;
	cout << "Iade edilicek kitap ID:";
	cin >> ktpId;

	if (ktp[ktpId].GetKitapDurumu() == "Hold" && ktp[ktpId].GetKitabiAlanKisiId() == GetId())
	{
		ktp[ktpId].SetKitabiAlanKisiId(-2);
		ktp[ktpId].SetKitapDurumu("Unhold");
		alinanKitapSayisi--;
		cout << "Kitap iade edilmistir..." << endl;
	}
	else if (ktp[ktpId].GetKitapDurumu() == "Unhold")
		cout << "Alinmamis kitap iade edilemez" << endl;
			

	else if (ktp[ktpId].GetKitabiAlanKisiId() != GetId() ) //Protected dan degistirdik hata çýkarsa bak
		cout << "Kitabi sadece odunc alan kisi iade edebilir" << endl;			
}

void Uye::kitapListele(Kitap ktp[])
{
	cout << setw(5) << left << "ID" << setw(15) << left << "Kitap Adi" << setw(15) << left << "Yazar Adi" << setw(15) << left << "Statu" << endl;
	for (int i = 0; ktp[i].GetKitapAdi() != "Girilmedi"; i++)
	{
		cout << setw(5) << left << ktp[i].GetId() << setw(15) << left << ktp[i].GetKitapAdi() << setw(15) << left
			<< ktp[i].GetKitapYazari() << setw(15) << left << ktp[i].GetKitapDurumu() << endl;
	}
}

void Uye::uyelikIslemleri()
{
	string yeniSifre;
	cout << "Yeni Sifrenizi Giriniz:";
	cin >> yeniSifre;
	SetSifre(yeniSifre);
	cout << "Sifreniz degistirildi..." << endl;
}

int Uye::GetKitapAlmaSayisi() { return kitapAlmaSayisi; }

string Uye::GetUyetipi() { return uyeTipi; }


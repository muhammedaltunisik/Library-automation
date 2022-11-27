#include "Kitap.h"



Kitap::Kitap(string kAdi, string kYazari, string kDurum, int kId, int kBas, int kAlanId) 
{
	kitapAdi = kAdi;
	kitapYazari = kYazari;
	kitapDurumu = kDurum;
	kitapId = kId;
	basimYili = kBas;
	kitabiAlanKisiId = kAlanId;
}

string Kitap::GetKitapAdi() { return kitapAdi; }
string Kitap::GetKitapYazari() { return kitapYazari; }
string Kitap::GetKitapDurumu() { return kitapDurumu; }
int Kitap::GetId() { return kitapId; }
int Kitap::GetBasimYili() { return basimYili; }
int Kitap::GetKitabiAlanKisiId() { return kitabiAlanKisiId; }


void Kitap::SetKitapAdi(string kAdi) { kitapAdi = kAdi; }
void Kitap::SetKitapYazari(string kYazari) { kitapYazari = kYazari; }
void Kitap::SetKitapDurumu(string kDurum) { kitapDurumu = kDurum; }
void Kitap::SetId(int kId) { kitapId = kId; }
void Kitap::SetBasimYili(int kBas) { basimYili = kBas; }
void Kitap::SetKitabiAlanKisiId(int kAlanId) { kitabiAlanKisiId = kAlanId; }

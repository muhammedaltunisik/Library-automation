#ifndef KITAP_H
#define KITAP_H
#include <string>

using namespace std;

class Kitap
{
public:
	Kitap(string = "Girilmedi" , string = "Girilmedi" , string = "Girilmedi" , int = -2, int = -2, int = -2);
	string GetKitapAdi();
	string GetKitapYazari();
	string GetKitapDurumu();
	int GetId();
	int GetBasimYili();
	int GetKitabiAlanKisiId();


	void SetKitapAdi(string);
	void SetKitapYazari(string);
	void SetKitapDurumu(string);
	void SetId(int);
	void SetBasimYili(int);
	void SetKitabiAlanKisiId(int);

private:
	string kitapAdi;
	string kitapYazari;
	string kitapDurumu;
	int kitapId;
	int basimYili;
	int kitabiAlanKisiId;
};

#endif // !KITAP_H

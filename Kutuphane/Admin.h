#ifndef ADMIN_H
#define ADMIN_H
#include "Kullanici.h"
#include "Uye.h"
#include "Kitap.h"


class Admin :public Kullanici
{
public:
	Admin(string = "adAdmin", string = "admin", string = "1234", int = 0);
	void uyeEkle(Uye[]);
	void uyeSilme(Uye[]);
	void uyeListele(Uye[]);
	void kitapEkle(Kitap[]);
	void kitapSilme(Kitap[]);
	void kitapListele(Kitap[]);
	int mevcutKitapSayisi(Kitap[]); //Sonradan Ekledim
	void mevcutUyeSayisi(Uye[]); //Sonradan Ekledim

private:
	int uyeSayisi;
};


#endif

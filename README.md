# Kutuphane Otomasyonu
Komut satırı üzerinde çalışan C++ dilinde yazılmış basit bir kütüphane otomasyonu.

-----
## Özellikleri

İki tip kullanıcı vardır **admin** ve **üye** olarak. Admin kullanıcı üyeler ve kitaplar ile ilgili işlemleri yapar. Üye kullanıcısı kitap ödünç alma, kitapları listeleme vs. durumlarla ilgili işlemler yapabilir. Statik olarak 100 kitap ve 100 üye tutan 2 ayrı array tanımlanmıştır. Tanımlanmış arraylerde ki ID numaralarına göre üyeler ve kitaplar seçilip üzerlerinde işlemler yapılır. Örnek olarak 5 adet kitap ve 4 adet üye kayıt edilmiştir. Uyelerin şifreleri varsayılan olarak tempdir. Adminin kullanici adi ve sifresi varsayılan olarak "admin" ve "1234" olarak ayarlanmıştır. Üye sınıfı ve admin sınıfı ortak özellikler barındırdığı için kullanıcı sınıfından türetilmiştir. 
Admin, Uye, Kullanıcı ve Kitap sınıflarının fonksiyonları ve görevleri aşağıda verilmiştir.

-----------
### Admin Kullanicisi Özellikleri
1. *Kitap Ekle*
2. *Kitap Sil*
3. *Kitapları Listele*
4. *Üye Ekle*
5. *Üyeleri Listele*
6. *Üyeleri Sil*
7. *Çıkış*

![Admin Menusu](img\AdminHomaPage.png)

### Uye Kullanicisi Özellikleri
1. *Kitap Ara*
2. *Kitap Ödünç Al*
3. *Kitapları İade et*
4. *Kitapları Listele*
5. *Uyelik İslemleri*
6. *Çıkış*

![Uye Menusu](img\User1.png)

------------------
### Projeye ait ekran çıktıları
![image1](img\Login.png)
![image1](img\User2.png)
![image1](img\Admin1.png)
![image1](img\Admin2.png)
------------------

### Kullanıcı Sınıfının Sahip Olduğu fonksiyonlar ve Özellikleri
*Admin ve Üye sınıfının ortak özelliklerini tutmak için oluşturulmuş sınıftır. Kalıtım yoluyla her iki sınıf tarafından özellikleri miras alınır*

1. **Yapıcı Fonksiyonu:** Kullanıcı sınıfınından oluşturulan nesnenin ilk özelliklerini belirler .
2. **GetAdSoyad:** Kullanıcının adını ve soyadını döndürür
3. **GetHesapAdi:**  Kullanıcının hesap adını döndürür
4. **GetSifre:** Kullanıcının sifresini döndürür
5. **GetID:** Kullanıcının ID numarasını döndürür
6. **SetAdSoyad:** Kullanıcının adını ve soyadını ayarlamayı sağlar
7. **SetHesapAdi:** Kullanıcının hesap adını ayarlamayı sağlar
8. **SetSifre:** Kullanıcının sifresini ayarlar
9. **SetID:** Kullanıcıya elle ID ataması yapar

#### Admin Sınıfının Sahip Olduğu fonksiyonlar ve Özellikleri

*Kullanıcı sınıfından Türetilmiştir. Kitap ve Uyelerle ilgili değişiklikleri yapmayı sağlar*

1. **Yapıcı Fonksiyonu:** Admin sınıfınından oluşturulan nesnenin ilk özelliklerini belirler .
2. **uyeEkle:** Yeni üye kaydetmeyi sağlar.
3. **uyeSil:**  Kayıtlı üyeyi silmeyi sağlar.
4. **uyeListele:** Kayıtlı üyeleri listeler.
5. **kitapEkle:** Yeni kitap ekler.
6. **kitapSilme:** Ekli kitabı siler.
7. **kitapListeleme:** Eklenmiş kitapları listeler.
8. **mevcutKitapSayisi:** Ekli kitapların sayısını döndürür.
9. **mevcutUyeSayisi:** Kayıtlı üyelerin sayısını döndürür.

#### Üye Sınıfının Sahip Olduğu fonksiyonlar ve Özellikleri
*Kullanıcı sınıfından Türetilmiştir. Üyelerin kitap ödünç alma iade etmeleri veya bilgilerini değiştirmeyi sağlar*

1. **Yapıcı Fonksiyonu:** Üye sınıfınından oluşturulan nesnenin ilk özelliklerini belirler .
2. **SetUyetipi:** Üye tipini belirler. (Öğrenci,Öğretim Üyesi vs)
3. **SetKitapAlmaSayisi:**  Ödünç alabiliceği kitap sayısını belirler.
4. **kitapArama:** Ekli olan kitaplar arasın dan arama yapar.
5. **kitapOduncAlma:** Ekli kitaplardan birini odunc almayı sağlar.
6. **kitapIadeEt:** Ödünç alınmış kitabı geri iade eder.
7. **kitapListele:** Ekli kitapların hepsini listeler.
8. **uyelikIslemleri:** Üye şifresini değiştirir.
9. **GetKitapAlmaSayisi:** Elinde tuttuğu ödünç kitap sayınısı döndürür.
10. **GetUyetipi:** Üyenin tipini döndürür.

#### Admin Sınıfının Sahip Olduğu fonksiyonlar ve Özellikleri

*Kitaplara ait özellikleri tutan sınıftır.*

1. **Yapıcı Fonksiyonu:** Kitap sınıfınından oluşturulan nesnenin ilk özelliklerini belirler .
2. **GetKitapAdi:** Kitabın adını döndürür.
3. **GetKitapYazari:**  Kitabın yazarını döndürür.
4. **GetKitapDurumu:** Kitabın ödünç alınıp alınmadığını döndürür.
5. **GetID:** Kitap ID döndürür.
6. **GetBasimYili:** Kitabın basım yılını döndürür.
7. **GetKitabiAlanKisiId:** Kitabı alan kişinin ID sini döndürür.
8. **SetKitapAdi:** Kitabın adını belirler.
9. **SetKitapYazari:** Kitabın yazarını belirler.
10. **SetKitapDurumu:** Kitabın ödünç alınma durumunu belirler.
11. **SetID:** Kitabın ID sını belirler.
12. **SetBasimYili:** Kitabın basım yılını belirler.
13. **SetKitabiAlanKisiID:** Kitabı alan kişinin ID sini belirler.

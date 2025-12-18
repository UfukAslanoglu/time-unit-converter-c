# ⏳ Zaman Birimi Dönüştürücü (C)

Bu proje, C programlama dili kullanılarak geliştirilmiş, farklı zaman birimleri (Saniye, Dakika, Saat, Gün) arasında dönüşüm yapan bir komut satırı uygulamasıdır.

## 🚀 Proje Hakkında
Uygulama, kullanıcıdan alınan bir miktarı önce standart birim olan saniyeye çevirir, ardından saniye üzerinden istenen hedef birime dönüştürür. Projenin öne çıkan teknik özellikleri:
- **Hata Yönetimi:** Kullanıcı hatalı (harf vb.) giriş yaptığında programın çökmesini engelleyen buffer temizleme mekanizması içerir.
- **Modüler Yapı:** Dönüşüm işlemleri için özelleşmiş fonksiyonlar kullanılarak kod tekrarı önlenmiştir.
- **Veri Hassasiyeti:** Hesaplamalarda yüksek hassasiyet için `double` veri tipi kullanılmıştır.

## 🛠️ Teknik Detaylar
- **Dil:** C
- **Kullanılan Yapılar:** `while` döngüsü, `switch-case` karar yapıları, `scanf` hata kontrolü.

## 💻 Nasıl Çalıştırılır?
1. `time_converter.c` dosyasını indirin.
2. Terminal üzerinden derleyin:
   ```bash
   gcc time_converter.c -o time_converter

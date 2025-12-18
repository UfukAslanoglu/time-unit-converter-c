#include <stdio.h>  // EKLENDI: Giris-cikis fonksiyonlari icin gerekli
#include <stdlib.h>

/*
  DUZELTME NOTLARI:
  1. <stdio.h> kutuphanesi eklendi.
  2. Sleep fonksiyonlari programi gereksiz dondurdugu icin kaldirildi.
  3. Null pointer hatasi (Segmentation Fault) yapan kisim silindi.
  4. Eksik olan 'saniyedenCevir' fonksiyonu yazildi.
  5. Degisken tanimlamalari (Declaration) main fonksiyonuna eklendi.
  6. Noktali virgul hatalari duzeltildi.
*/

void menuYazdir() {
    printf("\n--- ZAMAN DONUSTURUCU ---\n");
    printf("1. Saniye\n");
    printf("2. Dakika\n"); // DUZELTME: Noktali virgul eklendi
    printf("3. Saat\n");
    printf("4. Gun\n");
    printf("0. Cikis\n");
    printf("-------------------------\n");
}

// Girilen birimi saniyeye cevirir
double saniyeyeCevir(double miktar, int birim) {
    // BURADAKI HATALI KODLAR (Sleep ve Null Pointer) SILINDI.
    
    switch (birim) {
        case 1: return miktar;          // Saniye -> Saniye
        case 2: return miktar * 60;     // Dakika -> Saniye
        case 3: return miktar * 3600;   // Saat -> Saniye
        case 4: return miktar * 86400;  // Gun -> Saniye
        default: return -1.0;           // Hata durumu icin sayi donuldu
    }
}

// Saniyeyi istenen hedef birime cevirir (Eksik olan fonksiyon yazildi)
double saniyedenCevir(double saniye, int hedefBirim) {
    switch (hedefBirim) {
        case 1: return saniye;
        case 2: return saniye / 60.0;
        case 3: return saniye / 3600.0;
        case 4: return saniye / 86400.0;
        default: return -1.0;
    }
}

int main() {
    int kaynakBirim, hedefBirim; 
    double miktar, saniyeBazli, sonuc; // DUZELTME: Degiskenler tanimlandim

    while (1) {
        menuYazdir();
        
        printf("Hangi birimden cevireceksiniz? (Secim): ");
        if (scanf("%d", &kaynakBirim) != 1) {
            // Harf girilirse sonsuz donguye girmemesi icin buffer temizleme
            while(getchar() != '\n'); 
            printf("HATALI GIRIS! Lutfen sayi giriniz.\n");
            continue; 
        }
        
        if (kaynakBirim == 0) {
            printf("Programdan cikiliyor...\n");
            break;
        }

        printf("Miktari girin: ");
        if (scanf("%lf", &miktar) != 1) {
             while(getchar() != '\n');
             printf("Gecersiz miktar!\n");
             continue;
        }

        printf("Hangi birime donusturmek istiyorsunuz? (Secim): ");
        scanf("%d", &hedefBirim);

        // 1. Adim: Girilen birimi saniyeye cevir
        saniyeBazli = saniyeyeCevir(miktar, kaynakBirim);
        
        if (saniyeBazli < 0) {
            printf("Hatali birim secimi!\n");
            continue;
        }

        // 2. Adim: Saniyeyi hedef birime cevir
        sonuc = saniyedenCevir(saniyeBazli, hedefBirim); 

        if (sonuc < 0) {
            printf("Hatali hedef birim secimi!\n");
        } else {
            printf("\n>>> SONUC: %.4f \n", sonuc);
        }
    }
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* KARAKTER TABANLI "HAYATTA KALMA SIMÜLATÖRÜ"*/

int main() {
	
	int enerji=100, saglik=100, siginak=0, yemek=0;
	int devam=1;
	char komut;
	int i;
	
	srand(time(NULL));  // Rastgele sayi ureteci - bir kere yeterli
	
	printf("==============================================\n");
    printf("   HAYATTA KALMA SIMULATORU\n");
    printf("==============================================\n");
    printf("Vahsi dogada hayatta kalmayi deneyin!\n");
    printf("Komutlar:\n");
    printf("  A - Avlan\n");
    printf("  S - Siginak ara\n");
    printf("  E - Envanteri goruntule\n");
    printf("  R - Dinlen\n");
    printf("  F - Tehlike dalgasi\n");
    printf("  P - Sifreli ilerleme\n");
    printf("  X - Cikis\n");
    printf("==============================================\n\n");
    
	do{
		// Oyun bitti mi kontrol
		if(saglik <= 0){
			printf("\n*** OYUN BITTI! Sagliginiz sifira dustu. ***\n");
			devam = 0;
			break;
		}
		
		printf("\n--- DURUM ---\n");
        printf("Saglik: %d/100 | Enerji: %d/100 | Yemek: %d | Siginak: %s\n",
               saglik, enerji, yemek, siginak ? "Var" : "Yok");
        printf("-------------\n");
        
        printf("\nKomut girin: ");
        scanf(" %c", &komut);
        printf("\n");
       
		switch(komut){
			case 'a':
			case 'A':
				printf(">>> AVLANMA <<<\n");
				if(enerji < 20){
					printf("Yeterli enerjiniz yok! Once dinlenmelisiniz.\n");
				} else {
					enerji = enerji - 15;
					printf("Avlaniyorsunuz... Enerji: -15 (Kalan: %d)\n", enerji);
					
                    int Avsans = rand() % 100;
                    
                    // Mantiksal operatorler && ve ||
                    if((Avsans < 45 && enerji > 40) || (Avsans < 30 && enerji > 20)){
                    	int kazanc = 1 + rand() % 2;
                    	yemek = yemek + kazanc;
                    	printf("Basarili! %d yemek buldunuz. (Toplam: %d)\n", kazanc, yemek);
                    } else if(Avsans >= 45 && Avsans < 75){
                        printf("Av kacti! Hicbir sey bulamadýniz.\n");
                    } else {
                    	int hasar = 6 + rand() % 10;
                    	saglik = saglik - hasar;
                    	printf("Tehlikeli durum! Saglik: -%d (Kalan: %d)\n", hasar, saglik);
					}
                }
			    break;
			    
			case 'S':
			case 's':
				printf(">>> SIGINAK ARAMA <<<\n");
				if(enerji < 25){
					printf("Siginak aramak icin yeterli enerjiniz yok!\n");
				} else if(siginak == 1){
					printf("Zaten bir siginaginiz var!\n");
				} else {
					enerji = enerji - 20;
					printf("Siginak ariyorsunuz... Enerji: -20 (Kalan: %d)\n", enerji);
					
				    int Sgksans = rand() % 100;
				    
				    // IF-ELSE yapilari ile farkli kosullar
				    if(saglik > 70 && enerji > 40){
				    	// Iyi durum
				    	if(Sgksans < 70){
				    		siginak = 1;
				    		printf("Mukemmel bir siginak buldunuz!\n");
				    		saglik = saglik + 10;
				    		printf("Saglik: +10 (Toplam: %d)\n", saglik);
						} else {
							printf("Uygun siginak bulamadýniz.\n");
						}
					} else if(saglik > 40 || enerji > 30){
						// Orta durum
						if(Sgksans < 50){
							siginak = 1;
							printf("Basit bir siginak buldunuz.\n");
						} else {
							printf("Arama basarisiz.\n");
						}
					} else {
						// Kotu durum
						if(Sgksans < 30){
							siginak = 1;
							printf("Zor durumda siginak buldunuz!\n");
						} else {
							printf("Cok yorgunsunuz, bulamadýniz.\n");
							saglik = saglik - 5;
							printf("Saglik: -5 (Kalan: %d)\n", saglik);
						}
					}
				}
			    break;
			    
			case 'e':
			case 'E':
				printf(">>> ENVANTER <<<\n");
				printf("----------------------------------\n");
                printf("Saglik: %d/100\n", saglik);
                printf("Enerji: %d/100\n", enerji);
                printf("Yemek : %d adet\n", yemek);
                printf("Siginak: %s\n", siginak == 1 ? "Var" : "Yok");
                printf("----------------------------------\n");
                
                // Durum degerlendirmesi
                if(saglik > 80 && enerji > 80){
                	printf("Durum: Mukemmel!\n");
				} else if(saglik > 50 && enerji > 50){
					printf("Durum: Iyi.\n");
				} else if(saglik > 30 || enerji > 30){
					printf("Durum: Orta. Dikkatli olun!\n");
				} else {
					printf("Durum: KRITIK!\n");
				}
                break;
                
			case 'r':
			case 'R':
				printf(">>> DINLENME <<<\n");
				if(yemek <= 0){
					printf("Yemek yok! Dinlenemezsiniz. Once avlanmalisiniz.\n");
				} else {
					yemek = yemek - 1;
					printf("1 yemek tuketildi. (Kalan: %d)\n", yemek);
					
					int saglikArtis, enerjiArtis;
					
					if(siginak == 1){
						// Siginakta dinlenme - bonus
						saglikArtis = 25 + rand() % 11;
						enerjiArtis = 35 + rand() % 11;
						printf("Siginakta dinleniyorsunuz... Ekstra bonus!\n");
					} else {
						// Acik alanda dinlenme
						saglikArtis = 15 + rand() % 11;
						enerjiArtis = 25 + rand() % 11;
						printf("Acik alanda dinleniyorsunuz...\n");
					}
					
					saglik = saglik + saglikArtis;
					enerji = enerji + enerjiArtis;
					
					// Maksimum deger kontrolu
					if(saglik > 100) saglik = 100;
					if(enerji > 100) enerji = 100;
					
					printf("Saglik: +%d (Toplam: %d)\n", saglikArtis, saglik);
					printf("Enerji: +%d (Toplam: %d)\n", enerjiArtis, enerji);
				}
				break;
				
			case 'f':
			case 'F':
				// FOR DONGUSU - Tehlike dalgasi
				printf(">>> TEHLIKE DALGASI <<<\n");
				printf("Bir dizi tehlike geliyor!\n\n");
				
				int tehlikeSayisi = 3 + rand() % 3; // 3-5 arasi
				
				for(i = 1; i <= tehlikeSayisi; i = i + 1){
					printf("--- Tehlike %d/%d ---\n", i, tehlikeSayisi);
					
					int tehlikeTuru = rand() % 100;
					
					if(tehlikeTuru < 40){
						// Hafif hasar
						int hasar = 3 + rand() % 5;
						saglik = saglik - hasar;
						printf("Kucuk yaralanma! Saglik: -%d (Kalan: %d)\n", hasar, saglik);
					} else if(tehlikeTuru < 70){
						// Enerji kaybi
						int kayip = 5 + rand() % 8;
						enerji = enerji - kayip;
						printf("Yorucu kacis! Enerji: -%d (Kalan: %d)\n", kayip, enerji);
					} else if(tehlikeTuru < 85){
						// Kacis
						printf("Tehlikeden kactiniz!\n");
					} else {
						// Buyuk tehlike
						int buyukHasar = 8 + rand() % 8;
						saglik = saglik - buyukHasar;
						int enerjiKayip = 5 + rand() % 6;
						enerji = enerji - enerjiKayip;
						printf("BUYUK TEHLIKE!\n");
						printf("Saglik: -%d, Enerji: -%d\n", buyukHasar, enerjiKayip);
						printf("Kalan -> Saglik: %d, Enerji: %d\n", saglik, enerji);
					}
					
					if(saglik <= 0){
						printf("\nTehlikede hayatinizi kaybettiniz!\n");
						break;
					}
					
					printf("\n");
				}
				
				printf("Tehlike dalgasi bitti!\n");
				break;
				
			case 'p':
			case 'P':
				// DO-WHILE DONGUSU - Sifreli ilerleme
				printf(">>> SIFRELI ILERLEME <<<\n");
				printf("Onunde kilitli bir kapi var.\n");
			    printf("Kapinin uzerinde sembol: *\n");
			    printf("Dogru karakteri bul!\n\n");
			    
			    char dogruKarakter = '*';
			    char girilenKarakter;
			    int denemeSayisi = 0;
			    
				do{
			    	denemeSayisi = denemeSayisi + 1;
			    	printf("Deneme %d - Karakter girin: ", denemeSayisi);
			    	scanf(" %c", &girilenKarakter);
			    	
			    	if(girilenKarakter != dogruKarakter){
			    		printf("Yanlis! Tekrar dene.\n");
			    		
			    		// Her 3 yanlista ceza
			    		if(denemeSayisi % 3 == 0){
			    			enerji = enerji - 3;
			    			printf("Cok deneme! Enerji: -3 (Kalan: %d)\n", enerji);
						}
						printf("\n");
					}
			    	
				} while(girilenKarakter != dogruKarakter);
				
				// Basari
				printf("\n*** BASARILI! Kapidan gectiniz! ***\n");
				printf("Toplam deneme: %d\n", denemeSayisi);
				
				// Odul
				if(denemeSayisi == 1){
					yemek = yemek + 3;
					saglik = saglik + 15;
					printf("Mukemmel! +3 Yemek, +15 Saglik\n");
				} else if(denemeSayisi <= 3){
					yemek = yemek + 2;
					saglik = saglik + 10;
					printf("Iyi! +2 Yemek, +10 Saglik\n");
				} else {
					yemek = yemek + 1;
					saglik = saglik + 5;
					printf("Basardin! +1 Yemek, +5 Saglik\n");
				}
				
				if(saglik > 100) saglik = 100;
				break;
			
			case 'x':
			case 'X':
				printf("Oyundan cikiliyor... Gorusmek uzere!\n");
				devam = 0;
				break;
				
			default:
				printf("Gecersiz komut! Lutfen gecerli bir komut girin.\n");
				break;
		}
		
		printf("\n");
		
	} while(devam == 1);
	
	// Oyun sonu
	printf("\n==============================================\n");
	printf("Son Durum:\n");
	printf("Saglik: %d | Enerji: %d | Yemek: %d | Siginak: %s\n",
	       saglik, enerji, yemek, siginak ? "Var" : "Yok");
	printf("==============================================\n");
	
	return 0;
}

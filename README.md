Hayatta Kalma Simülatörü (Survival Simulator)
Bu proje, C programlama dili ile yazılmış, metin tabanlı (konsol) bir hayatta kalma oyunudur. Oyuncu; sağlık, enerji ve yemek gibi kaynaklarını yöneterek vahşi doğada hayatta kalmaya çalışır.
Projenin Amacı
Bu oyun, kullanıcının stratejik kararlar vererek hayatta kalma süresini uzatmasını hedefler. Aynı zamanda C programlama dilindeki şu yapıların pratik kullanımını gösterir:

do-while, while ve for döngüleri

switch-case menü yapısı

if-else karar mekanizmaları

rand() ile rastgele olay üretimi

 Nasıl Oynanır?
Oyuna 100 Sağlık ve 100 Enerji ile başlarsınız. Amacınız sağlığınızı sıfırın üstünde tutmaktır. Her turda bir komut girerek hamle yaparsınız.Komut ListesiTuşKomutAçıklamaAAvlanEnerji harcar (-15). Şansa bağlı olarak yemek kazandırır veya yaralanmanıza sebep olur.SSığınak AraEnerji harcar (-20). Sığınak bulursanız dinlenirken daha fazla can/enerji yenilersiniz.EEnvanterMevcut sağlık, enerji, yemek ve sığınak durumunu gösterir.RDinlen1 adet yemek tüketir. Sağlık ve enerjiyi yeniler. Sığınak varsa bonus verir.FTehlike DalgasıArdışık gelen 3-5 rastgele tehlikeye karşı direnirsiniz (for döngüsü örneği).PŞifreli İlerlemeKapıyı açmak için doğru karakteri tahmin etmeye çalıştığınız bir mini oyun (do-while örneği).XÇıkışOyunu sonlandırır.⚙️ Oyun Mekanikleri ve İpuçlarıEnerji Yönetimi: Avlanmak ve sığınak aramak enerji gerektirir. Enerjiniz çok düşerse bazı eylemleri yapamazsınız.Yemek: Dinlenmek (R) için yemeğe ihtiyacınız vardır. Yemeğiniz biterse canınızı yenileyemezsiniz, bu yüzden düzenli olarak avlanın (A).Sığınak: Sığınak bulmak (S), dinlendiğinizde kazandığınız sağlık ve enerjiyi önemli ölçüde artırır. Oyun başında sığınak bulmak iyi bir stratejidir.Risk: Tehlike dalgası (F) yüksek risk taşır ancak hayatta kalma simülasyonunun heyecanlı bir parçasıdır.📝 Kod Yapısı HakkındaKod içerisinde kullanılan önemli algoritmik yapılar şunlardır:Ana Oyun Döngüsü (do-while): Oyun, kullanıcı 'X'e basana veya canı bitene kadar sürekli döner.Rastgele Olaylar (rand): Avlanma sonucu, sığınak bulma ihtimali ve tehlikelerin türü tamamen rastgele hesaplanır.Bulmaca Modu: case 'P' bloğunda, kullanıcı doğru tuşa basana kadar onu döngüde tutan bir do-while yapısı kullanılmıştır. Yanlış denemeler enerji cezası getirir.Döngüsel Tehlike: case 'F' bloğunda, belirli sayıda (3-5 arası) tehlike yaratmak için for döngüsü kullanılmıştır.

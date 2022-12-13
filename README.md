# Oyun İçi Ögeler:

DedectedBox.cpp:
Bowling çizgisini temsil eder. Topun temas etmesinin ardından kontrol devre dışı kalır. Yeniden doğma için bir zamanlayıcı çağrılır. Ayrıca düşen pin sayısını, pin aktör içindeki "PointCalculate" fonksiyonu ile hesaplayabilir. Yeni round sayısını belirler.


FastBowlingCharacter.cpp:
Bowling topu karakteridir. Temel ayarlar(seçilmiş top rengi gibi), girişler, ileri, geri, sağ, sol hareket, topun hızı gibi fonksiyonlara sahiptir.


PinActors.cpp:
Bowling labutlarıdır. Bünyesinde puan hesaplayıcı fonksiyon, takribi ikinci atışta, önceki atışta düşürülen kukaları hesaplamaya dahil etmeyen muaf tutucu fonksiyon, strike, spare bulucu fonksiyonları ve çarpışma ses efektlerini içerir. Kukaların düşüp düşmediği Unreal Engine Blueprint sistemi ile rotasyona bağlı olarak boolean anahtarına kaydedilerek hesaplanır. Puan hesaplayıcı bu anahtarlara göre çalışır.

# Oyun İçi Kullanıcı Ara Yüzü

HudScreen.cpp:
Oyun içi bilgilendirme ekranıdır. Puan tablosu, zamanlayıcı, coin, level bilgisi, özellikler gibi bilgileri ekrana yazar.


WidgetCustomizeBall.cpp:
Top rengi seçimi, hangi ögelerin seçildiği, hangilerinin kitli olduğunu ayarlar. Onay sayfası ile beraber çalışır.


WidgetSelectLevel.cpp:
Bölüm seçmeye olanak tanır. Hangi bölümlerin kilitli olduğunu gösterir. Onay sayfası ile beraber çalışır.

WidgetSelectEvent.cpp:
Hafta sonu etkinliklerini seçme ekranını oluşturur. Etkinlik varsa açıktır yoksa erişilmez.



# Temel Oynanış Kodları

FBPlayerState.cpp:
Kullanıcının Level bilgisini toplam puana göre oluşturur ve kaydeder. Bu bilgiyi kayıt dosyasına iletir.


FastBowlPlayerController.cpp:
Oyuncunun toplam puanı, coinleri, kişiselleştirmeleri, ayarları gibi bir çok bilgiyi kayıt eder ve yükler. Hafta sonu etkinlikleri için yeni puanları aktif eder.


FastBowlingGameState.cpp:
Oyun içi durum, geri sayım, puanların eklenmesi, yıkım sonrası puanların ekrana basımı, bitiş ekranı ve pinlerin yeniden oluşturulması, müzik gibi bir çok fonsiyona sahiptir.



# Google Admob

AdMobSystem_RewardVideo.cpp:
Gelecekte ödül reklamlarının kullanılabileceği düşünülerek oluşturuldu. Admob sistemine bağlı ödül reklamlarının çağırılmasını sağlar. Yalnızca alt yapı olarak kurulumu hazırlandı. Activity içine ödül reklam kodları dahil edilmedi.



























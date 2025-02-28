## STM32F429I-DISC1 ile TouchGFX LED Kontrolü   
# Proje Açıklaması
Bu proje, TouchGFX ile tasarlanmış bir grafik kullanıcı arayüzü (GUI) kullanarak STM32F429I-DISC1 geliştirme kartı üzerinde LED kontrolünü göstermektedir. Arayüz, LED'i AÇ, KAPAT ve YANIP SÖNME işlemlerini gerçekleştiren butonlar içerir.
# Özellikler
-TouchGFX Designer kullanılarak oluşturulmuş Grafik Kullanıcı Arayüzü (GUI)

-STM32CubeIDE HAL kütüphanesi kullanırlar yazılan kodlar ile LED kontrolü

-STM32F429I-DISC1 geliştirme kartı üzerinde çalışır



**Üç kontrol butonu**

-LED ON: LED'i açar

-LED OFF: LED'i kapatır

-LED BLINK: LED'i belirli bir aralıkta yanıp söndürür

## Kod Açıklaması

```
void StartDefaultTask(void *argument)
{
  /* USER CODE BEGIN 5 */
  /* Infinite loop */
  for(;;)
  {    //Değişken 1 olduğu zaman 100ms aralıklarla bağlı olan ledleri yakıp söndürür
	  if(BlinkFlag == 1)HAL_GPIO_TogglePin(GPIOG, GPIO_PIN_13 | GPIO_PIN_14);
    osDelay(100);
  }
  /* USER CODE END 5 */
}
  
#include <gui/screen1_screen/Screen1View.hpp>
#include "main.h"
// LED'in yanıp sönme durumunu belirlemek için kullanılan bayrak değişkeni
uint8_t BlinkFlag;

Screen1View::Screen1View()
{

}

void Screen1View::setupScreen()
{
    // Ekran ilk açıldığında çağrılan fonksiyon
    // TouchGFX tarafından oluşturulan temel yapılandırmayı çağırır
    Screen1ViewBase::setupScreen();
}

void Screen1View::tearDownScreen()
{
    // Ekran kapatıldığında çağrılan fonksiyon
    // TouchGFX tarafından oluşturulan temel temizleme işlemini çağırır
    Screen1ViewBase::tearDownScreen();
}

void Screen1View::led_on()
{
    // GPIOG portundaki 13 ve 14 numaralı pinleri yüksek seviyeye çekerek LED'leri aç
	HAL_GPIO_WritePin(GPIOG	, GPIO_PIN_13 | GPIO_PIN_14, GPIO_PIN_SET);
	BlinkFlag = 0;

}
void Screen1View::led_off()
{
     // GPIOG portundaki 13 ve 14 numaralı pinleri düşük seviyeye çekerek LED'leri kapat
	HAL_GPIO_WritePin(GPIOG	, GPIO_PIN_13 | GPIO_PIN_14, GPIO_PIN_RESET);
	BlinkFlag = 0;

}
void Screen1View::led_blink()
{
    // BlinkFlag'ı 1 yaparak, LED'in yanıp sönme moduna geçmesini sağla
	BlinkFlag = 1;
}
```
## Görseller ve Videolar
<p align="center">
<img src="https://github.com/yavuzselimpek/STM32F4_Led_On/blob/master/002_LED_ON/Documents/resim1.png">
<p align="center">
<img src="https://github.com/yavuzselimpek/STM32F4_Led_On/blob/master/002_LED_ON/Documents/resim2.jpg">

Görsellerde de görüldüğü üzere, GPIOG portundaki 13 ve 14 numaralı pinler, "LED ON" butonuna basıldığında aktif hale gelerek LED'leri yakmaktadır. Çalışma videosuna Documents klasöründen erişebilirsiniz.

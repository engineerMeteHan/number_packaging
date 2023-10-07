/*********************************************
* To illustrate the use of bitwise operator  *
* let's consider the folloving program that  *
* packages three numbers into a short 16-bit *
* integer and then unpack them               *
*********************************************/

/// Metehan Gencer
// Date : 2023 - 10 - 07

#include <stdio.h>
#define GUN_UZ     5
#define AY_UZ      4
#define TABAN_YIL  1950
#define TAVAN_YIL  (TABAN_YIL + (1 << 16 - GUN_UZ - AY_UZ) - 1)

int main(void)
{
    unsigned const ay_ortu = ~(~0 << AY_UZ);
    unsigned const gun_ortu = ~(~0 << GUN_UZ);
    unsigned yil, ay, gun;
    unsigned short tarih;

    do {
        scanf("%u%u%u", &yil, &ay, &gun);
    }while (yil < TABAN_YIL || yil > TAVAN_YIL || ay < 1 || ay > 12 || gun < 1 || gun > 31);

    yil -= TABAN_YIL;
    tarih = (yil << AY_UZ | ay) << GUN_UZ | gun;
    printf("Paketleme tamamlandi: %ho\n", tarih);

    yil = ay = gun = 0;     // Clear values
    gun = tarih & gun_ortu;
    ay = (tarih >> GUN_UZ) & ay_ortu;
    yil = tarih >> (GUN_UZ + AY_UZ);
    printf("Acma tamalandi.\nTarih: %u %u %u\n",
           yil + TABAN_YIL, ay, tarih);
    return 0;
}  /// main()

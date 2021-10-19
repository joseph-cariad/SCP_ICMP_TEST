#include <stdio.h>
#include <led_flash_handler.h>


int main()
{
    printf("9 is for button 1\n");
    printf("0 is for button 2\n");
    printf("1...6 is for target\n");


    uint8_t target_holder=6;
    led_4_5_6_handler(target_holder);

    int test_sample_input;

    for(int i=0;i<3;i++){


    scanf("%d",&test_sample_input);
    if (test_sample_input==0){
        led_2_handler (true);
        printf("delay of 250ms\n");
        led_2_handler (false);
    }else if (test_sample_input==9){
        led_1_handler (true);
        printf("delay of 250ms\n");
        led_1_handler (false);
        target_holder++;
        if (target_holder==7){
            target_holder=1;
        }
        led_4_5_6_handler(target_holder);
    }

    }
    return 0;
}

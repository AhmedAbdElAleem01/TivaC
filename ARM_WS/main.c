#include "lm4f120h5qr.h"

#define  LED_RED         (1U << 1) 
#define  LED_GREEN       (1U << 2)
#define  LED_BLUE        (1U << 3)
#define  PORTF_CLOCKGATE (1U << 5)

void delay(void);

int main()
{
  // 1 ) write the clock gating bit for port f
   SYSCTL_RCGCGPIO_R = PORTF_CLOCKGATE;
  
  // 2 ) enable digtal function for red, green , blue Led pins
   GPIO_PORTF_DEN_R  = LED_RED | LED_GREEN | LED_BLUE;
  
  // 3 ) direction to output
  GPIO_PORTF_DIR_R  =  LED_RED | LED_GREEN | LED_BLUE;
  
  // 4 ) write output data 
  while(1)
  {
      GPIO_PORTF_DATA_R  |=  LED_RED;
      delay();
      GPIO_PORTF_DATA_R  &=  ~LED_RED;
      delay();
  }

}

void delay(void)
{
  volatile unsigned int counter = 0;
  while(counter < 1000000)
  {
     counter ++;
  }
}

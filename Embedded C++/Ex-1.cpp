#include <lpc214x.h>
#define LED_PIN (1 << 0) 
class LED 
{
	public:
		LED()
		{
			IODIR0 = LED_PIN;
			IOSET0= LED_PIN;
		}
		void on() 
		{
			 IOCLR0=LED_PIN;
		}
		void off() 
		{

			IOSET0=LED_PIN;  
		}
		void toggle() 
		{
			if (IOPIN0 & LED_PIN) 
			{
				on(); 
			} 
			else 
			{
				off(); 
			}
		}
};

int main() 
{
	LED led; 
	while(1)
	{
		led.toggle();
		for(volatile int i=0;i<1000000;i++);
	}
	return 0;
}
#include <linux/init.h>
#include <linux/module.h>
#include <linux/kthread.h>
#include <linux/delay.h>
#include <linux/gpio.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Uchchhwash");
MODULE_DESCRIPTION("TRAFFIC LIGHT & LED BLINKER");

//

#define A1  4 // Red Light
#define A2  17 // Yellow Light
#define A3  27 // Green Light
#define BLINK 18 // Blue Blink Light
#define BUZZER 14 // Buzzer 
#define OE  22 // Control Serial Communication
#define LE  23 // Control Serial Communication
#define SDI 24 // Serial Data Pin
#define CLK 25 // Clock Pin


static int i=0;
static int choice=0;
static int input=0;
module_param(choice, int , 0);
module_param(input, int , 0);

void simple_gpio_init(void){

printk(KERN_INFO "GPIO Driver  Started.");

if(choice==1)
{	
	printk(KERN_INFO "Traffic Signal Started");
  
	for(i= 1;i<=input;i++)
	{
	  gpio_request(A1, "A1");
	  gpio_request(A2, "A2");
	  gpio_request(A3, "A3");
	
	  gpio_request(OE, "OE");
	  gpio_request(LE, "LE");
	  gpio_request(SDI, "SDI");
	  gpio_request(CLK, "CLK");
	
	  gpio_direction_output(A1, 1);
		msleep(1000);
          gpio_direction_output(A1, 0);

	  gpio_direction_output(A2, 1);
		msleep(500);
          gpio_direction_output(A2, 0);
          gpio_direction_output(A3, 1);
		msleep(1000);	  
	  gpio_direction_output(A3, 0);
	
	  gpio_direction_output(OE, 1);
	  gpio_direction_output(LE, 0);
	  gpio_direction_output(SDI, 0);
	  gpio_direction_output(CLK, 0);
	}
}

else if(choice==2)
{	  
	printk(KERN_INFO "Light Blink Started");
	
	for(i=0;i<input;i++)
	{
		  gpio_request(BLINK, "BLINK");
		  gpio_request(OE, "OE");
		  gpio_request(LE, "LE");
		  gpio_request(SDI, "SDI");
		  gpio_request(CLK, "CLK");
	
	  	  gpio_direction_output(BLINK, 1);
	          gpio_direction_output(BUZZER, 1);
		  msleep(300);
		  gpio_direction_output(OE, 1);
		  gpio_direction_output(LE, 0);
		  gpio_direction_output(SDI, 0);
	  	  gpio_direction_output(CLK, 0);

		  gpio_direction_output(BLINK, 0);
                  gpio_direction_output(BUZZER, 0);
		  msleep(200);
	}
		
}
  printk(KERN_INFO "GPIO Task Done");
}

void simple_gpio_exit(void){

	if(choice==1)
	{
		  		
		  gpio_direction_output(A1, 0);
			
		  gpio_direction_output(A2, 0);
			
		  gpio_direction_output(A3, 0);
			
		  gpio_free(A1);
		  gpio_free(A2);
		  gpio_free(A3);
		
		  gpio_free(OE);
		  gpio_free(LE);
		  gpio_free(SDI);
  		  gpio_free(CLK);
		  printk(KERN_INFO "Traffic Signal Stopped");
	}

	else if(choice==2)
	{
	
		  gpio_direction_output(BLINK, 0);
		  gpio_direction_output(BUZZER, 0);
			
		  gpio_free(BLINK);
		  gpio_free(BUZZER);
		
		  gpio_free(OE);
		  gpio_free(LE);
		  gpio_free(SDI);
  		  gpio_free(CLK);
		    printk(KERN_INFO "Traffic Blink Stopped");
	}
}


//

static int __init simple_init(void){
  printk(KERN_INFO "Staring");
  simple_gpio_init();

  printk(KERN_INFO "Staring done.");
  return 0;
}

static void __exit simple_exit(void){
  printk(KERN_INFO "Stopping Kernal");

  printk(KERN_INFO "Kernal Module Stopped");
}

module_init(simple_init);
module_exit(simple_exit);
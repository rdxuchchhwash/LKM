// sudo make -C /lib/modules/$(uname -r)/build M=$(pwd) modules
#include <linux/module.h>
#include <linux/moduleparam.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/stat.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Uchchhwash");
MODULE_DESCRIPTION("Simple Kernal Program");


static int choice;
 
static int value1 = 300;
static int value2 = 200;
static int a;
static int b;
static char *mystring;
static int length =0;



module_param(a, int , 0);
module_param(b, int , 0);
module_param(choice, int , 0);
module_param(mystring, charp , 0);



static int __init simpleModuleStart(void)
{		if(choice==1)
		{
			printk(KERN_INFO "Value 1 is : %d and Value 2 is : %d",value1 , value2);
			printk(KERN_INFO "Addtion of Value 1 and Value 2 is: %d", value1+value2);
			printk(KERN_INFO "Value of A is %d", a);
			printk(KERN_INFO "Value of B is %d", b);
			printk(KERN_INFO "Addtion of A & B is: %d", a+b);
		}

		else if(choice==2)
		{
			length=strlen (*s);
			printk(KERN_INFO "Length Of String is: %d", length);

		}
	
	return 0;
	
}


static void __exit simpleModuleExit(void)
{
	printk(KERN_INFO "Goodbye, world 5\n");
}

module_init(simpleModuleStart);
module_exit(simpleModuleExit);

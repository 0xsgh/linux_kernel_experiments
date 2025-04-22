
#include <linux/mm.h>
#include <linux/miscdevice.h>
#include <linux/slab.h>
#include <linux/vmalloc.h>
#include <linux/mman.h>
#include <linux/random.h>
#include <linux/init.h>
#include <linux/tty.h>
#include <linux/capability.h>
#include <linux/ptrace.h>
#include <linux/device.h>
#include <linux/highmem.h>
#include <linux/backing-dev.h>
#include <linux/shmem_fs.h>
#include <linux/splice.h>
#include <linux/pfn.h>
#include <linux/export.h>
#include <linux/io.h>
#include <linux/uio.h>
#include <linux/uaccess.h>
#include <linux/security.h>

#define DEVMINOR 14

MODULE_LICENSE( "GPL" );



static ssize_t readFromDevice( struct file *file,
			       char __user *buf,
			       size_t count,
			       loff_t *ppos )
{
	return 0;
}

static ssize_t writeToDevice( struct file *file,
			      const char __user *buf,
			      size_t count,
			      loff_t *ppos )
{
	return count;
}

static struct file_operations const deviceFileOperations =
    {
	.read = readFromDevice,
	.write = writeToDevice
    };



static struct class* deviceClass = NULL;
static int deviceMajorNumber = -1;

static int __init createVoidDevice(void)
{
    deviceMajorNumber = register_chrdev( 0, "void", &deviceFileOperations );

    deviceClass = class_create( "void" );

    device_create( deviceClass, NULL, MKDEV( deviceMajorNumber, DEVMINOR ), NULL, "void" );

    return 0;
}

static void __exit unloadVoidDevice( void )
{
    pr_info( "Unloading void...\n" );

    device_destroy( deviceClass, MKDEV( deviceMajorNumber, DEVMINOR ) );
    class_destroy( deviceClass );
    unregister_chrdev( deviceMajorNumber, "void" );
}



module_init( createVoidDevice );
module_exit( unloadVoidDevice );

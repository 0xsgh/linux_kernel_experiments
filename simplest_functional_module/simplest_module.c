
#include <linux/module.h>
#include <linux/printk.h>

MODULE_LICENSE( "GPL" );

static int __init
initModule( void )
{
    pr_info( "Loading 'simplest_module'..." );

    return 0;
}

static void __exit
exitModule( void )
{
    pr_info( "Unloading 'simplest_module'..." );
}

module_init( initModule );
module_exit( exitModule );

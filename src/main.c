#include <zephyr/zephyr.h>
#include <sys_clock.h>
#include "thelib.h"

void k_sys_fatal_error_handler(unsigned int reason, const z_arch_esf_t *esf) {
        switch (reason) {
        case K_ERR_CPU_EXCEPTION :
                printk("FATAL ERROR: Generic CPU exception\n");
                break;
        default :
                printk("FATAL ERROR: Unknown (%d)\n", reason);
                break;
        }

        printk("r0 %X\n", esf->basic.r0);
        printk("r1 %X\n", esf->basic.r1);
        printk("r2 %X\n", esf->basic.r2);
        printk("r3 %X\n", esf->basic.r3);
        printk("r12 (ip)  %X\n", esf->basic.r12);
        printk("r14 (lr) %X\n", esf->basic.r14);
        printk("r15 (pc) %X\n", esf->basic.r15);
        printk("xpsr %X\n", esf->basic.xpsr);        
        
}


void main(void) {

        call_me();
        
        while (1) {
                double res = 1/CONFIG_SYS_CLOCK_TICKS_PER_SEC;
                uint32_t uptime =  k_uptime_ticks();
                k_sleep(K_MSEC(1000));
                uint32_t tot =  k_uptime_ticks() - uptime;
                printk("timing %s %ldus %d\n", CONFIG_BOARD, tot*100, CONFIG_SYS_CLOCK_TICKS_PER_SEC);
                
        }
}

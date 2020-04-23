#ifdef data
    #define _interrupt(x)
    #define _interrupt_using(irq,x)
    #define _at(x)
#else
    #define interrupt(x) interruptx
    #define _interrupt_using(irq,x) interrupt irq usingx
    #define _at(x) _at_x
#endif
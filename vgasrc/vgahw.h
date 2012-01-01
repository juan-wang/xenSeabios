#ifndef __VGAHW_H
#define __VGAHW_H

#include "types.h" // u8
#include "config.h" // CONFIG_*

#include "clext.h" // clext_set_mode
#include "bochsvga.h" // bochsvga_set_mode
#include "stdvga.h" // stdvga_set_mode
#include "geodelx.h" // geodelx_init

static inline int vgahw_set_mode(int mode, int flags) {
    if (CONFIG_VGA_CIRRUS)
        return clext_set_mode(mode, flags);
    if (CONFIG_VGA_BOCHS)
        return bochsvga_set_mode(mode, flags);
    return stdvga_set_mode(mode, flags);
}

static inline int vgahw_init(void) {
    if (CONFIG_VGA_CIRRUS)
        return clext_init();
    if (CONFIG_VGA_BOCHS)
        return bochsvga_init();
    if (CONFIG_VGA_GEODELX)
        return geodelx_init();
    return stdvga_init();
}

#endif // vgahw.h

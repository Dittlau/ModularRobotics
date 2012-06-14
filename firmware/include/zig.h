#ifndef _ZIG_HEADER
#define _ZIG_HEADER

#define LINK_PLUGIN 0x80
#define ENABLE_RXD_LINK_PC 0x20
#define ENABLE_RXD_LINK_ZIGBEE 0x40

void wire_initialize();
void zigbee_initialize();

#endif
/* dumped in little endian order.
   use `mrbc -E` option for big endian CPU. */
#include <stdint.h>
extern const uint8_t greet[];
const uint8_t
#if defined __GNUC__
__attribute__((aligned(4)))
#elif defined _MSC_VER
__declspec(align(4))
#endif
greet[] = {
0x45,0x54,0x49,0x52,0x30,0x30,0x30,0x34,0x18,0x50,0x00,0x00,0x00,0xfd,0x4d,0x41,
0x54,0x5a,0x30,0x30,0x30,0x30,0x49,0x52,0x45,0x50,0x00,0x00,0x00,0xbd,0x30,0x30,
0x30,0x30,0x00,0x00,0x00,0x48,0x00,0x01,0x00,0x03,0x00,0x02,0x00,0x00,0x00,0x08,
0x48,0x00,0x80,0x00,0xc0,0x00,0x00,0x01,0x46,0x00,0x80,0x00,0x48,0x00,0x80,0x00,
0xc0,0x02,0x00,0x01,0x46,0x40,0x80,0x00,0x84,0x00,0x80,0x00,0x4a,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x02,0x00,0x05,0x68,0x65,0x6c,0x6c,0x6f,0x00,
0x00,0x03,0x62,0x79,0x65,0x00,0x00,0x00,0x00,0x3b,0x00,0x03,0x00,0x05,0x00,0x00,
0x00,0x00,0x00,0x05,0x26,0x00,0x00,0x02,0x3d,0x00,0x80,0x01,0x01,0x40,0x00,0x02,
0x3e,0x00,0x81,0x01,0x29,0x00,0x80,0x01,0x00,0x00,0x00,0x02,0x00,0x00,0x07,0x48,
0x65,0x6c,0x6c,0x6f,0x2c,0x20,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x39,0x00,0x03,0x00,0x05,0x00,0x00,0x00,0x00,0x00,0x05,0x00,0x26,0x00,0x00,0x02,
0x3d,0x00,0x80,0x01,0x01,0x40,0x00,0x02,0x3e,0x00,0x81,0x01,0x29,0x00,0x80,0x01,
0x00,0x00,0x00,0x02,0x00,0x00,0x05,0x42,0x79,0x65,0x2c,0x20,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x4c,0x56,0x41,0x52,0x00,0x00,0x00,0x22,0x00,0x00,0x00,0x01,0x00,
0x04,0x6e,0x61,0x6d,0x65,0x00,0x00,0x00,0x01,0xff,0xff,0x00,0x00,0x00,0x00,0x00,
0x01,0xff,0xff,0x00,0x00,0x45,0x4e,0x44,0x00,0x00,0x00,0x00,0x08,
};

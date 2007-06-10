/**
 * =========================================================================
 * File        : aken.h
 * Project     : 0 A.D.
 * Description : Aken driver interface
 * =========================================================================
 */

// license: GPL; see lib/license.txt

// Aken - custodian of the ferryboat to the underworld in Egyptian mythology,
// and a driver that shuttles between applications and kernel mode resources.

#ifndef INCLUDED_AKEN
#define INCLUDED_AKEN

#define AKEN_NAME "Aken"

// device type
#define FILE_DEVICE_AKEN 53498	// in the "User Defined" range."

#define AKEN_IOCTL 0x800	// 0x800..0xFFF are for 'customer' use.

#define IOCTL_AKEN_READ_PORT           CTL_CODE(FILE_DEVICE_AKEN, AKEN_IOCTL+0, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IOCTL_AKEN_WRITE_PORT          CTL_CODE(FILE_DEVICE_AKEN, AKEN_IOCTL+1, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IOCTL_AKEN_MAP                 CTL_CODE(FILE_DEVICE_AKEN, AKEN_IOCTL+2, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IOCTL_AKEN_UNMAP               CTL_CODE(FILE_DEVICE_AKEN, AKEN_IOCTL+3, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IOCTL_AKEN_COPY_PHYSICAL       CTL_CODE(FILE_DEVICE_AKEN, AKEN_IOCTL+4, METHOD_BUFFERED, FILE_ANY_ACCESS)


// input and output data structures for the IOCTLs

#pragma pack(push, 1)

struct AkenReadPortIn
{
	USHORT port;
	UCHAR numBytes;
};

struct AkenReadPortOut
{
	DWORD32 value;
};

struct AkenWritePortIn
{
	DWORD32 value;
	USHORT port;
	UCHAR numBytes;
};

struct AkenMapIn
{
	// note: fixed-width types allow the 32 or 64-bit Mahaf wrapper to
	// interoperate with the 32 or 64-bit Aken driver.
	DWORD64 physicalAddress;
	DWORD64 numBytes;
};

struct AkenMapOut
{
	DWORD64 virtualAddress;
};

struct AkenUnmapIn
{
	DWORD64 virtualAddress;
};

struct AkenCopyPhysicalIn
{
	DWORD64 physicalAddress;
	DWORD64 numBytes;
	DWORD64 userAddress;
};

#pragma pack(pop)

#endif	// #ifndef INCLUDED_AKEN

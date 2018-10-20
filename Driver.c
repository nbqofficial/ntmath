/*
		MADE BY NBQ
*/



#include <ntddk.h>
#include "ntmath.h"

VOID DbgPrintFloat(_In_ float x) // SPECIAL THANKS TO FLAPJACKS (https://github.com/0xFJ) FOR THIS FUNCTION
{
	int ax = (int)x; // converts float to int until the decimal point
	int bx = qabs((int)(x * 1000) % 1000); // rest of the float after decimal point
	DbgPrintEx(0, 0, "%d.%03d\n", ax, bx); // prints out the float value in kernel debug (DebugView)
}

VOID DriverUnload(_In_ PDRIVER_OBJECT DriverObject) // basic driver unload routine
{
	UNREFERENCED_PARAMETER(DriverObject);
	DbgPrintEx(0, 0, "Unloaded!\n");
}

NTSTATUS DriverEntry(_In_ PDRIVER_OBJECT DriverObject, _In_ PUNICODE_STRING RegistryPath)
{
	UNREFERENCED_PARAMETER(DriverObject);
	UNREFERENCED_PARAMETER(RegistryPath);

	DriverObject->DriverUnload = DriverUnload;
	
	float x = 13.37f;

	float sqrt = qsqrt(x);
	float atan = qatan(x);
	float atan2 = qatan2(x,2);
	float acos = qacos(x);
	float abs = qabs(x);
	float min = qmin(x, X_PI);
	float max = qmax(x, X_DIV);

	DbgPrintFloat(x);

	return STATUS_SUCCESS;
}
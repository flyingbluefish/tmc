//File: TestO.globals.c 
//Generated by TMC Converter(C)2009-2013
#include "tmc.h"
#include "TestO.globals.h"

tmsMatrix	*pRefHelper;
tmsMatrix	*pGetHelper;
tmsMatrix *VV;
void tmcInitGlobals(void)
{
VV=tmcNewMatrix();
}
void tmcFreeGlobals(void)
{
tmcFreeLocalVar(VV);
}

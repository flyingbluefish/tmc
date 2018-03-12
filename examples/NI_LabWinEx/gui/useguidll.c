/*---------------------------------------------------------------------------*/
/*                                                                           */
/* FILE:    useguidll.c                                                      */
/*                                                                           */
/* PURPOSE: This project demonstrates how to call into a 32-bit DLL that     */
/*          implements it's own GUI in LabWindows/CVI.  In order for the     */
/*          RunDLLUI function to link properly, you will need to add the DLL */
/*          import library for the DLL to your project.  The import library  */
/*          will be generated by Labwindows/CVI when you build the guidll    */
/*          project.                                                         */
/*                                                                           */
/*---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*/
/* Include files                                                             */
/*---------------------------------------------------------------------------*/
#include <cvirte.h>  
#include "guidll.h" /* Notice we need the DLL function prototypes */
#include <userint.h>

/*---------------------------------------------------------------------------*/
/* This is the application's entry-point.                                    */
/*---------------------------------------------------------------------------*/
int main (int argc, char *argv[])
{
    if (InitCVIRTE (0, argv, 0) == 0) 
        return -1; 
    
//    MessagePopup ("Using a CVI DLL", "Ready to call RunDLLUI in guidll.dll");
    
    /* When we call this function, the DLL displays and runs its own GUI.    */
    /* We will not return from this function until the UI is finished.       */
    RunDLLUI ();
    
//    MessagePopup ("Using a CVI DLL", "Returned from RunDLLUI");
    CloseCVIRTE ();
    return 0;
}

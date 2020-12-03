/******************* Minimal Motif tooltip example *********************
 * - Build:
             gcc motif_tooltip.c -o motif_tooltip -lXm -lXt
 * - Run:
             ./motif_tooltip [any X command-line options ...]
 **********************************************************************/
#include <stdio.h>
#include <Xm/PushB.h>   /* Assumes either /usr/include/Xm/ or /usr/local/include/Xm/ exists */

int main(int argc,char** argv) {
Widget        toplevel;
XtAppContext  app;
XmString      tooltipString = XmStringCreateLocalized("The button's tooltip"); /* Small, one-time memory leak */

  XtSetLanguageProc(NULL,NULL,NULL);
  toplevel = XtVaAppInitialize(&app,"Hello with tooltip",NULL,0,&argc,argv,NULL
                              ,XmNtoolTipEnable,True  /* Accept default delay and duration; both are 5000ms */
                              ,NULL);

  XtVaCreateManagedWidget("Hover cursor here to see button's tooltip after 5s delay",xmPushButtonWidgetClass,toplevel
                         ,XmNtoolTipString,tooltipString /* XmStringFree(tooltipString) normally called next */
                         ,NULL);

  XtRealizeWidget(toplevel);
  XtAppMainLoop(app);
  return 0;
}

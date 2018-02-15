/*
 *  py_messages.c
 *  This file is part of LIME, the versatile line modeling engine
 *
 *  Copyright (C) 2006-2014 Christian Brinch
 *  Copyright (C) 2015-2017 The LIME development team
 *
 */

#include "lime.h"
#include "py_lime.h" /* for function definitions */

/*....................................................................*/
void
printOrClearPyError(void){
  /* This can cause a problem if called when !PyErr_Occurred(). */
  if(silent)
    PyErr_Clear();
  else
    PyErr_Print(); /* Also clears. */
}

/*....................................................................*/
void
pywarning(char *message){
  if(!silent) warning(message);
  Py_Exit(1);
}

/*....................................................................*/
void
pyerror(char *message){
  if(!silent) bail_out(message);
  Py_Exit(1);
}



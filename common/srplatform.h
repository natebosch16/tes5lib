/*===========================================================================
 *
 * File:	Srplatform.H
 * Author:	Dave Humphrey (dave@uesp.net)
 * Created On:	25 November 2011
 *
 * Contains platform specific definitions.
 *
 *=========================================================================*/
#ifndef __SRPLATFORM_H
#define __SRPLATFORM_H


/*===========================================================================
 *
 * Begin Required Includes
 *
 *=========================================================================*/
  #include "srtypes.h"
/*===========================================================================
 *		End of Required Includes
 *=========================================================================*/


/*===========================================================================
 *
 * Begin Definitions
 *
 *=========================================================================*/

	/* snprintf() implementation can vary on various platforms */
#ifdef _WIN32
  #define SSVSNPRINTF _vsnprintf
  #define SSSNPRINTF  _snprintf
#else
  #define SSVSNPRINTF vsnprintf
  #define SSSNPRINTF  snprintf
#endif  

/*===========================================================================
 *		End of Definitions
 *=========================================================================*/


#endif
/*===========================================================================
 *		End of File Srplatform.H
 *=========================================================================*/

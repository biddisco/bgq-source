/* begin_generated_IBM_copyright_prolog                             */
/*                                                                  */
/* This is an automatically generated copyright prolog.             */
/* After initializing,  DO NOT MODIFY OR MOVE                       */
/* ================================================================ */
/*                                                                  */
/* Licensed Materials - Property of IBM                             */
/*                                                                  */
/* Blue Gene/Q                                                      */
/*                                                                  */
/* (C) Copyright IBM Corp.  2010, 2012                              */
/*                                                                  */
/* US Government Users Restricted Rights -                          */
/* Use, duplication or disclosure restricted                        */
/* by GSA ADP Schedule Contract with IBM Corp.                      */
/*                                                                  */
/* This software is available to you under the                      */
/* Eclipse Public License (EPL).                                    */
/*                                                                  */
/* ================================================================ */
/*                                                                  */
/* end_generated_IBM_copyright_prolog                               */

#ifndef _KERNEL_H_ // Prevent multiple inclusion.
#define _KERNEL_H_

//
// Kernel master-include file.
//
#include <hwi/include/common/compiler_support.h>

#if defined(__KERNEL__) && !defined(__ASSEMBLY__)

#include <stdio.h>
#include <stdint.h>
#include <stdarg.h>
#include <stddef.h>
#include <string.h>
#include <sys/types.h>

#ifdef __cplusplus
extern "C" {
#endif

#include <cnk/include/Config.h>
#include <cnk/include/kcounters.h>

#include <hwi/include/common/asm_support.h>
#include <hwi/include/common/bgq_bitnumbers.h>
#include <firmware/include/personality.h>
#include <hwi/include/common/bgq_alignment.h>
#include <firmware/include/Firmware_Interface.h>

#include <hwi/include/bqc/A2_core.h>
#include <hwi/include/bqc/A2_inlines.h>
#include <hwi/include/bqc/BeDram.h>
#include <firmware/include/BeDram_inlines.h>
    
#include "atomicops.h"

#include <cnk/include/klibtypes.h>
#include "Kernel_Linkage.h"
#include "mmap.h"
#include "file.h"
#include <cnk/include/SPRG_Usage.h>
#include "Regs.h"
#include "Debug.h"
#include "syscalls.h"
#include <cnk/include/SPI_syscalls.h>
#include "Sched.h"
#include "KThread.h"
#include "CoreState.h"
#include <cnk/include/AppState.h>
#include <spi/include/kernel/spec.h>
#include "network/network.h"
#include "signal.h"
#include "AppProcess.h"
#include "NodeState.h"
#include "vmm.h"
#include "futex.h"
#include "timers.h"
#include "lock.h"
#include "speculation.h"
#include "tool.h"
#include "core2core.h"
#include "Personality_inlines.h"
#include "Trace.h"
#include "align.h"
#include "powermgmt.h"
#include "CoreDump.h"
#include "syscalls/internalsyscalls.h"
//#include "rank.h"

//#include "util.h"

extern void Kernel_Begin( void );
extern void Kernel_Finish( void );
extern void Kernel_Halt(void);
extern void Kernel_EntryPrimary(Firmware_Interface_t* fw_interface);
extern void Kernel_EntrySecondary(void* fw_interface);


#ifdef __cplusplus
}
#endif

extern NodeState_t NodeState; // main.c

#endif // __KERNEL__ and not __ASSEMBLY__

#endif // Add nothing below this line.


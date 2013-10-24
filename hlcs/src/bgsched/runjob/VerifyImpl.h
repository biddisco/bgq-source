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
/* (C) Copyright IBM Corp.  2010, 2011                              */
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
#ifndef BGSCHED_RUNJOB_VERIFY_IMPL_H
#define BGSCHED_RUNJOB_VERIFY_IMPL_H

#include <bgsched/runjob/Verify.h>

namespace bgsched {
namespace runjob {

class Verify::Impl
{
public:
    Impl();

    DenyJob::Value _denyJob;        //!< flag to prevent starting the job.
    pid_t _pid;                     //!< pid of the runjob process.
    std::string _exe;               //!< executable.
    Arguments _args;                //!< arguments.
    Environments _envs;             //!< environment variables.
    std::string _block;             //!< block ID.
    Corner _corner;                 //!< sub-block corner.
    Shape _shape;                   //!< sub-block shape.
    std::string _schedulerData;     //!< scheduler data.
    std::string _message;           //!< error message.
    UserId _user;                   //!< credentials.
};

} // runjob
} // bgsched

#endif

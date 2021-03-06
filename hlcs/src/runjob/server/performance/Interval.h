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
#ifndef RUNJOB_MUX_PERFORMANCE_INTERVAL_H
#define RUNJOB_MUX_PERFORMANCE_INTERVAL_H

#include "server/fwd.h"

namespace runjob {
namespace server {
namespace performance {

/*!
 * \brief
 */
class Interval
{
public:
    /*!
     * \brief ctor.
     */
    explicit Interval(
            const Options& options  //!< [in]
            );

    /*!
     * \brief
     */
    unsigned get() const;

private:
    const Options& _options;
};
} // performance
} // server
} // runjob

#endif

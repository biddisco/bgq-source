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
#ifndef RUNJOB_CLIENT_TIMEOUT_H
#define RUNJOB_CLIENT_TIMEOUT_H

#include <boost/enable_shared_from_this.hpp>

#include <boost/asio.hpp>

namespace runjob {
namespace client {

class Job;

/*!
 * \brief Kill the job after a specified timeout interval.
 */
class Timeout : public boost::enable_shared_from_this<Timeout>
{
public:
    /*!
     * \brief ctor.
     */
    Timeout(
            boost::asio::io_service& io_service,    //!< [in]
            const boost::shared_ptr<Job>& job       //!< [in]
           );

    /*!
     * \brief dtor.
     */
    ~Timeout();

    /*!
     * \brief Start waiting.
     */
    void start(
            uint32_t value  //!< [in] number of seconds to wait
            );

    /*!
     * \brief Stop waiting.
     */
    void stop();

private:
    void __attribute__ ((visibility("hidden"))) handler(
            uint32_t value,
            const boost::system::error_code& error
            );

private:
    boost::asio::deadline_timer _timer;
    const boost::weak_ptr<Job> _job;
};

} // client
} // runjob

#endif

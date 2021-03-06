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
#ifndef RUNJOB_SAMPLES_FIND_A_NODE_HOSTNAME_H
#define RUNJOB_SAMPLES_FIND_A_NODE_HOSTNAME_H

#include <boost/asio/ip/host_name.hpp>

namespace find_a_node {

class Hostname
{
public:
    Hostname() :
        _name( boost::asio::ip::host_name() )
    {
        const std::string::size_type period = _name.find_first_of('.');
        _name.erase( period );
    }

    operator const std::string&() const { return _name; }

private:
    std::string _name;
};

} // find_a_node

#endif

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
/* (C) Copyright IBM Corp.  2012, 2012                              */
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

#ifndef MMCS_SERVER_COMMAND_LIST_BLOCK_AUTHORITY_H_
#define MMCS_SERVER_COMMAND_LIST_BLOCK_AUTHORITY_H_

#include "common/AbstractCommand.h"

namespace mmcs {
namespace server {
namespace command {

// This command 'does' its own security instead
// of going through the command processor.  While it operates
// on security objects, blocks, they don't use CRUDE actions.


/*!
 * List authority to security objects
*/
class ListBlockAuthority: public common::AbstractCommand
{
public:
    ListBlockAuthority(const char* name, const char* description, const Attributes& attributes)
      : AbstractCommand(name,description,attributes) { _usage = "list_block_authority < block >";}
    static  ListBlockAuthority* build();  // factory method
    void execute(std::deque<std::string> args,
                 mmcs_client::CommandReply& reply,
                 DBConsoleController* pController,
                 BlockControllerTarget* pTarget=NULL,
                 std::vector<std::string>* validnames = 0
            );
    void execute(std::deque<std::string> args,
                 mmcs_client::CommandReply& reply,
                 DBConsoleController* pController,
                 BlockControllerTarget* pTarget=NULL
            );

    bool checkArgs(std::deque<std::string>& args) { if (args.size() != 1) return false; else return true;}
    void help(std::deque<std::string> args,
              mmcs_client::CommandReply& reply);
};

} } } // namespace mmcs::server::command

#endif

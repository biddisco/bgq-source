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


define(
[
    "./AbstractQueryResultsDijit",
    "dojo/_base/declare",
    "dojo/text!./templates/ServiceCard.html"
],
function(
        l_AbstractQueryResultsDijit,
        d_declare,
        template
    )
{

var b_navigator_dijit_environmentals_ServiceCard = d_declare(
        [ l_AbstractQueryResultsDijit ],

{

    templateString : template,


    // override
    _getExtraFieldNames: function()
    {
        return [
                "v12p",
                "v12r5",
                "v15p",
                "v25p",
                "v33p",
                "v50p"
            ];
    }


} );

return b_navigator_dijit_environmentals_ServiceCard;

} );

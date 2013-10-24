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
    "dojo/_base/declare",
    "dijit/_TemplatedMixin",
    "dijit/_WidgetsInTemplateMixin",
    "dijit/layout/_LayoutWidget",
    "dojo/text!./templates/Explorer.html",

    // Used in template
    "../../dijit/Hideable",
    "dijit/form/Button",
    "dijit/form/Form",
    "dijit/form/Select",
    "dijit/form/Textarea",
    "dijit/form/TextBox",
    "dijit/layout/BorderContainer",
    "dijit/layout/ContentPane",
    "dojox/grid/EnhancedGrid",
    "dojox/grid/enhanced/plugins/IndirectSelection"
],
function(
        d_declare,
        j__TemplatedMixin,
        j__WidgetsInTemplateMixin,
        j_layout__LayoutWidget,
        template
    )
{


var b_explorer_dijit_Explorer = d_declare(
        [ j_layout__LayoutWidget, j__TemplatedMixin, j__WidgetsInTemplateMixin ],

{

    _d : "$", // If have ${} in the template HTML, replace $ with ${_d}, so gets turned into ${}.


    templateString : template,

    doLayout : true,
        // Boolean
        // If true, change the size of my currently displayed child to match my size


    // Override _LayoutWidget.
    layout : function()
    {
        if ( this.doLayout ) {
            this.getChildren()[0].resize( this._contentBox );
        } else {
            this.getChildren()[0].resize();
        }
    }

} );

return b_explorer_dijit_Explorer;


} );

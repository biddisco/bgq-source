#! /usr/bin/python
# begin_generated_IBM_copyright_prolog                             
#                                                                  
# This is an automatically generated copyright prolog.             
# After initializing,  DO NOT MODIFY OR MOVE                       
# ================================================================ 
#                                                                  
# Licensed Materials - Property of IBM                             
#                                                                  
# Blue Gene/Q                                                      
#                                                                  
# (C) Copyright IBM Corp.  2011, 2011                              
#                                                                  
# US Government Users Restricted Rights -                          
# Use, duplication or disclosure restricted                        
# by GSA ADP Schedule Contract with IBM Corp.                      
#                                                                  
# This software is available to you under the                      
# Eclipse Public License (EPL).                                    
#                                                                  
# ================================================================ 
#                                                                  
# end_generated_IBM_copyright_prolog                               

import os, string, sys, pprint, time

class Method:
    # -------------------- initialization ------------------    
    def __init__(self):
        self._body = [] # method is stored as a vector of lines

    # -------------------- setters -------------------------
    def addLine(self, line):
        self._body.append(line)

    # ------------------- generator method -----------------
    def writeImplementation(self):
        for l in self._body:
            print l,
        print

        

-- begin_generated_IBM_copyright_prolog                             --
--                                                                  --
-- This is an automatically generated copyright prolog.             --
-- After initializing,  DO NOT MODIFY OR MOVE                       --
-- ================================================================ --
--                                                                  --
-- Licensed Materials - Property of IBM                             --
--                                                                  --
-- Blue Gene/Q                                                      --
--                                                                  --
-- (C) Copyright IBM Corp.  2010, 2011                              --
--                                                                  --
-- US Government Users Restricted Rights -                          --
-- Use, duplication or disclosure restricted                        --
-- by GSA ADP Schedule Contract with IBM Corp.                      --
--                                                                  --
-- This software is available to you under the                      --
-- Eclipse Public License (EPL).                                    --
--                                                                  --
-- ================================================================ --
--                                                                  --
-- end_generated_IBM_copyright_prolog                               --
--
--  DESCRIPTION: creates tables for TEAL
--


CREATE TABLE X_TEALEVENTLOGEXT (
    REC_ID BIGINT NOT NULL , 
    TIME_LOGGED TIMESTAMP NOT NULL DEFAULT CURRENT TIMESTAMP, 
    SRC_LOC_TYPE VARCHAR(2) NOT NULL , 
    SRC_LOC VARCHAR(255) NOT NULL , 
    RPT_COMP VARCHAR(128) , 
    RPT_LOC_TYPE VARCHAR(2) , 
    RPT_LOC VARCHAR(255) , 
    ELAPSED_TIME BIGINT , 
    RAW_DATA_FMT BIGINT NOT NULL,
    RAW_DATA VARCHAR(1024),
    PRIMARY KEY (REC_ID)
);

CREATE TABLE x_tealalertlog (
  "rec_id" BIGINT GENERATED BY DEFAULT AS IDENTITY,
  "alert_id" CHAR(8) NOT NULL,
  "creation_time" TIMESTAMP NOT NULL DEFAULT CURRENT_TIMESTAMP,
  "severity" CHAR(1) NOT NULL,
  "urgency" CHAR(1) NOT NULL,
  "event_loc_type" VARCHAR(2) NOT NULL,
  "event_loc" VARCHAR(255) NOT NULL,
  "fru_loc" VARCHAR(512) default NULL,
  "recommendation" VARCHAR(2048) NOT NULL,
  "reason" VARCHAR(512) NOT NULL,
  "src_name" VARCHAR(64) NOT NULL,
  "state" SMALLINT default NULL,
  "raw_data" VARCHAR(2048) default NULL,
  "comment" VARCHAR(128),
  "disable" VARCHAR(128),
  "comments" VARCHAR(128),
  PRIMARY KEY  ("rec_id")
);

CREATE TABLE x_tealalert2event (
  "assoc_id" BIGINT GENERATED BY DEFAULT AS IDENTITY,
  "alert_recid" BIGINT NOT NULL,
  "assoc_type" CHAR NOT NULL,
  "t_event_recid" BIGINT NOT NULL,
  "comments" VARCHAR(128),
  "disable" VARCHAR(128),
  PRIMARY KEY  ("assoc_id"),
  CONSTRAINT TEAL_FK_EREC FOREIGN KEY ("alert_recid") REFERENCES X_TEALALERTLOG ("rec_id") ON DELETE CASCADE,
  CONSTRAINT TEAL_A2E_ASSOC_CHECK CHECK("assoc_type" IN ('C','S'))
);

CREATE TABLE x_tealalert2alert (
  "assoc_id" BIGINT GENERATED BY DEFAULT AS IDENTITY,
  "alert_recid" BIGINT NOT NULL,
  "assoc_type" CHAR NOT NULL,
  "t_alert_recid" BIGINT NOT NULL,
  "comments" VARCHAR(128),
  "disable" VARCHAR(128),
  PRIMARY KEY  ("assoc_id"),
  CONSTRAINT TEAL_FK_AREC  FOREIGN KEY ("alert_recid") REFERENCES X_TEALALERTLOG ("rec_id") ON DELETE CASCADE,
  CONSTRAINT TEAL_FK_T_AREC FOREIGN KEY ("t_alert_recid") REFERENCES X_TEALALERTLOG ("rec_id") ON DELETE RESTRICT,
  CONSTRAINT TEAL_A2A_ASSOC_CHECK CHECK("assoc_type" IN ('C','S','D'))
);

CREATE TABLE x_tealcheckpoint (
  "chkpt_id" BIGINT GENERATED BY DEFAULT AS IDENTITY,
  "name" VARCHAR(128) NOT NULL,
  "status" CHAR(1) DEFAULT NULL, 
  "event_recid" BIGINT DEFAULT NULL,
  "data" VARCHAR(1024) DEFAULT NULL,
  "comments" VARCHAR(128),
  "disable" VARCHAR(128),
  PRIMARY KEY  ("chkpt_id")
);

CREATE TRIGGER TEAL_DUPALERT_DELETE AFTER DELETE ON X_TEALALERT2ALERT REFERENCING OLD AS OLD FOR EACH ROW BEGIN ATOMIC IF (OLD."assoc_type" = 'D') THEN DELETE FROM X_TEALALERTLOG WHERE "rec_id" = OLD."t_alert_recid"; END IF; END;
CREATE TRIGGER TEAL_ALERTLOG_DELETE BEFORE DELETE ON X_TEALALERTLOG REFERENCING OLD AS OLD FOR EACH ROW BEGIN ATOMIC IF (OLD."state" = 1) THEN SIGNAL SQLSTATE '70003' ('Deletion not permitted'); END IF; END;

CREATE VIEW X_TEALEVENTLOG (
    "rec_id", 
    "event_id", 
    "time_logged", 
    "time_occurred", 
    "src_comp", 
    "src_loc_type", 
    "src_loc", 
    "rpt_comp", 
    "rpt_loc_type", 
    "rpt_loc", 
    "event_cnt", 
    "elapsed_time", 
    "raw_data_fmt", 
    "raw_data"
    ) AS
    SELECT TBGQEVENTLOG.RECID AS "rec_id", 
           TBGQEVENTLOG.MSG_ID AS  "event_id", 
           X_TEALEVENTLOGEXT.TIME_LOGGED AS "time_logged", 
           TBGQEVENTLOG.EVENT_TIME AS "time_occurred", 
           TBGQEVENTLOG.COMPONENT AS "src_comp", 
           X_TEALEVENTLOGEXT.SRC_LOC_TYPE AS "src_loc_type", 
           X_TEALEVENTLOGEXT.SRC_LOC AS "src_loc", 
           X_TEALEVENTLOGEXT.RPT_COMP AS "rpt_comp", 
           X_TEALEVENTLOGEXT.RPT_LOC_TYPE AS "rpt_comp_type", 
           X_TEALEVENTLOGEXT.RPT_LOC AS "rpt_loc", 
           TBGQEVENTLOG."COUNT" AS "event_cnt", 
           X_TEALEVENTLOGEXT.ELAPSED_TIME AS "elapsed_time", 
           X_TEALEVENTLOGEXT.RAW_DATA_FMT AS "raw_data_fmt", 
           X_TEALEVENTLOGEXT.RAW_DATA AS "raw_data"
   FROM TBGQEVENTLOG AS TBGQEVENTLOG, X_TEALEVENTLOGEXT AS X_TEALEVENTLOGEXT
   WHERE TBGQEVENTLOG.RECID = X_TEALEVENTLOGEXT.REC_ID;

CREATE VIEW X_BGQ_1_1 (
    "rec_id",
    "category",
    "severity",
    "jobid",
    "block",
    "serialnumber",
    "ecid",
    "cpu",
    "ctlaction",
    "message",
    "rawdata",
    "diags",    
    "qualifier") AS
    SELECT BGQEVENTLOG.RECID AS "rec_id",
           BGQEVENTLOG.CATEGORY AS "category", 
           BGQEVENTLOG.SEVERITY AS "severity", 
           BGQEVENTLOG.JOBID AS "jobid",
           BGQEVENTLOG.BLOCK AS "block", 
           BGQEVENTLOG.SERIALNUMBER AS "serialnumber", 
           BGQEVENTLOG.ECID AS "ecid",
           BGQEVENTLOG.CPU AS "cpu", 
           BGQEVENTLOG.CTLACTION AS "ctlaction", 
           BGQEVENTLOG.MESSAGE AS "message",
           BGQEVENTLOG.RAWDATA AS "rawdata",
           BGQEVENTLOG.DIAGS AS "diags",
           BGQEVENTLOG.QUALIFIER AS "qualifier"
   FROM TBGQEVENTLOG AS BGQEVENTLOG;


COMMIT;

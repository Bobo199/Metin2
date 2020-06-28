
SET FOREIGN_KEY_CHECKS=0;

DROP TABLE IF EXISTS `bank_log`;
CREATE TABLE `bank_log` (
  `Name` varchar(12) CHARACTER SET big5 NOT NULL DEFAULT 'Empty',
  `ID` int(11) DEFAULT NULL,
  `Type` varchar(20) CHARACTER SET big5 NOT NULL DEFAULT 'Empty',
  `ip` varchar(20) CHARACTER SET big5 NOT NULL DEFAULT 'Empty',
  `TargetName` varchar(12) CHARACTER SET big5 NOT NULL DEFAULT 'Empty',
  `TargetID` int(11) DEFAULT NULL,
  `Targetip` varchar(20) CHARACTER SET big5 NOT NULL DEFAULT 'Empty',
  `time` timestamp NOT NULL DEFAULT '0000-00-00 00:00:00'
) ENGINE=MyISAM DEFAULT CHARSET=latin1 COLLATE=latin1_general_cs ROW_FORMAT=FIXED;

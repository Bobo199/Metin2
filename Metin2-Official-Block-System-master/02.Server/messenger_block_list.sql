DROP TABLE IF EXISTS `messenger_block_list`;
CREATE TABLE `messenger_block_list` (
  `account` varchar(12) NOT NULL DEFAULT '',
  `companion` varchar(12) NOT NULL DEFAULT '',
  `Time` timestamp NOT NULL DEFAULT '0000-00-00 00:00:00',
  PRIMARY KEY (`account`,`companion`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;

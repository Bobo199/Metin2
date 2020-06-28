SET FOREIGN_KEY_CHECKS=0;

DROP TABLE IF EXISTS `mails`;
CREATE TABLE `mails` (
  `name`  varchar(30) NOT NULL DEFAULT '',
  `type` int(11) unsigned NOT NULL DEFAULT '0',
  `title`  varchar(40) NOT NULL DEFAULT '',
  `message`  varchar(100) NOT NULL DEFAULT '',
  `from`  varchar(30) NOT NULL DEFAULT '',
  `itemid` int(15) unsigned NOT NULL DEFAULT '0',
  `gold` int(11) unsigned NOT NULL DEFAULT '0',
  `won` int(11) unsigned NOT NULL DEFAULT '0',
  `id` int(15) unsigned NOT NULL DEFAULT '0',
  `read` int(15) unsigned NOT NULL DEFAULT '0',
  `date` datetime NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1 COLLATE=latin1_general_cs;
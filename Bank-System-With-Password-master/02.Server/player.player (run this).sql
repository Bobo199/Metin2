ALTER TABLE `player`
ADD COLUMN `bankpass` varchar(6) NOT NULL DEFAULT '000000' AFTER `alignment`;
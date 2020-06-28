ALTER TABLE `player`
ADD COLUMN `envanter` int(11) NOT NULL DEFAULT 0 AFTER `horse_skill_point`;
ALTER TABLE `player_deleted`
ADD COLUMN `envanter` int(11) NOT NULL DEFAULT 0 AFTER `horse_skill_point`;

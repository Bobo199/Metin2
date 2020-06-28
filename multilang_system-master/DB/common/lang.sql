/*
 Navicat Premium Data Transfer

 Source Server         : Metin2-Test
 Source Server Type    : MySQL
 Source Server Version : 50727
 Source Host           : 192.168.1.117:3306
 Source Schema         : common

 Target Server Type    : MySQL
 Target Server Version : 50727
 File Encoding         : 65001

 Date: 02/02/2020 17:43:14
*/

SET NAMES utf8mb4;
SET FOREIGN_KEY_CHECKS = 0;

-- ----------------------------
-- Table structure for lang
-- ----------------------------
DROP TABLE IF EXISTS `lang`;
CREATE TABLE `lang`  (
  `lang` varchar(20) CHARACTER SET utf32 COLLATE utf32_general_ci NOT NULL DEFAULT ''
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of lang
-- ----------------------------
INSERT INTO `lang` VALUES ('en');
INSERT INTO `lang` VALUES ('es');
INSERT INTO `lang` VALUES ('hu');
INSERT INTO `lang` VALUES ('ro');
INSERT INTO `lang` VALUES ('tr');
INSERT INTO `lang` VALUES ('de');

SET FOREIGN_KEY_CHECKS = 1;

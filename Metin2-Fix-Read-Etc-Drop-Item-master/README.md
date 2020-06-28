
# What's the issue?

SYSERR: Aug 22 18:36:42.624296 :: ReadEtcDropItemFile: No such an item (name:  Èò»ö  ´ó±â+) SYSERR:  
Aug 22 18:36:42.624379 :: Boot: cannot load ETCDropItem: locale/germany/etc_drop_item.txt

Some people fixed it long time ago by replacing the  column  **name** from  **item_proto**  (which is korean) with  **vnum**.

[![68747470733a2f2f692e6779617a6f2e636f6d2f39616463653961663637373166343966366162353162393166353035613539372e706e67](https://camo.githubusercontent.com/af455cc0d7dd96ceaca832e7ca53a7031f0c9f75/68747470733a2f2f692e6779617a6f2e636f6d2f39616463653961663637373166343966366162353162393166353035613539372e706e67)](https://camo.githubusercontent.com/af455cc0d7dd96ceaca832e7ca53a7031f0c9f75/68747470733a2f2f692e6779617a6f2e636f6d2f39616463653961663637373166343966366162353162393166353035613539372e706e67)

If you want to do it like this and don't want the source change (from below)  _or_  you don't have the source code of your game core, you can use a update query and copy the  **vnum**  to  **name**  just if the  **vnum**  from  **item_proto**  exists inside of  **mob_proto.drop_item**  by a specific mob.


```sql
UPDATE player.item_proto SET name = vnum
	WHERE vnum IN (SELECT drop_item FROM player.mob_proto WHERE drop_item >= 10);  
# Affected rows: 83 
# Time: 35.919ms
```
# How can i know where the items are dropped?
So, the structure of  _etc_drop_item.txt_  is based on dropping a item with a probability from a specific mob where that mob have the  _**item vnum**_  attached in column  _**mob_drop**_  ->  _**drop_item**_.
```sql
SELECT DISTINCT locale_name, vnum, drop_item FROM player.mob_proto where drop_item >= 10;
```
![enter image description here](https://i.gyazo.com/af1fce0d94e3f435e7acbbb9b574a2af.png)

# Metin2-One-Player-Per-Ip-In-Map

Instructions for implementation are explained in the .cpp files.

Example of usage:

```
when login with pc.is_pc_ip_in_map() begin
	chat("En este mapa solo puede entrar 1 personaje por IP, serás transportado en 5 segundos.")
	warp_to_village()
end
```

For add/remove maps, just edit:
```
		std::map<DWORD, std::map<DWORD, DWORD>> maps = {
			{ 181, {} },
			{ 182, {} },
			{ 183, {} }
		};
```
In map_manager.h



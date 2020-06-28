-- add to end:
		when 20358.chat."Auto Reward" with pc.get_gm_level()== 5  begin
			local s = select("Give Auto Reward", "Reload Reward List", "Close")
			if s == 1 then	
				oxevent.autoreward()
			elseif s == 2 then
				oxevent.reloadreward()
			end
        end
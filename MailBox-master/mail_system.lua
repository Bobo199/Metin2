quest mail_system begin
	state start begin
		when 20359.chat."Posta Kutusunu A� " begin
			pc.open_mailbox()
			setskin(NOWINDOW)
		end
	end
end
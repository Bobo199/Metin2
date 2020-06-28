quest mail_system begin
	state start begin
		when 20359.chat."Posta Kutusunu Aç " begin
			pc.open_mailbox()
			setskin(NOWINDOW)
		end
	end
end
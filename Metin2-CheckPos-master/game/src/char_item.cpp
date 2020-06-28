//Find
	
							case 50200:
								...
								...
								break;

///Change
	
							case 50200:
								LPSECTREE sectree = GetSectree();
								if (sectree) {
									CheckValidPos f(this, "shop", 200);
									sectree->ForEachAround(f);
									if(!GetCheckValidPos()) {
										ChatPacket(CHAT_TYPE_INFO, "You cannot open a shop here (too close to other shop).");
										return false;
									}
									if (!sectree->IsAttr(GetX(), GetY(), ATTR_BANPK)) {
										ChatPacket(CHAT_TYPE_INFO, "You cannot open a shop here (use safezone).");
										return false;
									}
									__OpenPrivateShop();
								}
								break;
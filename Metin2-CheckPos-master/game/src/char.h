///Add
#include "utils.h"

//Find 
		BYTE				m_bDropMetinStonePct;

///Add
	public:
		void			SetCheckValidPos(bool value) { m_bValidPos = value; }
		bool			GetCheckValidPos() { return m_bValidPos; }
		
		struct CheckValidPos {
			LPCHARACTER m_ch;
			std::string m_type;
			DWORD m_distance;
			CheckValidPos(LPCHARACTER ch, std::string type, DWORD distance) : m_ch(ch), m_type(type), m_distance(distance) {
				m_ch->SetCheckValidPos(true);
			}
			
			void operator()(LPENTITY ent) {
				if (!ent->IsType(ENTITY_CHARACTER)) return;
				LPCHARACTER ch = (LPCHARACTER) ent;
				if (ch == m_ch) return;
				if (m_type == "shop") {
					for (int i = 0; i <= 7; i++) {
						if (!ch->IsPC() && ch->GetRaceNum() != (30000 + i))
							return;
					}
				}
				else if (m_type == "npc") {
					std::list<DWORD> npc = {20094, 60003}; // change
					for (int n = 0; n <sizeof(npc)/sizeof(npc[0]); n++) {
						if (!ch->IsNPC() && ch->GetRaceNum() != npc[n])
							return;
					}
				}
				else if (m_type == "ch" && !ch->IsPC()) return;
				else {
					sys_err("Error in %s, type is not found!\n type:[%s]", __FUNCTION__, m_type);
					return;
				}
				
				if (DISTANCE_APPROX(ch->GetX() - m_ch->GetX(), ch->GetY() - m_ch->GetY()) < m_distance)
					m_ch->SetCheckValidPos(false);
		}};
	
	protected:
		bool			m_bValidPos;

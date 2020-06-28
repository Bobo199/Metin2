
//Search in class CFuncShoot:

				case SKILL_NOEJEON:
				case SKILL_GEOMPUNG:
				case SKILL_SANGONG:
				case SKILL_MAHWAN:
				case SKILL_PABEOB:
					//case SKILL_CURSE:
					{
						m_me->OnMove(true);
						pkVictim->OnMove();

//Add before:

				case SKILL_PAERYONG:

//Example after add this case:

				case SKILL_PAERYONG:
				case SKILL_NOEJEON:
				case SKILL_GEOMPUNG:
				case SKILL_SANGONG:
				case SKILL_MAHWAN:
				case SKILL_PABEOB:
					//case SKILL_CURSE:
					{
						m_me->OnMove(true);
						pkVictim->OnMove();


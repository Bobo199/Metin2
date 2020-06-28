///Add
#include <boost/algorithm/string.hpp>

//Find
		if (d->GetCharacter() && !strcmp(d->GetCharacter()->GetName(), m_name))
			return true;
		return false;
		
///Change
#if defined(FIXDESCFINDPC)
		return d->GetCharacter() && boost::algorithm::to_lower_copy(std::string(d->GetCharacter()->GetName())) == boost::algorithm::to_lower_copy(std::string(m_name));
#else
		if (d->GetCharacter() && !strcmp(d->GetCharacter()->GetName(), m_name))
			return true;
		return false;
#endif

or

///Change
#if defined(FIXDESCFINDPC)
		auto tolowerlocal = [](std::string sz) {
			std::transform(sz.begin(), sz.end(), sz.begin(), ::tolower);
			return sz;
		};
		return d->GetCharacter() && tolowerlocal(std::string(m_name)) == tolowerlocal(std::string(d->GetCharacter()->GetName()));
#else
		if (d->GetCharacter() && !strcmp(d->GetCharacter()->GetName(), m_name))
			return true;
		return false;
#endif

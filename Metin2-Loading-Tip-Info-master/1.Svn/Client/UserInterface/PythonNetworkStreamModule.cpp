///Add
#if defined(__LOADING_TIP__)
#include "LTiplist.h"
#include "PythonBackground.h"
PyObject* netGetTipInfo(PyObject* poSelf, PyObject* poArgs)
{
	auto Find("");
	const auto idx = CPythonBackground::Instance().GetWarpMapIndex();
	using namespace NS_TipList;

	if (!Tip_List.empty()) {
		const auto it = std::find_if(Tip_List.begin(), Tip_List.end(), [&idx](const decltype(Tip_List)::value_type& Tlist) {
			const auto& MapVec = std::get<MAP_VEC>(Tlist);
			return (std::find(MapVec.begin(), MapVec.end(), idx) != MapVec.end());
		});

		const auto& Tip_Tuple = (it != Tip_List.end()) ? *it : *Tip_List.begin();

		try {
			const auto& VnumVec = std::get<VNUM_VEC>(Tip_Tuple);
			const auto& idx = VnumVec.at(random_range(0, VnumVec.size() - 1));
			Find = CPythonNetworkStream::Instance().GetTipMap().at(idx).c_str();
		}
		catch (const std::out_of_range & ex) {
			TraceError("netGetTipInfo error:: %s", ex.what());
			TraceError("netGetTipInfo WarpMapIndex:: %ld", idx);
			TraceError("netGetTipInfo---> Find:%s ", std::get<NAMESTR>(Tip_Tuple));
		}
	}

	return Py_BuildValue("s", Find);
}
#endif

//Find
		{ "GetServerInfo",						netGetServerInfo,						METH_VARARGS },
		
///Add
#if defined(__LOADING_TIP__)
		{ "GetTipInfo",							netGetTipInfo,							METH_VARARGS },
#endif

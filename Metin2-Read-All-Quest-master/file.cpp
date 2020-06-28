#include <iostream>
#include <filesystem>
#include <sstream>
#include <unordered_set>
int main()
{
	const std::unordered_set<std::string> block{ "questlib.lua", "locale.lua", "GFquestlib.lua", "oxquiz.lua" };
	const auto& currentpath = std::filesystem::current_path();
	std::filesystem::remove_all(currentpath.string() + "\\object");
	for (const auto& cpath : std::filesystem::directory_iterator(currentpath)) {
		for (const std::string& find : { ".lua", ".quest" }) {
			const auto& strpath = cpath.path().string();
			const auto& pathlen = strpath.length();
			if (strpath.substr(pathlen - find.length(), pathlen) == find) {
				const auto& questname = strpath.substr(strpath.find_last_of('\\') + 1);
				if (!block.count(questname)) {
					std::stringstream ss;
					ss << "start qc.exe " << questname;
					system(ss.str().c_str());
				}
			}
		}
	}
	return 0;
}

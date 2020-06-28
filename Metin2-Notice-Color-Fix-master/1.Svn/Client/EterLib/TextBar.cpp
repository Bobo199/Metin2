//Find
void CTextBar::TextOut(int ix, int iy, const char * c_szText)
{
	...
}

///Change
#include <regex>
void CTextBar::TextOut(int ix, int iy, const char * c_szText)
{
	const auto x = std::regex_replace(c_szText, std::regex("\\|c[a-zA-Z0-9]+|\\|[r|R|H|h]"), "");
	c_szText = x.c_str();

	if (m_isBold) {
		SIZE size { 0,0 };
		GetTextExtent(c_szText, &size);
		ix = (500 - size.cx) / 2;
	}
	m_dib.TextOut(ix, iy, c_szText);
	Invalidate();
}

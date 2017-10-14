#include "LawyerAcademyCode.h"

// Initializing the map with academies codes and names
map<int,string> LawyerAcademyCode::ACADEMIES = LawyerAcademyCode::init_map();

LawyerAcademyCode::LawyerAcademyCode(const string& name, int id, int graduatedYear, int academyCode) throw(const char*)
	:lawyer(name,id,LawyerAcademyCode::ACADEMIES[academyCode], graduatedYear){}

bool LawyerAcademyCode::operator==(const LawyerAcademyCode& other) const
{
	return lawyer==other.lawyer;
}

// derivation interface
void LawyerAcademyCode::toOs( std::ostream& os) const
{
	os << lawyer;
}
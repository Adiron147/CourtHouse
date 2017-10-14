#ifndef __LAWYER_ACADEMY_CODE_H
#define __LAWYER_ACADEMY_CODE_H

#include "IPrintableLawyer.h"
#include "Lawyer.h"
#include <map>

// This class is a wrapper for Lawyer class, getting academy code number and translating it to academy name
class LawyerAcademyCode : public IPrintableLawyer
{
public:
	LawyerAcademyCode(const string& name, int id, int graduatedYear, int academyCode);
	bool operator==(const LawyerAcademyCode& other) const;
private:
	static map<int,string> ACADEMIES;
	Lawyer lawyer;

    void toOs( ostream& ) const override;

    static map<int,string> init_map() 
	{
        map<int,string> academiesMap;
        academiesMap[0] = "Yale";
		academiesMap[1] = "Harvard";
		academiesMap[99] = "Institute";
        return academiesMap;
    }
};

#endif __LAWYER_ACADEMY_CODE_H
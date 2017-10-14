#ifndef __I_PRINTABLE_LAWYER_H
#define __I_PRINTABLE_LAWYER_H

#include <ostream>
using namespace std;

class IPrintableLawyer
{
public:

	virtual ~IPrintableLawyer(){};

    friend ostream& operator<<( ostream& out, const IPrintableLawyer& printableLawyer )
    {
        printableLawyer.toOs( out );
        return out;
    }
private:

    /// derivation interface
    virtual void toOs( ostream& ) const =0;
};

#endif __I_PRINTABLE_LAWYER_H
#ifndef __IVISITOR_H
#define __IVISITOR_H

class IVisitable;

class IVisitor
{
public:
	virtual void visit(IVisitable* element) = 0;
};

#endif __IVISITOR_H
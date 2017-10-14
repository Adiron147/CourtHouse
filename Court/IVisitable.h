#ifndef __IVISITABLE_H
#define __IVISITABLE_H

class IVisitor;

class IVisitable
{
public:
	virtual void accept(IVisitor* visitor) = 0;
};

#endif __IVISITABLE_H
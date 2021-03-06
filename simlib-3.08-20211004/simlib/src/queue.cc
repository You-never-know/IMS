/////////////////////////////////////////////////////////////////////////////
//! \file queue.cc      Queue implementation (priority queue)
//
// Copyright (c) 1991-2004 Petr Peringer
//
// This library is licensed under GNU Library GPL. See the file COPYING.
//

//
//  implementation of queue
//

#include "simlib.h"
#include "internal.h"


////////////////////////////////////////////////////////////////////////////
//  implementation
//

namespace simlib3 {

SIMLIB_IMPLEMENTATION;


////////////////////////////////////////////////////////////////////////////
//  constructors
//
Queue::Queue()
{
  Dprintf(("Queue{%p}::Queue()", this));
}

Queue::Queue(const char *name)
{
  Dprintf(("Queue{%p}::Queue(\"%s\")", this, name));
  SetName(name);
}

////////////////////////////////////////////////////////////////////////////
//  destructor
//
Queue::~Queue() {
  Dprintf(("Queue{%p}::~Queue() // \"%s\" ", this, Name().c_str()));
}

////////////////////////////////////////////////////////////////////////////
// Insert --- priority insert into queue
//
void Queue::Insert(Entity *ent)
{
  Dprintf(("%s::Insert(%s)", Name().c_str(), ent->Name().c_str() ));
  Entity::Priority_t prio = ent->Priority;
  // find (higher priority is first)
#if 0 // _INS_FROM_BEGIN
  Queue::iterator p = begin();
  for( ; p!=end() && ((Entity*)(*p))->Priority >= prio; ++p);
#else
  // this is faster (items are inserted at end usually)
  Queue::iterator p = end();
  while(p!=begin()) {
        Queue::iterator q = p;
        --p;
        if( ((Entity*)(*p))->Priority >= prio ) { p = q; break; }
  }
#endif
  PredIns(ent,p); // works for end()
}

////////////////////////////////////////////////////////////////////////////
// InsFirst --- insert at first position (special case)
//
void Queue::InsFirst(Entity *ent)
{
  Dprintf(("%s::InsFirst(%s)", Name().c_str(), ent->Name().c_str() ));
  PredIns(ent,begin());
}

////////////////////////////////////////////////////////////////////////////
// InsLast --- insert at last position (for FIFO)
//
void Queue::InsLast(Entity *ent)
{
  Dprintf(("%s::InsLast(%s)", Name().c_str(), ent->Name().c_str() ));
  PredIns(ent,end());
}

////////////////////////////////////////////////////////////////////////////
// PostIns --- insert after entity
//
void Queue::PostIns(Entity *ent, iterator pos)
{
  Dprintf(("%s::PostIns(%s,pos)", Name().c_str(), ent->Name().c_str(), *pos ));
  if(pos==end())
     SIMLIB_internal_error(); // add error message
  PredIns(ent, ++pos);
}

////////////////////////////////////////////////////////////////////////////
// PredIns --- insert before entity
//
void Queue::PredIns(Entity *ent, iterator pos)
{
  Dprintf(("%s::PredIns(%s,pos:%p)", Name().c_str(), ent->Name().c_str(), *pos ));
  List::PredIns(ent, *pos); // insert before pos, can be end()
  ent->_MarkTime = Time;    // marks input time
  StatN(size());            // length statistic
}

////////////////////////////////////////////////////////////////////////////
// GetFirst --- remove first entity from queue
//
Entity *Queue::GetFirst()
{
  Dprintf(("%s::GetFirst()", Name().c_str()));
  Entity *ent = Get(begin());
  return ent;
}

////////////////////////////////////////////////////////////////////////////
// GetLast --- remove last entity from queue
//
Entity *Queue::GetLast()
{
  Dprintf(("%s::GetLast()", Name().c_str()));
  Entity *ent = Get(--end());
  return ent;
}

////////////////////////////////////////////////////////////////////////////
// Get --- remove item
//
Entity *Queue::Get(iterator pos)
{
  Dprintf(("%s::Get(pos:%p)", Name().c_str(), *pos));
  Entity *ent = static_cast<Entity*>(List::Get(*pos));
  StatDT(Time - ent->_MarkTime);
  StatN(size());  StatN.n--; // the number of samples correction
  return ent;
}

////////////////////////////////////////////////////////////////////////////
//  clear - initialization of list
//
void Queue::clear()
{
  Dprintf(("%s::Clear()", Name().c_str()));
  StatN.Clear();
  StatDT.Clear();
  List::clear(); // problem with WARNING
  StatN.Clear();
  StatDT.Clear();
}

#if 0
////////////////////////////////////////////////////////////////////////////
//  Process::Name --- name of the process
//
const char *Queue::Name() const
{
    const char *name = SimObject::Name();
    if(*name) return name; // has explicit name
    else      return SIMLIB_create_tmp_name("Queue{%p}", this);
}
#endif

}
// end


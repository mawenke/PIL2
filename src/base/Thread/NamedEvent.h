
#ifndef Foundation_NamedEvent_INCLUDED
#define Foundation_NamedEvent_INCLUDED

#include "../Environment.h"


#if defined(PIL_OS_FAMILY_WINDOWS) && defined(PIL_WIN32_UTF8)
//#include "NamedEvent_WIN32U.h"
#elif defined(PIL_OS_FAMILY_WINDOWS)
#include "NamedEvent_WIN32.h"
#elif defined(PIL_ANDROID)
#include "NamedEvent_Android.h"
#elif defined(PIL_OS_FAMILY_UNIX)
#include "NamedEvent_UNIX.h"
#else
#include "NamedEvent_VMS.h"
#endif


namespace pi {


class PIL_API NamedEvent: public NamedEventImpl
	/// An NamedEvent is a global synchronization object 
	/// that allows one process or thread to signal an
	/// other process or thread that a certain event
	/// has happened.
	///
	/// Unlike an Event, which itself is the unit of synchronization,
	/// a NamedEvent refers to a named operating system resource being the
	/// unit of synchronization.
	/// In other words, there can be multiple instances of NamedEvent referring
	/// to the same actual synchronization object.
	///
	/// NamedEvents are always autoresetting.
	///
	/// There should not be more than one instance of NamedEvent for
	/// a given name in a process. Otherwise, the instances may
	/// interfere with each other.
{
public:
	NamedEvent(const std::string& name);
		/// Creates the event.
		
	~NamedEvent();
		/// Destroys the event.

	void set();
		/// Signals the event. 
		/// The one thread or process waiting for the event 
		/// can resume execution.

	void wait();
		/// Waits for the event to become signalled.

private:
	NamedEvent();
	NamedEvent(const NamedEvent&);
	NamedEvent& operator = (const NamedEvent&);
};


//
// inlines
//
inline void NamedEvent::set()
{
	setImpl();
}


inline void NamedEvent::wait()
{
	waitImpl();
}


} // namespace pi


#endif // Foundation_NamedEvent_INCLUDED

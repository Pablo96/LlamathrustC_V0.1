/**
 * @file thread.h
 * @author Pablo Narvaja
 * @brief Here is everything related to threading
 **/
#pragma once
#include <Common.h>

#define MAX_RESERVED_SIZE 8 * 2

#ifdef LT_DEBUG
#define ASSERT_RESERVED_SIZE(size) \
if (size > MAX_RESERVED_SIZE) {\
log_fatal("Size of platform object(%u) is greater than MAX_SIZE(%u)", size, MAX_RESERVED_SIZE);\
exit(36);}
#else
#define ASSERT_RESERVED_SIZE(size)
#endif


typedef uint64 (*ThreadFuncWrapper)(void* name);

/**
 * @struct Thread
 * @brief represents a thread within the engine.
 * @note Called by the platform layer only!!
 * @field reserved:
 *	@type byte pointer
 *	@brief reserved for platform representation.
 * @field name:
 *	@type const char pointer
 *	@brief OPTIONAL: name for the thread.
 * @field ID
 *  @type const uint64
 *  @brief the ID of this thread.
 * @field reservedSize
 *  @type const uint64
 *  @brief the size used by the platform representation
 **/
typedef struct _Thread {
    byte reserved[MAX_RESERVED_SIZE];
    const char* name;
    const uint64 ID;
    const uint16 reservedSize;
} Thread;


/**
 * @func ConstructThread
 * @brief Create a new thread on the heap.
 * @param platformObj:
 *	@type const void pointer
 *	@brief the pointer to the thread object must not be null
 *  @note data will be copied to the thread obj.
 * @param size:
 *	@type const uint16
 *	@brief size of the platform obj.
 * @param name
 *  @brief OPTIONAL: name of the thread.
 * @return Thread pointer
 *  @brief pointer to the created thread obj.
 **/
extern Thread* ConstructThread(const void* platformObj, const uint16 size, const char* name);

/**
 * @func LT_Thread_Create
 * @brief this function does this thing.
 * @note the thread is created and suspended.
 * @param func:
 *	@type ThreadFuncWrapper
 *	@brief function to execute on the thread.
 * @param name
 *  @brief OPTIONAL: name of the thread.
 * @return Thread pointer
 *  @brief reference to the thread created.
 **/
extern Thread* LT_Thread_Create(ThreadFuncWrapper func, const char* name);

/**
 * @func LT_Thread_Join
 * @brief waits for a thread to finish.
 * @param thread:
 *	@type const Thread pointer
 *	@brief the thread to wait for.
 * @return void
 **/
extern void LT_Thread_Join(const Thread* thread);

/**
 * @func LT_Thread_Sleep
 * @brief Sleep the thread the specified ammount of time.
 * @note if miliseconds is 0 then it dont go to sleep at all.
 * @param thread:
 *	@type const Thread pointer
 *	@brief the thread to put to sleep.
 * @param millisecons:
 *	@type uint64
 *	@brief the amount of millisecond to wait.
 * @return void
 **/
extern void LT_Thread_Sleep(const Thread* thread, const uint64 miliseconds);

/*
 * taintgrind.h
 *
 *  Created on: Jun 12, 2012
 *      Author: khilan
 */

#ifndef TAINTGRIND_H_
#define TAINTGRIND_H_

#include "valgrind.h"
#include <sys/syscall.h>

typedef enum {
	VG_USERREQ__TAINTGRIND_CREATE_SANDBOX,
	VG_USERREQ__TAINTGRIND_ENTER_PERSISTENT_SANDBOX,
	VG_USERREQ__TAINTGRIND_EXIT_PERSISTENT_SANDBOX,
	VG_USERREQ__TAINTGRIND_ENTER_EPHEMERAL_SANDBOX,
	VG_USERREQ__TAINTGRIND_EXIT_EPHEMERAL_SANDBOX,
	VG_USERREQ__TAINTGRIND_SHARED_FD,
	VG_USERREQ__TAINTGRIND_SHARED_VAR,
	VG_USERREQ__TAINTGRIND_UPDATE_SHARED_VAR,
	VG_USERREQ__TAINTGRIND_ALLOW_SYSCALL,
	VG_USERREQ__TAINTGRIND_ENTER_CALLGATE,
	VG_USERREQ__TAINTGRIND_EXIT_CALLGATE,
	VG_USERREQ__TAINTGRIND_TAINT,
	VG_USERREQ__TAINTGRIND_TAINT_NAMED,
	VG_USERREQ__TAINTGRIND_UNTAINT,
	VG_USERREQ__TAINTGRIND_IS_TAINTED,
	VG_USERREQ__TAINTGRIND_START_PRINT,
	VG_USERREQ__TAINTGRIND_STOP_PRINT
} Vg_TaintGrindClientRequest;

#define TNT_CREATE_SANDBOX() \
		VALGRIND_DO_CLIENT_REQUEST_STMT(VG_USERREQ__TAINTGRIND_CREATE_SANDBOX, 0, 0, 0, 0, 0)

#define TNT_ENTER_PERSISTENT_SANDBOX() \
		VALGRIND_DO_CLIENT_REQUEST_STMT(VG_USERREQ__TAINTGRIND_ENTER_PERSISTENT_SANDBOX, 0, 0, 0, 0, 0)

#define TNT_EXIT_PERSISTENT_SANDBOX() \
		VALGRIND_DO_CLIENT_REQUEST_STMT(VG_USERREQ__TAINTGRIND_EXIT_PERSISTENT_SANDBOX, 0, 0, 0, 0, 0)

#define TNT_ENTER_EPHEMERAL_SANDBOX() \
		VALGRIND_DO_CLIENT_REQUEST_STMT(VG_USERREQ__TAINTGRIND_ENTER_EPHEMERAL_SANDBOX, 0, 0, 0, 0, 0)

#define TNT_EXIT_EPHEMERAL_SANDBOX() \
		VALGRIND_DO_CLIENT_REQUEST_STMT(VG_USERREQ__TAINTGRIND_EXIT_EPHEMERAL_SANDBOX, 0, 0, 0, 0, 0)

#define TNT_SHARED_FD(fd,perm) \
		VALGRIND_DO_CLIENT_REQUEST_STMT(VG_USERREQ__TAINTGRIND_SHARED_FD, fd, perm, 0, 0, 0)

#define TNT_SHARED_VAR(var,perm) \
		VALGRIND_DO_CLIENT_REQUEST_STMT(VG_USERREQ__TAINTGRIND_SHARED_VAR, var, perm, 0, 0, 0)

#define TNT_ENTER_CALLGATE() \
		VALGRIND_DO_CLIENT_REQUEST_STMT(VG_USERREQ__TAINTGRIND_ENTER_CALLGATE, 0, 0, 0, 0, 0)

#define TNT_EXIT_CALLGATE() \
		VALGRIND_DO_CLIENT_REQUEST_STMT(VG_USERREQ__TAINTGRIND_EXIT_CALLGATE, 0, 0, 0, 0, 0)

#define TNT_UPDATE_SHARED_VAR(var,value) \
	{ \
		VALGRIND_DO_CLIENT_REQUEST_STMT(VG_USERREQ__TAINTGRIND_UPDATE_SHARED_VAR,#var,0,0,0,0); \
		var = value; \
	}

#define TNT_ALLOW_SYSCALL(syscallno) \
		VALGRIND_DO_CLIENT_REQUEST_STMT(VG_USERREQ__TAINTGRIND_ALLOWSYSCALL,syscallno,0,0,0,0);

// Tainting/Untainting memory
#define TNT_TAINT(addr, size) \
		VALGRIND_DO_CLIENT_REQUEST_STMT(VG_USERREQ__TAINTGRIND_TAINT,addr,size,0,0,0);

#define TNT_TAINT_NAMED(addr, size, varname) \
		VALGRIND_DO_CLIENT_REQUEST_STMT(VG_USERREQ__TAINTGRIND_TAINT_NAMED,addr,size,varname,0,0);

#define TNT_UNTAINT(addr, size) \
		VALGRIND_DO_CLIENT_REQUEST_STMT(VG_USERREQ__TAINTGRIND_UNTAINT,addr,size,0,0,0);

#define TNT_IS_TAINTED(is_tainted, addr, size) \
		VALGRIND_DO_CLIENT_REQUEST(is_tainted, 0, VG_USERREQ__TAINTGRIND_IS_TAINTED,addr,size,0,0,0);

// Start/Stop printing output
#define TNT_START_PRINT() \
		VALGRIND_DO_CLIENT_REQUEST_STMT(VG_USERREQ__TAINTGRIND_START_PRINT, 0, 0, 0, 0, 0)

#define TNT_STOP_PRINT() \
		VALGRIND_DO_CLIENT_REQUEST_STMT(VG_USERREQ__TAINTGRIND_STOP_PRINT, 0, 0, 0, 0, 0)

#endif /* TAINTGRIND_H_ */

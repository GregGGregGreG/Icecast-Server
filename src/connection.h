#ifndef __CONNECTION_H__
#define __CONNECTION_H__

#include <sys/types.h>
#include "compat.h"

typedef struct connection_tag
{
	unsigned long id;

	time_t con_time;
	uint64_t sent_bytes;

	int sock;
	int error;

	char *ip;
	char *host;
} connection_t;

void connection_initialize(void);
void connection_shutdown(void);
void connection_accept_loop(void);
void connection_close(connection_t *con);

#endif  /* __CONNECTION_H__ */
/* format.h
**
** format plugin header
**
*/
#ifndef __FORMAT_H__
#define __FORMAT_H__

typedef enum _format_type_tag
{
	FORMAT_TYPE_VORBIS,
	FORMAT_TYPE_MP3
} format_type_t;

typedef struct _format_plugin_tag
{
	format_type_t type;

	/* set this is the data format has a header that
	** we must send before regular data
	*/
	int has_predata;

	refbuf_t *(*get_buffer)(struct _format_plugin_tag *self, char *data, unsigned long len);
	refbuf_queue_t *(*get_predata)(struct _format_plugin_tag *self);

	/* for internal state management */
	void *_state;
} format_plugin_t;

format_plugin_t *format_get_plugin(format_type_t type);

#endif  /* __FORMAT_H__ */







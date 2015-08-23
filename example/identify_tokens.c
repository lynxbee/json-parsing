#include <stdio.h>
#include <string.h>
#include "../jsmn.h"

/*
 * This example shows how many tokes are there in json and how they
 * get parsed, we can use this as reference to parse big jsons, 
 * where we need to track i, i.e. counter for parsing.
 */

const char *JSON_STRING =
	"{\"user\": \"johndoe\", \"admin\": false, \"uid\": 1000,\n  "
	"\"groups\": [\"users\", \"wheel\", \"audio\", \"video\"]}";

static int jsoneq(const char *json, jsmntok_t *tok, const char *s) {
	if (tok->type == JSMN_STRING && (int) strlen(s) == tok->end - tok->start &&
			strncmp(json + tok->start, s, tok->end - tok->start) == 0) {
		return 0;
	}
	return -1;
}

int main() {
	int i;
	int r;
	jsmn_parser p;
	jsmntok_t t[128]; /* We expect no more than 128 tokens */

	jsmn_init(&p);
	r = jsmn_parse(&p, JSON_STRING, strlen(JSON_STRING), t, sizeof(t)/sizeof(t[0]));
	if (r < 0) {
		printf("Failed to parse JSON: %d\n", r);
		return 1;
	}

	printf("---------------------------------------------------------\n");
	printf("actual json to parse :\n");
	printf("%s\n", JSON_STRING);
	printf("---------------------------------------------------------\n");
	/* A non-negative return value of jsmn_parse is
		 the number of tokens actually used by the parser. */
	printf("here jsmn_parse actually parsed %d tokens\n", r);

	printf("tokens are as below:\n\n");

	for (i=0; i < r; i++) {
		switch(t[i].type) {
			case JSMN_PRIMITIVE:
				printf("%d: type : JSMN_PRIMITIVE, child tokens(size): %d ", i, t[i].size); break;
			case JSMN_OBJECT:
				printf("%d: type : JSMN_OBJECT, child tokens(size): %d ", i, t[i].size ); break;
			case JSMN_ARRAY:
				printf("%d: type : JSMN_ARRAY, child tokens(size): %d ", i, t[i].size); break;
			case JSMN_STRING:
				printf("%d: type : JSMN_STRING, child tokens(size): %d ", i, t[i].size); break;
		}
		printf("token : %s\n\n",strndup(JSON_STRING + t[i].start, t[i].end-t[i].start));
	}

	return 0;
}

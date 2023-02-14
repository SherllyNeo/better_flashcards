#define _XOPEN_SOURCE 700
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include "time_strings.h"
#include <json-c/json.h>

#define MAX_SIZE 1000



struct flashcard {
  char prompt[MAX_SIZE];
  char answer[MAX_SIZE];
  time_t lastseen;
  int delay;
};

struct flashcard string_to_flashcard(char* flashcard_string) {
	//get values from json
	struct json_object *parsed_json;
	struct json_object *prompt_j;
	struct json_object *answer_j;
	struct json_object *lastseen_j;
	struct json_object *delay_j;
	parsed_json = json_tokener_parse(flashcard_string);
	json_object_object_get_ex(parsed_json,"prompt",&prompt_j);
	json_object_object_get_ex(parsed_json,"answer",&answer_j);
	json_object_object_get_ex(parsed_json,"date-last-seen",&lastseen_j);
	json_object_object_get_ex(parsed_json,"delay",&delay_j);



	//parse datetime
	char dt_string[MAX_SIZE];
	strcpy(dt_string,json_object_get_string(lastseen_j));
	struct tm date = {};
	strptime(dt_string, "%Y-%m-%d", &date);
	time_t t = mktime(&date);

	char dt[20];
	struct tm * timeinfo3;
	timeinfo3 = localtime (&t);
	strftime(dt, sizeof(dt), "%Y-%m-%d %H:%M", timeinfo3);



	//fill struct
	struct flashcard new_flashcard;
	strcpy(new_flashcard.prompt,json_object_get_string(prompt_j));
	strcpy(new_flashcard.answer,json_object_get_string(answer_j));
	new_flashcard.lastseen = t;
	new_flashcard.delay = json_object_get_int(delay_j);;
 	json_object_put(parsed_json);
// 	json_object_put(prompt_j);
// 	json_object_put(answer_j);
// 	json_object_put(lastseen_j);
// 	json_object_put(delay_j);
	return new_flashcard;


}

char* flashcard_to_string(struct flashcard  flash_card ) {
	char *buf;
	size_t sz;
	//time to string
	time_t time = flash_card.lastseen;
	struct tm *tm = localtime(&time);
	static char time_string[50];
	strftime(time_string, 50, "%Y-%m-%d", tm);

	sz = snprintf(NULL, 0,"{\"prompt\":\"%s\",\"answer\":\"%s\",\"date-last-seen\":\"%s\",\"delay\":\"%d\"}",flash_card.prompt,flash_card.answer,time_string,flash_card.delay);


	buf = (char *)malloc(sz + 3);
	snprintf(buf, sz+1, "{\"prompt\":\"%s\",\"answer\":\"%s\",\"date-last-seen\":\"%s\",\"delay\":\"%d\"}",flash_card.prompt,flash_card.answer,time_string,flash_card.delay);

	return buf;



 }

